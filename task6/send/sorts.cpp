#include <iostream>
using namespace std;

void select_sort(char* l,char* r){
    for(auto i=l;i!=r;i++){
        char mn=*i;
        char* mptr=i;
        for(auto j=i;j!=r;j++){
            if(mn>*j){
                mn=*j;
                mptr=j;
            }
        }
        char k=*mptr;
        *mptr=*i;
        *i=k;
    }
}

void bubble_sort(char* l,char* r){
    for(auto i=l;i!=r-2;i++){
        for(auto j=i;j!=r;j++){
            if(*i>*(i+1)){
                char k=*i;
                *i=*j;
                *j=k;
            }
        }
    }
}

void insert_sort(char* l,char* r){
    for(auto i=l+1;i!=r;i++){
        char* j=i-1;
        char x=*i;
        while(*j>x&&j!=l-1){
            *i=*j;
            *j=x;
            j--;
            i--;
        }
    }
}

void quick_sort(char* l,char* r){
    char* i=l;
    char* j=r-1;
    int n=r-l;
    char mid=*(i+(n/2));
    do{
        while(*i<mid){
            i++;
        }
        while(*j>mid){
            j--;
        }
        if(j-i>=0){
            char tmp=*i;
            *i=*j;
            *j=tmp;
            i++;
            j--;
        }
    }while(j-i>0);
    if(j-l>0){
        quick_sort(l,j+1);
    }
    if(r-i-1>0){
        quick_sort(i,r);
    }
}
