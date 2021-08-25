#include <bits/stdc++.h>
#include "sorts.h"
#include <fstream>
using namespace std;

void sort(char *file_name,int t_sort=3,int t_file=0){
    if( ifstream(file_name).fail()){
        cout<<"File does not exists.\n";
        return;
    }
    int n;
    string s;
    switch(t_file){
    case 0:
        {
            freopen(file_name,"r",stdin);
            getline(cin,s,(char)0);
            fclose(stdin);
        }
    break;
    case 1:
        ifstream in(file_name,ios::binary|ios::in);
        char c=1;
        while(!in.eof()){
            in.read((char*)&c,sizeof c);
            s.push_back(c);
        }
        in.close();
    break;
    }
    n=s.size();
    char arr[n];
    for(int i=0;i<n;i++){
        arr[i]=s[i];
    }
    switch(t_sort){
    case 0:
        select_sort(arr,arr+n);
    break;
    case 1:
        bubble_sort(arr,arr+n);
    break;
    case 2:
        insert_sort(arr,arr+n);
    break;
    case 3:
        quick_sort(arr,arr+n);
    break;
    }
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
    return;
}

int main(int argc, char *argv[]){
    switch(argc){
    case 2:
        sort(argv[1]);
    break;
    case 3:
        if(strcmp(argv[1],"-s")==0){
            sort(argv[2],0);
        }else if(strcmp(argv[1],"-b")==0){
            sort(argv[2],1);
        }else if(strcmp(argv[1],"-i")==0){
            sort(argv[2],2);
        }else if(strcmp(argv[1],"-q")==0){
            sort(argv[2],3);
        }else if(strcmp(argv[1],"-t")==0){
            sort(argv[2],3,0);
        }else if(strcmp(argv[1],"-2")==0){
            sort(argv[2],3,1);
        }else{
            cout<<"Invalid argument\n";
            return 0;
        }
    break;
    case 4:
        if(strcmp(argv[2],"-t")==0){
            if(strcmp(argv[1],"-s")==0){
                sort(argv[3],0,0);
            }else if(strcmp(argv[1],"-b")==0){
                sort(argv[3],1,0);
            }else if(strcmp(argv[1],"-i")==0){
                sort(argv[3],2,0);
            }else if(strcmp(argv[1],"-q")==0){
                sort(argv[3],3,0);
            }else{
                cout<<"Invalid argument\n";
                return 0;
            }
        }else if(strcmp(argv[2],"-2")==0){
            if(strcmp(argv[1],"-s")==0){
                sort(argv[3],0,1);
            }else if(strcmp(argv[1],"-b")==0){
                sort(argv[3],1,1);
            }else if(strcmp(argv[1],"-i")==0){
                sort(argv[3],2,1);
            }else if(strcmp(argv[1],"-q")==0){
                sort(argv[3],3,1);
            }else{
                cout<<"Invalid argument\n";
                return 0;
            }
        }else if(strcmp(argv[2],"-s")==0){
            if(strcmp(argv[1],"-t")==0){
                sort(argv[3],0,0);
            }else if(strcmp(argv[1],"-2")==0){
                sort(argv[3],0,1);
            }else{
                cout<<"Invalid argument\n";
                return 0;
            }
        }else if(strcmp(argv[2],"-b")==0){
            if(strcmp(argv[1],"-t")==0){
                sort(argv[3],1,0);
            }else if(strcmp(argv[1],"-2")==0){
                sort(argv[3],1,1);
            }else{
                cout<<"Invalid argument\n";
                return 0;
            }
        }else if(strcmp(argv[2],"-i")==0){
            if(strcmp(argv[1],"-t")==0){
                sort(argv[3],2,0);
            }else if(strcmp(argv[1],"-2")==0){
                sort(argv[3],2,1);
            }else{
                cout<<"Invalid argument\n";
                return 0;
            }
        }else if(strcmp(argv[2],"-q")==0){

            if(strcmp(argv[1],"-t")==0){
                cout<<"!!!";
                sort(argv[3],3,0);
            }else if(strcmp(argv[1],"-2")==0){
                sort(argv[3],3,1);
            }else{
                cout<<"Invalid argument\n";
                return 0;
            }
        }else{
            cout<<"Invalid argument\n";
            return 0;
        }
    break;
    default:
        cout<<"Invalid argument's count\n";
        return 0;
    }
    return 0;
}
