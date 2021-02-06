#ifndef QUICKUNION_H
#define QUICKUNION_H

// QuickUnion class bij me.
#include <vector>

class QuickUnion{

    // Number of elements.
    unsigned N;
    // Connected component of each element.
    std::vector<int> connected;
    // Size of each connected component.
    std::vector<int> connected_size;

    public:
    // Constructors of QuickUnion.
    QuickUnion() {}; 
    QuickUnion(unsigned n)
    {
        InitializeConnected(n);
    }

    // Connect elements p and q.
    void Union(const unsigned& p, const unsigned& q);

    // Check whether p and q are in the same connected component.
    bool Search(const unsigned& p, const unsigned& q);

    // Find the root of p.
    unsigned Root(unsigned i);

    // Print number of elements in each connected component.
    void PrintConnected();

    // Initialize the connected components.
    void InitializeConnected(unsigned& n);
};
#endif