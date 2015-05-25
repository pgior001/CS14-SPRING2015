//Prestong Giorgianni
//861161781
//5/25/15
#include<iostream>
#include"lab7.h"
#include<set>
#include<unordered_set>

using namespace std;

int main()
{
    srand(time(0));
    vector<string> words;
    readWords(words);
    set<string> ordered;
    unordered_set<string> unordered;
    vector<int> orderInsert(10);
    vector<int> unorderedInsert(10);
    vector<int> orderFind(10);
    vector<int> unorderedFind(10);
    pair<double, double> Time;
    //calls randomization and time checks
    for(int i = 0; i < 10; ++i)
    {
        randomizeWords(words);
        for(int i = 5000; i <= 50000; i += 5000)
        {
            Time = times(words, i, ordered);
            orderInsert.at((i / 5000) - 1) += (Time.first / i);
            orderFind.at((i / 5000) - 1) += (Time.second / i);
        }
        for(int i = 5000; i <= 50000; i += 5000)
        {
            Time = times(words, i, unordered);
            unorderedInsert.at((i / 5000) - 1) += (Time.first / i);
            unorderedFind.at((i / 5000) - 1) += (Time.second / i);
        }
    }
    ofstream data;
    data.open("data.txt");
    //averages times and puts them into data.txt
    for(int i = 5000; i <= 50000; i += 5000)
    {
        data << i << ' ' << orderInsert.at(i / 5000 - 1) / 10 << ' ' << unorderedInsert.at(i / 5000 - 1) / 10
        << ' ' << orderFind.at(i / 5000 - 1) / 10 << ' ' << unorderedFind.at(i / 5000 - 1) / 10 << endl;
    }
    return 0;
}