#include <iostream>

using namespace std;

struct Matrix {
    int a, b, c, d;
};

struct Point {
    int x, y;
};

class SegTree {
private:
    int n;
    Matrix tree[4 * 1000];

    Point multiply(Matrix matrix, Point p) {
        return {matrix.a * p.x + matrix.b * p.y, matrix.c * p.x + matrix.d * p.y};
    }

public:
    SegTree(int size) : n(size) {}

    void build(Matrix arr[], int v = 1, int tl = 0, int tr = -1) {
        if (tr == -1) tr = n - 1;
        if (tl == tr) {
            tree[v] = arr[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(arr, 2 * v, tl, tm);
            build(arr, 2 * v + 1, tm + 1, tr);
            tree[v] = {tree[2 * v].a, tree[2 * v].b, tree[2 * v].c, tree[2 * v].d};
        }
    }

    void update(int pos, Matrix new_transform, int v = 1, int tl = 0, int tr = -1) {
        if (tr == -1) tr = n - 1;
        if (tl == tr) {
            tree[v] = new_transform;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm) {
                update(pos, new_transform, 2 * v, tl, tm);
            } else {
                update(pos, new_transform, 2 * v + 1, tm + 1, tr);
            }
            tree[v] = {tree[2 * v].a, tree[2 * v].b, tree[2 * v + 1].c, tree[2 * v + 1].d};
        }
    }

    Point query(int t0, int td, int x, int y, int v = 1, int tl = 0, int tr = -1) {
        if (tr == -1) tr = n - 1;
        if (t0 > tr || td < tl) {
            return {x, y};
        }
        if (t0 <= tl && td >= tr) {
            return multiply(tree[v], {x, y});
        }

        int tm = (tl + tr) / 2;
        Point left_result = query(t0, td, x, y, 2 * v, tl, tm);
        Point right_result = query(t0, td, x, y, 2 * v + 1, tm + 1, tr);

        return {left_result.x + right_result.x, left_result.y + right_result.y};
    }
};

const int maxn = 1e5 + 10;
Matrix matrices[maxn]; // Assuming you have a matrix array for the SegTree

int main() {
    // Example: Set the size of your array
    int n = 3; // Adjust the size as needed

    // Example: Set a fixed array of matrices
    Matrix fixedMatrices[] = {
        {1, 0, 0, 1},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    // Create a SegTree with size n
    SegTree segTree(n);

    // Build the segment tree with the fixed array
    segTree.build(fixedMatrices);

    // Example query
    int t0 = 0, td = 2;  // query range [t0, td]
    int x = 2, y = 3;    // point (x, y)
    Point result = segTree.query(t0, td, x, y);

    cout << "Query result for range [" << t0 << ", " << td << "] and point (" << x << ", " << y << "): ";
    cout << "(" << result.x << ", " << result.y << ")" << endl;

    // Example update
    int pos = 0;  // update position
    Matrix newTransform = {9, 10, 11, 12};
    segTree.update(pos, newTransform);

    // Query again after update
    result = segTree.query(t0, td, x, y);

    cout << "Query result after update for range [" << t0 << ", " << td << "] and point (" << x << ", " << y << "): ";
    cout << "(" << result.x << ", " << result.y << ")" << endl;

    return 0;
}
