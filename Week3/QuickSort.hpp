#ifndef QUICKSORT_H
#define QUICKSORT_H

template <class T>
class QuickSort{

    // Reference to vector to be sorted inplace.
    T& vect;

    // Shuffle vector elements.
    void shuffle();
    
    // Partition vector elements between lo and hi e_i such that e_i <= e_j left of e_j and e_i > e_j right of e_j.
    unsigned partition(unsigned lo, unsigned hi);

    // Sort keys between lo and hi.
    void sort(unsigned lo, unsigned hi);

    public:
    Quicksort(T& v) vect(v) {}

    // Inplace sort of vector.
    void sort();
};

#endif