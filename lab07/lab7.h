#include<chrono>
#include<ctime>
#include<iostream>
#include<fstream>
//Prestong Giorgianni
//861161781
//5/25/15
#include<vector>
#include<assert.h>
#include <ratio>
#include<stdlib.h>
#include<unordered_set>

using namespace std;

void readWords(vector<string>& list)
{
    ifstream Words;
    Words.open("words.txt");
    assert(Words.is_open());
    string add;
    while(Words >> add)
    {
        list.push_back(add);
    }
}

//returns a pair of inserts and finds
template<typename t>
pair<double, double> times(vector<string>& list, unsigned n, t test)
{
    pair<double, double> times;
    auto start = chrono::high_resolution_clock::now();
    for(int i = 0; i < n; ++i)
    {
        test.insert(list.at(i));
    }
    auto end = chrono::high_resolution_clock::now();
    times.first = chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    start = chrono::high_resolution_clock::now();
    for(int i = 0; i < n; ++i)
    {
        test.find(list.at(i));
    }
    end = chrono::high_resolution_clock::now();
    times.second = chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    return times;
}

void randomizeWords(vector<string>& Words)
{
    for(unsigned i = 0; i < Words.size(); ++i)
    {
        swap(Words.at(i), Words.at(rand() % 50000));
    }
}