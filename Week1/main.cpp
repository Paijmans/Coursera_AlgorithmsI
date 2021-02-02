#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

#include "QuickUnion.hpp"

using namespace std;

int main(){

    unsigned N(1e6);

    /* initialize random seed: */
    srand (time(NULL));

    QuickUnion qu(N);

    unsigned p,q;
    for(int i=0; i<3*N; i++)
    {
        p = rand()%N;
        q = rand()%N;

        qu.Union(p,q);

        //cout << "Union:\t" << p << "\t" << q << endl;
    }

    qu.PrintConnected();
}