#ifndef PERCOLATION_H
#define PERCOLATION_H

// QuickUnion class bij me.
#include <vector>
#include <stdexcept>

class Percolation {

    // Size of the square-grid.
    unsigned N;
    // Grid with closed (false) or open (true) sites.
    std::vector<bool> grid;

    inline unsigned vect_coord(const unsigned& row, const unsigned& col) const;

    bool CheckCoordinates(const unsigned& row, const unsigned& col) const;

    public:
    // creates n-by-n grid, with all sites initially blocked
    Percolation(unsigned n): N(n)
    {
        // Create grid of closed sites.
        grid.resize(N*N, 0);
    }

    // opens the site (row, col) if it is not open already
    void open(unsigned row, unsigned col);

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