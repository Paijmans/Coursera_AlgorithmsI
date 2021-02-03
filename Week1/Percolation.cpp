#include "Percolation.hpp"

// Update QuickUnion connected components when site is openened.
void Percolation::QUOpen(unsigned& row, unsigned& col)
{
    // Determine the opened site vector position.
    unsigned mid(vect_coord(row, col));

    // Make connection to top site in grid.
    if(row>0 && isFull(row-1, col))
    {
        QUGrid.Union(mid, vect_coord(row-1, col));
    }
    // Make connection to bottom site in grid.
    if(row<N-1 && isFull(row+1, col))
    {
        QUGrid.Union(mid, vect_coord(row+1, col));
    }
    // Make connection to left site in grid.
    if(col>0 && isFull(row, col-1))
    {
        QUGrid.Union(mid, vect_coord(row, col-1));
    }
    // Make connection to right site in grid.
    if(col<N-1 && isFull(row, col+1))
    {
        QUGrid.Union(mid, vect_coord(row, col+1));
    }            
    // Make connection to virtual top site.
    if(row == 0)
    {
        QUGrid.Union(mid, N*N);
    }
    // Make connection to virtual bottom site.
    if(row == N-1)
    {
        QUGrid.Union(mid, N*N+1);
    }
}

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

// Opens the site (row, col). Returns true is site was closed.
bool Percolation::open(unsigned row, unsigned col)
{
    if (isOpen(row, col))
    {
        // Set the field to open.
        Grid[vect_coord(row, col)] = true;
        // Update the connected components on the field.
        QUOpen(row, col);
        
        return true;
    }
    return false;
}

// is the site (row, col) open?
bool Percolation::isOpen(unsigned row, unsigned col)
{
    return (Grid[vect_coord(row, col)] == false);
}

// is the site (row, col) full?
bool Percolation::isFull(unsigned row, unsigned col)
{
    return (Grid[vect_coord(row, col)] == true);
}

// returns the number of open sites
int Percolation::numberOfOpenSites()
{
    unsigned open_sites(0);

    for (const auto& full : Grid)
        open_sites += (1-full);

    return open_sites;
}

// does the system percolate?
bool Percolation::percolates()
{
    // System percolates when the two virtual grid points are in the same connected component.
    return QUGrid.Search(N*N, N*N+1);
}