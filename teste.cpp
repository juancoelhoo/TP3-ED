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
    Matrix tree[4 * 100000];  // Tamanho máximo da árvore
    Point multiply(Matrix a, Point p) {
        return {a.a * p.x + a.b * p.y, a.c * p.x + a.d * p.y};
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
            tree[v] = {tree[2 * v].a, tree[2 * v].b, tree[2 * v + 1].c, tree[2 * v + 1].d};
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
            Point result = multiply(tree[v], {x, y});
            return {result.x, result.y};
        }

        int tm = (tl + tr) / 2;
        Point left_result = query(t0, td, x, y, 2 * v, tl, tm);
        Point right_result = query(t0, td, x, y, 2 * v + 1, tm + 1, tr);

        return multiply(tree[v], {left_result.x, right_result.y});
    }
};

int main() {
    // Example 2x2 matrices
    Matrix matrices[] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8}
    };

    int n = sizeof(matrices) / sizeof(matrices[0]);

    // Create a SegTree with size n
    SegTree segTree(n);

    // Build the segment tree
    segTree.build(matrices);

    // Example query
    int t0 = 0, td = 1;  // query range [t0, td]
    int x = 2, y = 3;    // point (x, y)
    Point result = segTree.query(t0, td, x, y);

    cout << "Query result for range [" << t0 << ", " << td << "] and point (" << x << ", " << y << "): ";
    cout << "(" << result.x << ", " << result.y << ")" << endl;

    // Example update
    int pos = 1;  // update position
    Matrix newTransform = {9, 10, 11, 12};
    segTree.update(pos, newTransform);

    // Query again after update
    result = segTree.query(t0, td, x, y);

    cout << "Query result after update for range [" << t0 << ", " << td << "] and point (" << x << ", " << y << "): ";
    cout << "(" << result.x << ", " << result.y << ")" << endl;

    return 0;
}
