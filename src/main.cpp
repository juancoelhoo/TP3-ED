#include <iostream>
#include "../include/SegTree.hpp"

int main() {
    int n, q;
    cin >> n >> q;

    // Create a SegTree with size n
    SegTree segTree(n);

    Point queryResults[q];
    int resultIndex = 0;

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
            queryResults[resultIndex].x = result.x;
            queryResults[resultIndex].y = result.y;
            resultIndex++;
        }
    }

    // Print all query results
    for (int i = 0; i < resultIndex; ++i) {
        cout << queryResults[i].x << " " << queryResults[i].y << endl;
    }

    return 0;
}
