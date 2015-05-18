// Preston Giorgianni
// 861161781
// 5/18/15

#include<utility>
#include<iostream>
#include<typeinfo>

using namespace std;

//used to only compare the first int in the < operator of a pair
class mypair : public pair<int, int>
{
    public:
    
    bool operator <(mypair B)
    {
        return this->first < B.first;
    }
};


//display is overloaded for pairs and not pairs to be able to print out both types
template <typename t, typename x>
void display(pair<t, x> l)
{
    cout << '(' << l.first << ',' << l.second << ')' << ' ';
}

//used only for question two display
void display(mypair l)
{
    cout << '(' << l.first << ',' << l.second << ')' << ' ';
}

template <typename D>
void display(D l)
{
    cout << l << ' ';
}

template<typename L>
void selectionsort(L &l)
{
    //uses iterators and overloaded display to print out the lsit
    cout << "pre: ";
    for(auto curr = l.begin(); curr != l.end(); ++curr)
    {
        display(*curr);
    }
    cout << endl;
    int swapCount = 0;
    //uses iterators to go through list and swap with the lowest value found
    //uses swap count to count swaps
    for(auto out = l.begin(); out != l.end(); ++out)
    {
        auto lowest = out;
        for(auto curr = out; curr != l.end(); ++curr)
        {
            if(*curr < *lowest)
            {
                lowest = curr;
            }
        }
        if(lowest != out)
        {
            swapCount++;
            swap(*lowest, *out);
        }
    }
    
    //uses iterators and overloaded display to print out the lsit
    cout << "post: ";
    for(auto curr = l.begin(); curr != l.end(); ++curr)
    {
        display(*curr);
    }
    cout << endl;
    cout << "0 copies and " << 3 * swapCount << " moves" << endl;
}

//uses mypair class to only compair the first in to keep track of the which time
//it appeared in the list with the second int
void question2()
{
    cout << "Part 2" << endl;
    list<mypair> test;
    mypair in;
    list<mypair> test2;
    in.first = 5;
    in.second = 1;
    test2.push_back(in);
    in.second = 2;
    test2.push_back(in);
    in.first = 4;
    in.second =0;
    test2.push_back(in);
    selectionsort(test2);
}
