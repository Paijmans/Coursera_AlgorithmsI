// QuickSort class method definions.

#include <iostream>
#include <vector>
#include <string>

#include "QuickSort.hpp"

using namespace std;

void QuickSort::shuffle()
{

}

unsigned QuickSort::partition(unsigned lo, unsigned hi)
{

}

void QuickSort::sort(unsigned lo, unsigned hi)
{
    partition(lo, hi);

    sort(lo, j);
    sort(j, hi);
}

void QuickSort::sort()
{
    shuffle(0, vect.length());
}