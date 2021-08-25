#include <iostream>
#include <math.h>

long long cycle(long long n){
    if(n==1||n==2){
        return 1;
    }
    long long a=1,b=1;
    for(int i=3;i<=n;i++){
        std::swap(a,b);
        b=a+b;
    }
    return b;
}

long long rec(long long n){
    if(n==1||n==2){
        return 1;
    }
    return rec(n-1)+rec(n-2);
}

long long bine(long long n){
    return (pow((1+sqrt(5))/2,n)-pow((1-sqrt(5))/2,n))/sqrt(5);
}
