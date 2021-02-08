#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <cassert>
#include <vector>

template <class T>
class QuickSort{

    // Reference to vector to be sorted inplace.
    std::vector<T> &vect;
    // Temperary storage used in ::swap.
    T temp;

    // Swap two elements in array.
    void Swap(unsigned& i, unsigned& j);

    // Shuffle vector elements.
    void Shuffle();
    
    // Partition vector elements between lo and hi e_i such that e_i <= e_j left of e_j and e_i > e_j right of e_j.
    unsigned Partition(unsigned lo, unsigned hi);

    // Sort keys between lo and hi.
    void Sort(unsigned lo, unsigned hi);

    // Checks whether for every pair of consecutive elements e_i, e_{i+1} in vect, e_{i} <= e_{i+1}.
    bool IsSorted() const;

    public:
    QuickSort(std::vector<T> &v) : vect(v)
    {
        Sort();
        assert(IsSorted());
    }

    // Inplace sort of vector.
    void Sort();
};

#endif