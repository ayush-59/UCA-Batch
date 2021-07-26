/*
 * Program to find square root of a number upto given decimal places using 
   binary search
 * Ayush Singh 1910990059 18/07/2
 * Assignment -> Day1_Coding_Assignment
*/

#include <stdio.h>
#include <math.h>

float squareRoot(int n, float left, float right, int precision){
    float mid = (left + right) / 2;

    //checking if square of mid is very close or equal to n
    if(fabs(mid*mid - n) < pow(10, -precision) )
        return mid;
        
    //if square of mid < n then result is on right side and vice versa
    if(mid*mid < n)
        return squareRoot(n, mid, right, precision);
    else
        return squareRoot(n, left, mid, precision);
}

int main()
{
    int n, precision;
    float res;

    //taking number and precision from user
    scanf("%d", &n);
    scanf("%d", &precision);

    res = squareRoot(n, 0, n, precision);
    //printing result upto given precision
    printf("ans = %.*f",precision , res);

    return 0;
}