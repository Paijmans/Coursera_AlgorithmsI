// QuickSort class method definions.

#include <iostream>
#include <vector>
#include <stdlib.h>

#include "QuickSort.hpp"

using namespace std;

template <class T>
void QuickSort<T>::Swap(unsigned& i, unsigned& j)
{
    temp = vect[i];
    vect[i] = vect[j];
    vect[j] = temp;
}


template <class T>
void QuickSort<T>::Shuffle()
{
    unsigned N(vect.size());

    if(N < 2) return;
     
    srand (time(NULL));
    
    unsigned iRand;
    for(unsigned iVect=1; iVect<N; iVect++)
    {
        iRand = rand()%(iVect+1);
        Swap(iRand, iVect);
    }
}


template <class T>
unsigned QuickSort<T>::Partition(unsigned lo, unsigned hi)
{
    unsigned iLeft(lo);
    unsigned iRight(hi);

    while(true)
    {
        while(vect[++iLeft] < vect[lo])
            if(iLeft == hi-1) break;
        while(vect[--iRight] > vect[lo]) 
            if(iRight == lo) break;

        if(iLeft >= iRight) break;
        Swap(iLeft, iRight);
    }
    //cerr << "** - " << vect[lo] << " " << iRight << endl;
    Swap(lo, iRight);
    // for(int i = lo; i < hi; i++)
    //     cerr << vect[i] << " ";
    // cerr << endl;

    return iRight;
}


template <class T>
void QuickSort<T>::Sort(unsigned lo, unsigned hi)
{
    if(hi <= lo+1) return;
    unsigned j(Partition(lo, hi));

    Sort(lo, j);
    Sort(j+1, hi);
}


template <class T>
void QuickSort<T>::Sort()
{
    Shuffle();
    Sort(0, vect.size());
}


template <class T>
bool QuickSort<T>::IsSorted() const
{
    for(unsigned iVect=0; iVect < vect.size()-1; iVect++)
        if(vect[iVect] > vect[iVect+1]) return false;
    
    return true;
}

// Explicit instantiations of the QuickSort template class.
template class QuickSort<int>;
template class QuickSort<unsigned>;
template class QuickSort<float>;
template class QuickSort<double>;