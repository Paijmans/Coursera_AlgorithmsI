#include "Percolation.hpp"

// Convert (row, col) into vector coordinate
inline unsigned Percolation::vect_coord(const unsigned& row, const unsigned& col) const
{
    return row + col*N;
}

// Check if coordinate is valid; Retuns true if N is within range.
bool Percolation::CheckCoordinates(const unsigned& row, const unsigned& col) const
{
    if(row < 0 || row > N || col < 0 || col > N)
    {
        throw std::out_of_range("Invalid grid coordinate given.");
        return false;
    }
    return true; 
}

// opens the site (row, col) if it is not open already
void Percolation::open(unsigned row, unsigned col)
{
    if (isOpen(row, col))
    {
        grid[vect_coord(row, col)] = true;
        QUopen(row, col);
    }
}

// is the site (row, col) open?
bool Percolation::isOpen(unsigned row, unsigned col)
{
    return (grid[vect_coord(row, col)] == false);
}

// is the site (row, col) full?
bool Percolation::isFull(unsigned row, unsigned col)
{
    return (grid[vect_coord(row, col)] == true);
}

// returns the number of open sites
int Percolation::numberOfOpenSites()
{
    unsigned open_sites(0);

    for (const auto& full : grid)
        open_sites += (1-full);

    return open_sites;
}

// does the system percolate?
bool Percolation::percolates()
{

}