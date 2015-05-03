#include "deque.hpp"
#include <iostream>
#include <algorithm>
using std::cout;
using std::endl;


int main(){
    using verihy::vstd::deque;
    deque<int> dq;
    for(int i = 0; i< 10000; ++i){
        dq.push_back(i);
    }
    dq[2];
    //for(int i = 0; i< 100; ++i){
        //cout << a[i] << endl;
    //}

    //std::sort(a.begin(), a.end());
    //for(int i = 0; i< 100; ++i){
        //cout << a[i] << endl;
    //}
    //auto c = a.begin() + 33;
    //cout << c << endl;

    return 0;
}
