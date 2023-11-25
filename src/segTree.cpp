#include "../include/segTree.hpp"

segTree::segTree(unsigned int n){
    Tree = new Matrix[4 * n];
    transforms = new Matrix[n];
    Identity_Matrix matrix;

    for (unsigned i = 0; i < n; ++i) {
        transforms[i] = matrix.identity;
    }
    this->build(1, 0, n-1);
}

Point Point::linear_transf(const Matrix matrix, const Point A)
{
    Point result;
    result.x = (matrix.values[0][0] * A.x) + (matrix.values[0][1] * A.y); 
    result.y = (matrix.values[1][0] * A.x) + (matrix.values[1][1] * A.y);
    return result;
}

Matrix segTree::multiply_matrices(const Matrix matrix1, const Matrix matrix2){
    Matrix result;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            result.values[i][j] = 0;
            for (int k = 0; k < 2; ++k) {
                result.values[i][j] += (static_cast<long long>
                (matrix1.values[i][k]) * matrix2.values[k][j]) % MOD;
                result.values[i][j] %= MOD;
            }
        }
    }
    return result;
}

void segTree::build(int node, int start, int end) 
{
    if (start == end) {
        Tree[node] = transforms[start];
    } else {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        Tree[node] = multiply_matrices(Tree[2 * node], Tree[2 * node + 1]);
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
        Tree[node] = multiply_matrices(Tree[2 * node], Tree[2 * node + 1]);
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
    return multiply_matrices(leftChild, rightChild);
}

segTree::~segTree()
{
    delete[] Tree;
    delete[] transforms;
}