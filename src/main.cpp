#include "../include/segTree.hpp"
#include <stdexcept>

int main() {
    unsigned int n, q;
    std::cin >> n >> q;

    segTree segTree(n);

    Point results[q];   
    int resultIndex = 0;  

    for (unsigned int i = 0; i < q; ++i) {
        char operationType;
        std::cin >> operationType;

        if (operationType == 'u') {
            int a;
            std::cin >> a;
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 2; ++k) {
                    std::cin >> segTree.linear_transformations[a].values[j][k];
                }
            }
            segTree.update(1, 0, n - 1, a, segTree.linear_transformations[a]);
        } else if (operationType == 'q') {
            int t0, td;
            unsigned long int x, y;
            std::cin >> t0 >> td >> x >> y;
            Matrix M_res = segTree.query(1, 0, n - 1, t0, td);
            Point point = {x, y};
            Point result = point.linear_transf(M_res, point);
            results[resultIndex++] = result;
        } else {
            throw std::invalid_argument("Invalid operationType: " + std::to_string(operationType));
        }
    }

    // Print the results after processing all operations
    for (int i = 0; i < resultIndex; ++i) {
        std::cout << results[i].x % MOD << " " << results[i].y % MOD << "\n";
    }

    return 0;
}
