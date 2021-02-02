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
    // Constructor of QuickUnion.
    QuickUnion(unsigned n): N(n)
    {
        // Initialized vector of connected components.
        connected.resize(N);
        connected_size.resize(N);
        for(unsigned i=0; i<N; i++) 
        {
            // Every element is its own connected component.
            connected[i] =  i;
            // Every connected component has size 1.
            connected_size[i] = 1;
        }
    }

    // Connect elements p and q.
    void Union(const unsigned& p, const unsigned& q);

    // Check whether p and q are in the same connected component.
    bool Search(const unsigned& p, const unsigned& q);

    // Find the root of p.
    unsigned Root(unsigned i);

    // Print number of elements in each connected component.
    void PrintConnected();
};



#endif