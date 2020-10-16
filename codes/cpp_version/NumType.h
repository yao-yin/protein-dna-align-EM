#ifndef NUMTYPE_H
#define NUMTYPE_H
#include <numeric>
#include <math.h>
#include <algorithm>
#include <vector>

typedef double NumType; // To represent Probability numerically;
typedef double LogNumType;
template <typename Iter>
typename std::iterator_traits<Iter>::value_type
_log_sum_exp(Iter begin, Iter end);
template <typename Iter>
typename std::iterator_traits<Iter>::value_type
log_sum_exp(Iter begin, Iter end);
LogNumType LogSumExp(const LogNumType & a, const LogNumType & b);
LogNumType LogSumExp(const LogNumType & a, const LogNumType & b, const LogNumType & c);
LogNumType LogSumExp(const LogNumType & a, const LogNumType & b, const LogNumType & c, const LogNumType & d);
LogNumType LogSumExp(const LogNumType & a, const LogNumType & b, const LogNumType & c, const LogNumType & d, const LogNumType & e,const LogNumType & f, const LogNumType & g);
LogNumType Log1m(const LogNumType & a);

inline LogNumType LogSumExp(const LogNumType & a, const LogNumType & b) {
    LogNumType max_elem = a > b ? a : b;
    return max_elem == log(0.0) ? max_elem : max_elem + log(exp(a-max_elem) + exp(b-max_elem));  
}

inline LogNumType Log1m(const LogNumType & x) {
    return log(1.0-exp(x));
    /*if (x < -log(2.0)) {
      return log1p(-exp(x));
    }
    else return log(-expm1(x));*/
}

#endif