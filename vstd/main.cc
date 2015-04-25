#include "Vector.hpp"
#include <iostream>
#include <algorithm>
using std::cout;
using std::endl;


int main(){
    using verihy::vstd::Vector;
    Vector<int> a;
    for(int i = 0; i< 100; ++i){
        a.push_back(100-i);
    }
    //for(int i = 0; i< 100; ++i){
        //cout << a[i] << endl;
    //}

    std::sort(a.begin(), a.end());
    for(int i = 0; i< 100; ++i){
        cout << a[i] << endl;
    }
    auto c = a.begin() + 33;
    cout << c << endl;

    return 0;
}
