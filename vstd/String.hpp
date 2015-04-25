#ifndef VERIHY_VSTD_STRING_HPP
#define VERIHY_VSTD_STRING_HPP

#include <cstdint>
#include <memory>
#include <cstring>
#include <iostream>

namespace verihy{

namespace vstd{

class String{
  public:
    typedef std::uint32_t size_type;
    typedef char value_type;
    typedef std::allocator<char> allocator_type;
    typedef char& reference;
    typedef char* pointer;
    //class iterator;

    String():data_(new char[1]), size_(1){
        data_[0] = '\0'; 
    }
    String(const char *data):data_(new char[strlen(data) + 1]), size_(strlen(data)){
        std::memcpy(data_, data, size_); 
        data_[size_] = '\0';
    } 
    String(const String &rhs):data_(new char[rhs.size() + 1]), size_(rhs.size()){
        std::memcpy(data_, rhs.data_, size_);
        data_[size_] = '\0';
    }
    String(String &&rhs):data_(rhs.data_), size_(rhs.size_){
        rhs.data_ = nullptr;
        rhs.size_ = 0;
    }

    ~String(){
        delete[] data_;
    }

    void swap(String &rhs){
        if (&rhs == this){
            return;
        }
        std::swap(data_, rhs.data_);
        std::swap(size_, rhs.size_);
    }

    String& operator=(const String &rhs){
        if(this == &rhs){
            return *this;
        }
        String tmp(rhs);
        swap(tmp);
        return *this;
    }

    String& operator=(String &&rhs){
        if(this == &rhs){
            return *this;
        }
        delete[] data_;
        data_ = rhs.data_;
        size_ = rhs.size_;
        rhs.data_ = nullptr;
        rhs.size_ = 0;
        return *this;
    }

    const char* data() const{
        return data_;
    }

    size_type size() const {
        return size_;
    }

    bool empty(){
        return 0 == size_;
    }


    bool operator==(const String &rhs)const{
        return !std::strcmp(data_, rhs.data());
    }

  private:
    char* data_;
    size_type size_;
    // This code is for interview only, so we're not going to use
    //  allocator; 
    //size_type capacity_;
    //static allocator_type alloc_;
    //static const size_type growsize_ = 24;


};

std::ostream& operator<<(std::ostream &os, const String &rhs){
    os << rhs.data();
    return os;
}

}// namespace verihy::vstd

}// namespace verihy

#endif
