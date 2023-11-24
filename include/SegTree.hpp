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
    Matrix* tree;

    Point multiply(Matrix matrix, Point p) {
        return {matrix.a * p.x + matrix.b * p.y, matrix.c * p.x + matrix.d * p.y};
    }

public:
    SegTree(int size) : n(size)
	{
		tree = new Matrix[4 * size];
        // Build the segment tree with identity matrices
        for (int i = 0; i < n; ++i) {
            Matrix identityMatrix = {1, 0, 0, 1};
            this->update(i, identityMatrix);
        }
	}

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

    void update(int pos, Matrix new_transform, int v = 0, int tl = 0, int tr = -1) {
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
            tree[pos] = {tree[2 * v].a, tree[2 * v].b, tree[2 * v].c, tree[2 * v].d};
        }
    }

    Point query(int t0, int td, int x, int y, int v = 1, int tl = 0, int tr = -1) {
        if (tr == -1) tr = n - 1;
        if (td < tl || t0 > tr || tl > tr) {
            return {x, y};
        }
        if (tl <= t0 && tr >= td) {
            return multiply(this->tree[v], {x, y});
        }

        int tm = (tl + tr) / 2;
        Point left_result = query(t0, td, x, y, 2 * v, tl, tm);
        Point right_result = query(t0, td, left_result.x, left_result.y, 2 * v + 1, tm + 1, tr);

        return right_result;
    }

};
