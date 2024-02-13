#include "trig.h"
#include "math.h"









/*
sin(x) = x - (x^3)/(3!) + (x^5)/(5!) - (x^7)/(7!)
for four terms

*/
int32_t taylor_series_sin(int32_t x) {
	int32_t term1 = x;
	int32_t term2 = ipow(x, 3) / (int32_t) factorial(3);
	int32_t term3 = ipow(x, 5) / (int32_t) factorial(5);
		int32_t term4 = ipow(x, 7) / (int32_t) factorial(7);
	return term1 - term2 + term3 - term4;

}



// Function to find factorial of given number
// modified from: https://www.geeksforgeeks.org/c-program-for-factorial-of-a-number/
uint32_t factorial(uint32_t n)
{
    uint32_t result = 1, i;
 
    // loop from 2 to n to get the factorial
    for (i = 2; i <= n; i++) {
        result *= i;
    }
 
    return result;
}


// modified from: https://stackoverflow.com/questions/101439/the-most-efficient-way-to-implement-an-integer-based-power-function-powint-int

int32_t ipow(uint32_t base, int32_t exp)
{
    int32_t result = 1;
    for (;;)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        if (!exp)
            break;
        base *= base;
    }

    return result;
}

