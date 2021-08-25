#include <iostream>
#include <stdio.h>
#include <iomanip>

using namespace std;

int main()
{
    float a,b;
    cin>>a>>b;
    cout<<setprecision(10)<<"a+b="<<a+b<<"\na-b="<<a-b<<"\nab="<<a*b<<"\na/b="<<a/b;
    return 0;
}
