#ifndef SEGTREE_HPP
#define SEGTREE_HPP

#include <iostream>
#include "../include/matrix.hpp"

class segTree {
    private:
        Matrix* Tree;    
        int maxNodes;        
    public:
        Matrix* linear_transformations;

        // Constructor for initializing the segment tree with a specified number of linear transformations
        segTree(unsigned int n);

        // Build the segment tree given the root node, start, and end indices
        void build(int node, int start, int end);

        // Update the segment tree by modifying the value at a specified index
        void update(int node, int start, int end, int idx, const Matrix newValue);
            
        // Query the segment tree for the combined linear transformation in a specified range
        Matrix query(int node, int start, int end, int left, int right);

        // Destructor to free dynamically allocated memory
        ~segTree();
};

#endif
