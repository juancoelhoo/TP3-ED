#include "../include/segTree.hpp"

int main() {
    unsigned int n, q;
    cin >> n >> q;

    // Create a SegTree with size n
    segTree segTree(n);

    Point results[q];   
    int resultIndex = 0;  

    for (int i = 0; i < q; ++i) {
        char operationType;
        cin >> operationType;

        if (operationType == 'u') {
            int a;
            cin >> a;
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 2; ++k) {
                    cin >> segTree.transforms[a].values[j][k];
                }
            }
            segTree.update(1, 0, n - 1, a, segTree.transforms[a]);
        } else if (operationType == 'q') {
            int t0, td, x, y;
            cin >> t0 >> td >> x >> y;
            Matrix M_res = segTree.query(1, 0, n - 1, t0, td);
            Point point = {x, y};
            Point result = point.linear_transf(M_res, point);
            results[resultIndex++] = result;
        }
    }

    // Print the results after processing all operations
    for (int i = 0; i < resultIndex; ++i) {
        cout << results[i].x << " " << results[i].y << "\n";
    }

    return 0;
}
