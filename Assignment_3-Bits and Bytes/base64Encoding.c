/*
 * Problem-9: Base64 Encoding
 * Ayush Singh 1910990059 17/08/21
 * Assignment_3 -> Bits and Bytes
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//Returns index corresponding to the Base32 character
int getBase32Index(char c){
    if(c >= 65 && c <= 90)
        return c-65;
    else if(c >= 50 && c <= 55)
        return c-24;
    return -1;
}

// Returns Base64 value corresponding to given index
char getBase64Char(int n){
    if(n >= 0 && n <= 25)
        return n+65;
    else if(n >= 26 && n <= 51)
        return n+71;
    else if(n >= 52 && n <= 61)
        return n-4;
    else if(n == 62)
        return '+';
    else if(n == 63)
        return '/';
    return '_';
}

// Combining 6 bits together to form Base64 index
void gen_result(char *res, int *k, int n){
    char val;

    if(n == 0)
        return;

    // Using mask 0x3f to get first 6 bits
    val = getBase64Char(n & 0x3f);
    gen_result(res, k, n >> 6);
    res[*k] = val;
    ++*k;

}

// Function to convert Base32 encoded string to Base64 encoded string
char* base32to64(char *str, int size){
    int i, n, val, k, rem;
    char *res = (char*)calloc(size, sizeof(char));
    n = k = 0;


    for(i = 0; str[i] != '\0' && str[i] != '=' && str[i] != '\n'; i++){
        val = getBase32Index(str[i]);

        // Concatenating bits of the indexes of 5 bit each
        n<<=5;
        n = n | val;

        // When 5 indexes are concatenated then convert them to Base64
        // and initialize n to 0
        if(i != 0 && (i+1)%6 == 0){
            gen_result(res, &k, n);
            n = 0;
        }
    }

    // n will have group of less than 6 indexes
    if(n != 0){
        rem = i%6;
        int bits_rem = 6 - rem;
        if((n>>bits_rem)<<bits_rem == n && str[i] == '=' )
            n>>=(6-rem);
        else
            n<<=rem;
        gen_result(res, &k, n);
    }

    // Adding Padding
    while(k % 4 != 0){
        res[k++] = '=';
    }
    res[k] = '\0';
    return res;

}

int main() {
    char str[200], *res;
    int size, test;

    scanf("%d ", &test);

    while(test--){
        fgets(str, 200, stdin);
        size = strlen(str);

        res = base32to64(str, size);
        printf("%s\n", res);
    }

    return 0;
}
