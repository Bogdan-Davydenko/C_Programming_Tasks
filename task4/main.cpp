#include <iostream>
#include "funk.h"

using namespace std;

int main()
{
    long long n;
    cout<<"0<=n<=92\n";
    do{
        cin>>n;
    }while(n>92||n<0);
    //cin>>n;
    cout << cycle(n) << ' ' << bine(n) <<' '<< rec(n) << ' ' << '\n';
    return 0;
}
