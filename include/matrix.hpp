#ifndef MATRIX_HPP
#define MATRIX_HPP

#define MOD 100000000

// Represents a 2x2 matrix
struct Matrix 
{
    unsigned long int values[2][2];

    // Multiply 2x2 matrices 
    Matrix multiply_matrices(const Matrix matrix1, const Matrix matrix2);
};

// Represents an identity matrix, which is a special matrix that doesn't change a vector when multiplied
struct Identity_Matrix 
{
    Matrix identity;

    // Constructor to initialize the identity matrix
    Identity_Matrix()
    {
        // Set diagonal elements to 1, and off-diagonal elements to 0
        identity.values[0][0] = 1;
        identity.values[0][1] = 0;
        identity.values[1][0] = 0;
        identity.values[1][1] = 1;
    }
};

// Represents a 2D point
struct Point {
    unsigned long int x, y;

    // Function for performing a linear transformation on a Point using a Matrix
    Point linear_transf(const Matrix matrix, const Point A);
};

#endif // MATRIX_HPP
