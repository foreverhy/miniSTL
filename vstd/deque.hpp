#ifndef VERIHY_VSTD_DEQUE_HPP
#define VERIHY_VSTD_DEQUE_HPP

#include <memory>

namespace verihy{

namespace vstd{

namespace {

template<typename T>
struct block{
    static const std::size_t default_size = 24;
    std::size_t capacity = default_size;
    T *data = nullptr;
    T *end = nullptr;
    T *first = nullptr;
    T *tail = nullptr;

    block(bool front = false): capacity(default_size), data(deque<T>::alloc.allocate(default_size)),
            end(data + capacity), first(front?(data+capacity):data),
            tail(front?(data+capacity):data){}
    ~block(){
        for (auto p = first; p < tail; ++p){
            deque<T>::alloc.destroy(p);
        }
        deque<T>::alloc.deallocate(data, capacity);
    }

    T& operator[](std::size_t idx){
        return *(first + idx);
    }

    bool push_back(const T &rhs) {
        if (tail >= end){
            return false;
        }
        deque<T>::alloc.construct(tail, rhs);
        ++tail;
        return true;
    }
    bool push_front(const T &rhs) {
        if (first <= data){
            return false;
        }
        deque<T>::alloc.construct(first - 1, rhs);
        --first;
        return true;
    }
    bool pop_back() {
        if (first >= tail){
            return false;
        }
        deque<T>::alloc.destroy(tail - 1);
        --tail;
        return true;
    }
    bool pop_front() {
        if (first >= tail){
            return false;
        }
        deque<T>::alloc.destroy(first);
        ++first;
        return true;
    }
};



template<typename T>
struct map{
    typedef block<T>* pointer;

    pointer *data = nullptr;
    pointer *end = nullptr;
    pointer *first = nullptr;
    pointer *last = nullptr;

    std::size_t size = 0;
    static const std::size_t space = 24;

    map(): data(new pointer[2 * space](nullptr)), end(data + 2 * space), first(data + space),
            last(first){};
    ~map(){
        for (auto p = data; p < end; ++p){
            delete *p;
        }
        delete[] data;
    }

    block<T>& operator[](std::size_t idx){
        return **(first + idx);
    }

    void grow(){
        auto data_new = new pointer[space * 2 + size];
        for (int i = space, j = 0; j < size; ++i, ++j){
            data_new[i] = *(first + j);
        }
        delete[] data;
        data = data_new;
        first = data + space;
        last = first + size - 1;
        end = data + space * 2 + size;
    }

    pointer push_back(){
        if (last + 1 >= end){
            grow();
        }
        if (nullptr == ++last){
            *last = new block();
        }
        return *last;
    }

    pointer push_front(){
        if (first <= data){
            grow();
        }
        if (nullptr == --first){
            *first = new block();
        }
        return *first;
    }

    void pop_back(){
        if (first < last){
            --last;
        }
    }

    void pop_front(){
        if (first < last){
            ++first;
        }
    }

};

}

template<typename T, typename Allocator = std::allocator<T> >
class deque{
  private:
    static Allocator alloc;
    map<T> mp;
  public:
    friend class block;
    friend class map;

    deque(){

    }
    ~deque(){

    }
};


} // namespace vstd

} // namespace verihy

#endif // VERIHY_VSTD_DEQUE_HPP
