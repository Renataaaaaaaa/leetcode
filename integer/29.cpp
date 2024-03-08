#include <vector>
#include <iostream>
using namespace std;

int divide(int dividend, int divisor) {
    int coeff = -1;
    if (divisor == -1 && dividend == INT32_MIN){
        return INT32_MAX;
    }
    if (dividend > 0 && divisor > 0){
        dividend = 0 - dividend;
        divisor = 0 - divisor;
    }else if (dividend <= 0 && divisor > 0)
    {
        coeff = 1;
        divisor = 0 - divisor;
    }else if (divisor <= 0 && dividend > 0){
        dividend = 0 - dividend;
        coeff = 1;
    }
    
    int quotient = 0;
    while(dividend <= divisor){
        int divident_tmp = dividend;
        int divisor_tmp = divisor;
        int quotient_tmp = -1;

        while (true){
            divident_tmp = dividend - divisor_tmp;
            if (divisor_tmp < (INT32_MIN >> 2)){
                break;
            }
            divisor_tmp = divisor_tmp + divisor_tmp;
            if (divident_tmp > divisor_tmp){
                break;
            }
            quotient_tmp = quotient_tmp + quotient_tmp;
        }
        dividend = divident_tmp;
        quotient = quotient + quotient_tmp;
    }
    return quotient * coeff;
}