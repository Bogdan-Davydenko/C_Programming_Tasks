#include <bits/stdc++.h>
#include "Test.h"
using namespace std;

Test::Test(){}

Test::Test(string person_name,int test_number,int questions_count, vector <int> points){
    this->person_name=person_name;
    this->test_number=test_number;
    this->questions_count=questions_count;
    this->points=points;
}
/*
void Test::read(){
    cout<<"Input name:\n";
    cin>>person_name;
    do{
        cin.clear();
        cin.ignore(32767,'\n');
        cout<<"Input test number:\n";
        cin>>test_number;
    }while(cin.fail());
    do{
        cin.clear();
        cin.ignore(32767,'\n');
        cout<<"Input number of questions:\n";
        cin>>questions_count;
    }while(cin.fail()||questions_count<0||questions_count>1e9);
    points.resize(questions_count);
    cout<<"Input score list:\n";
    for(int i=0;i<questions_count;i++){
        do{
            cin.clear();
            cin.ignore(32767,'\n');
            cin>>points[i];
        }while(cin.fail());
    }
}

void Test::read(ifstream fin){
    fin>>person_name>>test_number>>questions_count;
    points.resize(questions_count);
    for(int i=0;i<questions_count;i++){
        fin>>points[i];
    }
}

void Test::write(){
    cout<<"Person name: "<<person_name<<"\nTest number: "<<test_number<<"\nQuestions count: "<<questions_count<<"\nScore:\n";
    for(int i=0;i<questions_count;i++){
        cout<<points[i]<<' ';
    }
}
*/
int Test::compare(Test left, Test right){
    if(left.person_name>right.person_name){
        return 1;
    }else if(left.person_name==right.person_name){
        if(left.test_number>right.test_number){
            return 1;
        }else if(left.test_number==right.test_number){
            return 0;
        }
    }
    return -1;
}


bool Test::check(string name, int number,vector <int> bottom_edge, vector <int> top_edge){
    if(person_name!=name&&name!="*"){
        return false;
    }
    if(test_number!=number&&number!=-1){
        return false;
    }
    for(int i=0;i<questions_count;i++){
        if(points[i]<bottom_edge[i]||points[i]>top_edge[i]){
            return false;
        }
    }
    return true;
}

bool Test::check(int number){
    return test_number==number;
}

int Test::getProperty(vector <int> weights){
    int sum=0;
    for(int i=0;i<questions_count;i++){
        sum+=weights[i]*points[i];
    }
    return sum;
}

bool operator < (Test left,Test right){
    return left.compare(left,right)<0;
}

bool operator> (Test left,Test right){
    return left.compare(left,right)>0;
}

bool operator <= (Test left,Test right){
    return left.compare(left,right)<=0;
}

bool operator >= (Test left,Test right){
    return left.compare(left,right)>=0;
}

bool operator != (Test left,Test right){
    return left.compare(left,right)!=0;
}

bool operator == (Test left,Test right){
    return left.compare(left,right)==0;
}

ostream& operator << (ostream &out,Test &test){

    out<<test.person_name<<'\n'<<test.test_number<<'\n'<<test.questions_count<<'\n';
    for(int i=0;i<test.questions_count;i++){
        out<<test.points[i]<<' ';
    }
    out<<'\n';
    return out;
}

istream& operator >> (istream &in,Test &test){
    in>>test.person_name>>test.test_number>>test.questions_count;
    test.points.resize(test.questions_count);
    for(int i=0;i<test.questions_count;i++){
        in>>test.points[i];
    }
    return in;
}
