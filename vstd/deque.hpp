#ifndef VERIHY_VSTD_DEQUE_HPP
#define VERIHY_VSTD_DEQUE_HPP

#include <memory>

namespace verihy{

namespace vstd{

template<typename T, typename Allocator = std::allocator<T> >
class deque{
  public:
    //friend struct block<T>;
    //friend struct map<T>;

    typedef T value_type;
    typedef Allocator allocator_type;
    typedef std::size_t size_type;
    typedef std::ptrdiff_t difference_type;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef typename std::allocator_traits<Allocator>::pointer pointer;
    typedef typename std::allocator_traits<Allocator>::const_pointer const_pointer;
    class iterator;


    deque(){
    }

    ~deque(){
    }

    reference operator[](size_type pos){
        return mp.get_value(pos);
    }

    void push_back(const value_type &rhs){
        mp.pb_value(rhs);
    }

  private:

    struct block{
        static const std::size_t default_size = 24;
        std::size_t capacity = default_size;
        T *data = nullptr;
        T *end = nullptr;
        T *first = nullptr;
        T *tail = nullptr;
        block(bool front = false): capacity(default_size), data(deque::alloc.allocate(default_size)),
                end(data + capacity), first(front?(data+capacity):data),
                tail(front?(data+capacity):data){}
        ~block(){
            for (auto p = first; p < tail; ++p){
                deque::alloc.destroy(p);
            }
            deque::alloc.deallocate(data, capacity);
        }
        T& operator[](std::size_t idx){
            return *(first + idx);
        }

        bool push_back(const T &rhs) {
            if (tail >= end){
                return false;
            }
            deque::alloc.construct(tail, rhs);
            ++tail;
            return true;
        }
        bool push_front(const T &rhs) {
            if (first <= data){
                return false;
            }
            deque::alloc.construct(first - 1, rhs);
            --first;
            return true;
        }
        bool pop_back() {
            if (first >= tail){
                return false;
            }
            deque::alloc.destroy(tail - 1);
            --tail;
            return true;
        }
        bool pop_front() {
            if (first >= tail){
                return false;
            }
            deque::alloc.destroy(first);
            ++first;
            return true;
        }

    };
    struct map{
        typedef block* pointer;

        pointer *data = nullptr;
        pointer *end = nullptr;
        pointer *first = nullptr;
        pointer *last = nullptr;

        static const std::size_t space = 24;

        map(): data(new pointer[2 * space]), end(data + 2 * space), first(data + space),
                last(first){
                    std::fill(data, data + 2 * space, nullptr); 
                };
        ~map(){
            for (auto p = data; p < end; ++p){
                delete *p;
            }
            delete[] data;
        }

        T& get_value(std::size_t pos){
            std::size_t fsz = (*first)->tail - (*first)->first;
            if (pos <= fsz){
                return first[0][pos];
            }
            return first[(pos - fsz) / block::default_size + 1][(pos - fsz) % block::default_size];
        }

        void grow(){
            int sz = last - first + 1;
            auto data_new = new pointer[space * 2 + sz];
            for (auto p1 = data_new + space, p2 = first; p2 <= last; ++p1, ++p2){
                *p1 = *p2;
            }
            for (auto p = data; p < first; ++p){
                delete *p;
            }
            for (auto p = last + 1; p < end; ++p){
                delete *p;
            }
            delete[] data;
            data = data_new;
            first = data + space;
            last = first + sz - 1;
            end = data + space * 2 + sz;
        }

        pointer push_back(){
            if (last + 1 >= end){
                grow();
            }
            //if (nullptr == *(++last)){
                //*last = new block();
            //}
            return *(++last);
        }

        pointer push_front(){
            if (first <= data){
                grow();
            }
            //if (nullptr == *(--first)){
                //*first = new block(true);
            //}
            return *(--first);
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

        void pb_value(const value_type &rhs){
            if (!*last){
                *last = new block();
            }
            if ( (*last)->push_back(rhs)){
                return;
            }
            push_back();
            //if (!*last){
                //*last = new block();
            //}
            //(*last)->push_back(rhs);
            pb_value(rhs);
            //(*last)->push_back(rhs);
        }

    };

    static allocator_type alloc;
    map mp;

};


template<typename T, typename Allocator>
typename deque<T, Allocator>::allocator_type deque<T, Allocator>::alloc;

} // namespace vstd

} // namespace verihy

#endif // VERIHY_VSTD_DEQUE_HPP
