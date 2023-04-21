#include "algorithm.h"

int fibonacci(int n)
{   
    if(n<=1){
        return n;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

int fibonacci_dynamic(int n){
    int fib[n+1];
    fib[0] = 0;
    fib[1] = 1;

    for (int i =2; i<=n; i++){
        fib[i] = fib[i-1] + fib[i-2];
    }
    return fib[n];
}

int factorial(int n)
{   
    if(n==0){
        return 1;
    }
    return n * factorial(n-1);
}
