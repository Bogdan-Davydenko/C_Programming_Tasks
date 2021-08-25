#include <iostream>

using namespace std;

#ifndef TESTBASE_H
#define TESTBASE_H

class TestBase{
    int tests_count;
    list <Test> tests_list;
public:
    TestBase();
    void add(Test test);
    void sort();
    void addToSorted(Test test);
    void write(string name, int number,vector <int> bottom_edge, vector <int> top_edge);
    void remove(string name, int number,vector <int> bottom_edge, vector <int> top_edge);
    void getBallList(int number);

    friend ostream& operator << (ostream &out,TestBase &testBase);
    friend istream& operator >> (istream &in,TestBase &testBase);
};

bool test_compare(Test l,Test r);

ostream& operator << (ostream &out,TestBase &testBase);
istream& operator >> (istream &in,TestBase &testBase);

#endif
