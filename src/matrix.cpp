#include "../include/matrix.hpp"

#define MOD 100000000

Point Point::linear_transf(const Matrix matrix, const Point A)
{
    Point result;
    result.x = (matrix.values[0][0] * A.x) + (matrix.values[0][1] * A.y); 
    result.y = (matrix.values[1][0] * A.x) + (matrix.values[1][1] * A.y);
    return result;
}

Matrix Matrix::multiply_matrices(const Matrix matrix1, const Matrix matrix2){
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