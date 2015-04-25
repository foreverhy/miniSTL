#ifndef VERIHY_VSTD_ALGORITHM_ALGORHITHM_ITER
#define VERIHY_VSTD_ALGORITHM_ALGORHITHM_ITER 1

#include <algorithm>

namespace verihy{

namespace vstd{


//TODO
// use own vstd::less and vstd::swap
template<typename RAIter, typename Comp = std::less<typename std::iterator_traits<RAIter>::value_type> >
void next_permutaion(RAIter first, RAIter end, Comp cmp = Comp()){
    auto p = end - 1;
    if(first == end || first == p){
        return;
    }
    for(; p > first; --p){
        if(cmp(*(p - 1), *p))break;
    }
    if(p > first){
        auto q = p - 1;
        auto e = end - 1;
        for(; e > q; --e){
            if(cmp(*q, *e))break;
        }
        std::swap(*q, *e);
    }

    for(auto q = end - 1; p < q; ++p, --q){
        std::swap(*p, *q);
    }

}// function next_permutation

}// namespace vstd

}// namespace verihy





#endif
