// Preston Giorgianni
// 861161781
// 5/11/15

#include<iostream>
#include<array>
#include"lab5.h"

using namespace std;

void test1()
{
    BST<int> test;
    test.insert(50);
    test.insert(60);
    test.insert(20);
    test.insert(10);
    test.insert(40);
    test.insert(35);
    test.insert(45);
    test.insert(70);
    test.minCover();
    test.displayMinCover();
    //changed findSumPath to a helper function because we do not have acess to a node
    //outside of the tree.
    // int buffer[500];
    // test.findSumPath(test.root, 80, buffer);
    test.SumPath(80);
    test.vertsum();   
}

void test2()
{
    BST<int> test;
    test.insert(50);
    test.insert(60);
    test.insert(20);
    test.insert(10);
    test.insert(40);
    test.insert(35);
    test.insert(45);
    test.insert(70);
    test.insert(5);
    test.insert(75);
    test.insert(55);
    test.insert(15);
    test.minCover();
    test.displayMinCover();
    test.SumPath(85);
    test.vertsum();
}

void test3()
{
    BST<int> test;
    test.displayMinCover();
    test.SumPath(80);
    test.vertsum();
}

int main()
{
    cout << "case 1" << endl;
    test1();
    cout << "case 2" << endl;
    test2();
    cout << "case 3" << endl;
    test3();
    return 0;
}