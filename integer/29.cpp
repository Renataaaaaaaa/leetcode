#include <vector>
#include <iostream>
using namespace std;

//-2^31 变成正数越界了，所以要都变成负数
//-2^31 / -1 = 2^31 越界，要特殊处理

int divideHelp(int dividend, int divisor){
    int result = 0;
    
    while(dividend <= divisor){ //be negative
        int quotient = 1;
        int divisor_cur = divisor;
        while(divisor_cur >= 0xc0000000 && dividend <= (divisor_cur * 2)){ //-2147483648 / 2
            divisor_cur = divisor_cur * 2;
            quotient += quotient;
        }
        result += quotient;
        dividend = dividend - divisor_cur;
    }
    return result;
}
int divide(int dividend, int divisor) {
    int coeff = 2;
    if (dividend == INT32_MIN){
        if (divisor == 1){
            return INT32_MIN;
        }
        if (divisor == -1){
            return INT32_MAX;
        }
    }
    if (dividend > 0){
        coeff--;
        dividend = 0 - dividend;
    }
    if (divisor > 0){
        divisor = 0 - divisor;
        coeff--;
    }
    int quotient = divideHelp(dividend, divisor);
    return (coeff == 1) ? (-quotient) : quotient;
}

int main(){
    int divident = -2147483648;
    int divisor = 1;
    cout << divide(divident, divisor) << endl;
}

