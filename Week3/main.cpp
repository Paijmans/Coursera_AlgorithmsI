#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <cassert>

#include "QuickSort.hpp"

using namespace std;

// Swap two elements of a vector.

template <class T>
class Test
{
    vector<T>& top;

    public:
    Test(vector<T>& a) : top(a) {};

    // Print vector.
    void print()
    {
        for(auto el: top) cout << el << "\t";
        cout << endl;
    }
    
};

template <class T>
void print_vec(std::vector<T> &v)
{
    for( auto el : v) cout << el << " ";
    cout << endl;
}

int main(int argc, char* argv[])
{
    unsigned N;
    if(argc != 2)
    {
        cout << "Arguments are vector length." << endl;
        return 0;
    }
    else{
        N = atoi(argv[1]);
    }    

    srand (time(NULL));

    // Create vector and fill with random numbers.
    std:vector<int> piet(N);
    for(auto& el : piet) el = rand()%N;   
    //for(int i =0; i<piet.size(); i++) piet[i] = i;

    //print_vec(piet);

    QuickSort<int> temp(piet);

    //print_vec(piet);
}