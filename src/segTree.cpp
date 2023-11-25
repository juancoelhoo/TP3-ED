#include "../include/segTree.hpp"

segTree::segTree(unsigned int n){
    Tree = new Matrix[4 * n];
    linear_transformations = new Matrix[n];
    Identity_Matrix matrix;

    for (unsigned i = 0; i < n; ++i) {
        linear_transformations[i] = matrix.identity;
    }
    this->build(1, 0, n-1);
}

void segTree::build(int node, int start, int end) 
{
    if (start == end) {
        Tree[node] = linear_transformations[start];
    } else {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        Tree[node] = Tree[node].multiply_matrices(Tree[2 * node], Tree[2 * node + 1]);
    }
}

void segTree::update(int node, int start, int end, int idx, const Matrix newValue)
{
    if (start == end) {
        Tree[node] = newValue;
    } else {
        int mid = (start + end) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, newValue);
        } else {
            update(2 * node + 1, mid + 1, end, idx, newValue);
        }
        Tree[node] = Tree[node].multiply_matrices(Tree[2 * node], Tree[2 * node + 1]);
    }
}

Matrix segTree::query(int node, int start, int end, int left, int right) 
{
    if (right < start || left > end || left > right) {
        Identity_Matrix matrix;
        return matrix.identity;
    }
    if (left <= start && right >= end) {
        return Tree[node];
    }
    int mid = (start + end) / 2;
    Matrix leftChild = query(2 * node, start, mid, left, right);
    Matrix rightChild = query(2 * node + 1, mid + 1, end, left, right);
    return leftChild.multiply_matrices(leftChild, rightChild);
}

segTree::~segTree()
{
    delete[] Tree;
    delete[] linear_transformations;
}