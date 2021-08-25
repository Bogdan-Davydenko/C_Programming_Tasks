#include <bits/stdc++.h>
#include "Test.h"
#include "TestBase.h"

using namespace std;

TestBase::TestBase(){};

void TestBase::add(Test test){
    tests_count++;
    tests_list.push_back(test);
}

bool test_compare(Test l,Test r){
    return l<r;
}

void TestBase::sort(){
    tests_list.sort(test_compare);
}

void TestBase::addToSorted(Test test){
    auto it=tests_list.begin();
    bool flag=false;
    while(it!=tests_list.end()){
        if((*it)>=test){
            tests_list.insert(it,test);
            flag=true;
        }
    }

    if(flag){
        tests_list.push_back(test);
    }
}

void TestBase::write(string name, int number,vector <int> bottom_edge, vector <int> top_edge){
    for(auto it=tests_list.begin();it!=tests_list.end();it++){
        if((*it).check(name,number,bottom_edge,top_edge)){
            cout<<(*it);
        }
    }
}

void TestBase::remove(string name, int number,vector <int> bottom_edge, vector <int> top_edge){
    for(auto it=tests_list.begin();it!=tests_list.end();it++){
        if((*it).check(name,number,bottom_edge,top_edge)){
            tests_list.erase(it);
            tests_count--;
        }
    }
}

void TestBase::getBallList(int number){
    for(auto it=tests_list.begin();it!=tests_list.end();it++){
        if((*it).check(number)){
            cout<<(*it);
        }
    }
}

ostream& operator << (ostream &out,TestBase &testBase){
    out<<testBase.tests_count<<'\n';
    for(auto it=testBase.tests_list.begin();it!=testBase.tests_list.end();it++){
        out<<(*it);
    }
    out<<'\n';
    return out;
}

istream& operator >> (istream &in,TestBase &testBase){
    in>>testBase.tests_count;
    testBase.tests_list.resize(testBase.tests_count);
    for(auto it=testBase.tests_list.begin();it!=testBase.tests_list.end();it++){
        in>>(*it);
    }
    return in;
}
