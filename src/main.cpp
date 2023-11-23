#include <iostream>
#include "../include/SegTree.hpp"

const int maxn = 1e5 + 10;
Matrix matrices[maxn]; // Assuming you have a matrix array for the SegTree

int main() {
    int n, q;
    cin >> n >> q;

    // Create a SegTree with size n
    SegTree segTree(n);

    // Build the segment tree with identity matrices
    for (int i = 0; i < n; ++i) {
        Matrix identityMatrix = {1, 0, 0, 1};
        segTree.update(i, identityMatrix);
    }

    // Perform q operations (update or query)
    for (int i = 0; i < q; ++i) {
        char operationType;
        cin >> operationType;

        if (operationType == 'u') {
            // Update operation
            int pos;
            Matrix newTransform;
            cin >> pos >> newTransform.a >> newTransform.b >> newTransform.c >> newTransform.d;
            segTree.update(pos, newTransform);
        } else if (operationType == 'q') {
            // Query operation
            int t0, td, x, y;
            cin >> t0 >> td >> x >> y;
            Point result = segTree.query(t0, td, x, y);
            cout << "Query result: (" << result.x << ", " << result.y << ")" << endl;
        }
    }

    return 0;
}
