// QuickUnion class method definions.

#include <iostream>
#include <vector>
#include <string>

#include "QuickUnion.hpp"

using namespace std;

// Initialize syste with n components only connected to themselves.
void QuickUnion::InitializeConnected(unsigned& n)
{
    // Initialized vector of connected components.
    N = n;
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
void QuickUnion::Union(const unsigned& p, const unsigned& q)
{
    unsigned root_p(Root(p));
    unsigned root_q(Root(q));

    // If p and q are connected, do nothing.
    if (root_p == root_q) return;

    // Change the root of the smaller connected component to that of the larger one.
    // Update size of new connected component.
    if (connected_size[root_p] < connected_size[root_q])
    {
        connected[root_p] = root_q;
        connected_size[root_q] += connected_size[root_p];
        connected_size[root_p] = 0;
    }
    else
    {
        connected[root_q] = root_p;
        connected_size[root_p] += connected_size[root_q];
        connected_size[root_q] = 0;
    }


}

// Check whether p and q are in the same connected component.
bool QuickUnion::Search(const unsigned& p, const unsigned& q)
{
    // Two elements are in the same connected component if they have the same root.
    return Root(p) == Root(q);
}

// Find the root of p.
// Updates all references to grandparent along the search for speedup.
unsigned QuickUnion::Root(unsigned i)
{
    // Move through the tree until you reach an element that refers to itself.
    while( connected[i] != i)
    {
        connected[i] = connected[connected[i]];
        i = connected[i];
    } 
    return i;
}

// Print number of elements in each connected component.
void QuickUnion::PrintConnected()
{
    unsigned id(0);
    unsigned tot(0);
    for(const auto& cc_size : connected_size){

        if(cc_size > 0)
            cout << id << "\t" << cc_size << endl;
    
        tot += cc_size;
        id++;
    }
    cout << "Total number of elements: " << tot << endl;
}