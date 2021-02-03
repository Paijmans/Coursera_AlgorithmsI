#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

#include "QuickUnion.hpp"
#include "Percolation.hpp"

using namespace std;

double PerculationFraction(unsigned& N)
{
    //QuickUnion qu(N);
    Percolation perc(N);

    // Continue to open sites in the grid until system perculates.
    unsigned p, q, OpenedSites(0);
    while(!perc.percolates())
    {
        p = rand()%N;
        q = rand()%N;

        if(perc.open(p, q))
        {
            OpenedSites++;
        }
    }

    return double(OpenedSites)/(N*N);
}

int main(int argc, char* argv[]){

    unsigned N;
    unsigned SampleNumber;
    if(argc != 3)
    {
        cout << "Arguments are [grid size] and [sample number]." << endl;
        return 0;
    }
    else{
        N = atoi(argv[1]);
        SampleNumber = atoi(argv[2]);
    }
    //cout << N << " " << SampleNumber << endl;
    /* initialize random seed: */
    srand (time(NULL));

    for(unsigned iSample=0; iSample<SampleNumber; iSample++)
    {
        if(iSample%10000==0)
        {
            cerr << double(iSample)/SampleNumber << endl;
        }
        cout << PerculationFraction(N) << endl;
    }
}