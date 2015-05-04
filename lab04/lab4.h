// Preston Giorgianni
// 861161781
// 5/4/15
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef pair<int,int> Entry;
class Priority_queue
{
    public:
        vector<Entry> entries;
        Entry& front() { return entries.back(); }
        void pop() { entries.pop_back(); }
        void push( Entry e )
        { 
            entries.push_back( e );
            for ( int i = entries.size()-1; i != 0; --i )
            {
                //if combine second pair is bigger and first value is smaller changes values
                if (entries[i].first + entries[i].second <= entries[i-1].first + entries [i-1].second)
                {
                    //sorts by first number if the sums are equal
                    if(entries[i].first + entries[i].second == entries[i-1].first + entries [i-1].second)
                    {
                        if(entries[i].first < entries[i-1].first)
                        {
                            break;
                        }
                    }
                    else
                    {
                        break;
                    }
                }
                swap(entries[i], entries[i-1]);
            }
        }
};

//prints valuse after it has hit end
void postOrder(int m, int n, int k)
{
    if(m + n >= k)
    {
        return;
    }
    postOrder(2 * m -n, m , k);
    postOrder(2 * m + n, m, k);
    postOrder(m + 2 * n, n, k);
    cout << m << ' ' << n << endl;
}


//prints values then continues
void preOrder(int m, int n, int k)
{
    if(m + n >= k)
    {
        return;
    }
    cout << m << ' ' << n << endl;
    preOrder(2 * m -n, m , k);
    preOrder(2 * m + n, m, k);
    preOrder(m + 2 * n, n, k);
}

//sorted helper checks them, delets after check, then prints them in assending order
//uses priority queue to assure assending oreder
void inOrder(Priority_queue& vals, int k)
{
    if(vals.front().first + vals.front().second >= k)
    {
        return;
    }
    int m = vals.front().first;
    int n = vals.front().second;
    vals.pop();
    Entry add;
    add.first = (2 * m) - n;
    add.second = m;
    vals.push(add);
    add.first = (2 * m) + n;
    vals.push(add);
    add.first = m + (n * 2);
    add.second = n;
    vals.push(add);
    cout << m << ' ' << n << endl;
    inOrder(vals, k);
}

//sets up queue and calles helper function inOrder
//takes the values of the childeren so that it can check both sides at once
void sorted(int m, int n, int m1, int n1, int k)
{
    Priority_queue vals;
    Entry test;
    test.first = m;
    test.second = n;
    vals.push(test);
    test.first = m1;
    test.second = n1;
    vals.push(test);
    inOrder(vals, k);
}