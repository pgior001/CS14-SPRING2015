// Preston Giorgianni
// 861161781
// 5/4/15
#include<iostream>
#include<string.h>
#include<math.h>
#include"lab4.h"

using namespace std;

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        cout << "Usage: <end number>" << endl;
        exit(1);
    }
    int k = 0;
    //converts argv into an int. converts char into int by using the table value
    //then it multiplies that by to raised to the place it is to give it the proper
    //place value
    for(unsigned int i = 0; i !=  strlen(argv[1]); ++i)
    {
        if(i + 1 < strlen(argv[1]))
        {
            cout << "check: " << ((argv[1][i] - '0') * (pow(10, (strlen(argv[1]) - (i + 1))))) << endl;
            k = k + ((argv[1][i] - '0') * (pow(10, (strlen(argv[1]) - (i + 1)))));
        }
        else
        {
            k += argv[1][i] - '0';
        }
    }
    cout << "test" << k << endl;
    cout << "pre-order" << endl;
    preOrder(2, 1, k);
    preOrder(3, 1, k);
    cout << "post-order" << endl;
    postOrder(2, 1, k);
    postOrder(3, 1, k);
    cout << "sorted" << endl;
    sorted(2, 1, 3, 1, k);
    return 0;
}