#ifndef PERCOLATION_H
#define PERCOLATION_H

// QuickUnion class bij me.
#include <vector>
#include <stdexcept>

#include "QuickUnion.hpp"

class Percolation {

    // Size of the square-grid.
    unsigned N;
    // Grid with closed (false) or open (true) sites.
    std::vector<bool> Grid;
    // QuickUnion to track connected components of open fields on the grid.
    QuickUnion QUGrid;
    // Convert grid coord to vector coord.
    inline unsigned vect_coord(const unsigned& row, const unsigned& col) const;
    // Check whether given coordiante are within range.
    bool CheckCoordinates(const unsigned& row, const unsigned& col) const;
    // Update connected components when site is openened.
    void QUOpen(unsigned& row, unsigned& col);

    public:
    // creates n-by-n grid, with all sites initially blocked
    Percolation(unsigned n): N(n)
    {
        // Create grid of closed sites.
        Grid.resize(N*N, 0);
        // Initialize the QuickUnion object. N * N grid points + the top and bottom row virtual grid points.
        unsigned number_of_elements(N*N+2);
        QUGrid.InitializeConnected(number_of_elements);
    }

    // opens the site (row, col) if it is not open already
    bool open(unsigned row, unsigned col);

    // is the site (row, col) open?
    bool isOpen(unsigned row, unsigned col);

    // is the site (row, col) full?
    bool isFull(unsigned row, unsigned col);

    // returns the number of open sites
    int numberOfOpenSites();

    // does the system percolate?
    bool percolates();
};

#endif