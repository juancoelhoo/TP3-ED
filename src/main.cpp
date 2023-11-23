#include <iostream>
#include "../include/SegTree.hpp"

int main() {
    int n, q;
    cin >> n >> q;

    // Create a SegTree with size n
    SegTree segTree(n);

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
