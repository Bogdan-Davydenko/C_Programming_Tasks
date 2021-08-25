#include <iostream>

using namespace std;

#ifndef TEST_H
#define TEST_H

class Test{
    string person_name;
    int test_number;
    int questions_count;
    vector <int> points;

public:
    Test();
    Test(string person_name,int test_number,int questions_count, vector <int> points);
    //void read();
    //void read(ifstream fout);
    //void write();
    int compare(Test left, Test right);
    bool check(string name, int number, vector <int> bottom_edge, vector <int> top_edge);
    bool check(int number);
    int getProperty(vector <int> weights);

    friend ostream& operator << (ostream &out,Test &test);
    friend istream& operator >> (istream &in,Test &test);
};

bool operator < (Test left,Test right);

bool operator> (Test left,Test right);

bool operator <= (Test left,Test right);

bool operator >= (Test left,Test right);

bool operator != (Test left,Test right);

bool operator == (Test left,Test right);

ostream& operator << (ostream &out,Test &test);

istream& operator >> (istream &in,Test &test);

#endif
