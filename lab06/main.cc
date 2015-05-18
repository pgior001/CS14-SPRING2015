// Preston Giorgianni
// 861161781
// 5/18/15

#include<iostream> 
#include<vector>
#include<utility>
#include<map>
#include<list>
#include"selectionsort.h"

using namespace std;

void test1()
{
    vector<int> test;
    test.push_back(2);
    test.push_back(4);
    test.push_back(5);
    test.push_back(1);
    test.push_back(8);
    test.push_back(9);
    selectionsort(test);
}

void test2()
{
    vector<pair<int, int> > check;
    pair<int, int> insert;
    insert.first = 1;
    insert.second = 2;
    check.push_back(insert);
    insert.first = 3;
    insert.second = -1;
    check.push_back(insert);
    insert.first = -1;
    insert.second = 3;
    check.push_back(insert);
    insert.first = 0;
    insert.second = 0;
    check.push_back(insert);
    insert.first = 2;
    insert.second = 3;
    check.push_back(insert);
    insert.first = 1;
    insert.second = 2;
    check.push_back(insert);
    insert.first = 1;
    insert.second = -2;
    check.push_back(insert);
    insert.first = 8;
    insert.second = 10;
    check.push_back(insert);
    selectionsort(check);
}

void test3()
{
    list<pair <int, int> > test;
    pair<int, int> in;
    in.first = 10;
    in.second = 2;
    test.push_back(in);
    in.first = -3;
    in.second = -1;
    test.push_back(in);
    in.first = -8;
    in.second = 0;
    test.push_back(in);
    in.first = 1;
    in.second = 1;
    test.push_back(in);
    test.push_back(in);
    in.first = 0;
    in.second = 0;
    test.push_back(in);
    in.first = 10;
    in.second = 2;
    test.push_back(in);
    in.first = 5;
    in.second =5;
    test.push_back(in);
    in.second = -5;
    test.push_back(in);
    in.first = 0;
    in.second = 0;
    test.push_back(in);
    in.first = 10;
    in.second = 2;
    test.push_back(in);
    selectionsort(test);
}

void test4()
{
    vector<pair<int, int> > test;
    pair<int, int> in;
    in.first = -1;
    in.second = 3;
    test.push_back(in);
    in.first = 0;
    in.second = 0;
    test.push_back(in);
    in.first = 1;
    in.second = -2;
    test.push_back(in);
    in.second = 2;
    test.push_back(in);
    test.push_back(in);
    in.first = 2;
    in.second = 3;
    test.push_back(in);
    in.first = 3;
    in.second = -1;
    test.push_back(in);
    in.first = 8;
    in.second = 10;
    test.push_back(in);
    selectionsort(test);
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    cout << "------------------------------------------------------------------" << endl;
    question2();
    return 0;
}