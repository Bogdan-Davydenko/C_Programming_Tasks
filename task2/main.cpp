#include <iostream>

using namespace std;

void printSet(unsigned int a){
    int c=1;
    cout<<"{";
    bool f=false;
    while(a!=0){
        if(a%2==1){
            if(f){
                cout<<',';
            }
            f=true;
            cout<<c;
        }
        a/=2;
        c++;
    }
    cout<<"}\n";
}

int main(){
    unsigned a,b;
    cin>>a>>b;
    cout<<"A = ";
    printSet(a);
    cout<<"B = ";
    printSet(b);
    cout<<"A or B = ";
    printSet(a|b);
    cout<<"A and B = ";
    printSet(a&b);
    cout<<"A / B = ";
    printSet((a|b)^b);
    cout<<"A - B = ";
    printSet(a^b);
    return 0;
}
