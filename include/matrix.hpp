struct Matrix 
{
    int values[2][2];
};

struct Identity_Matrix 
{
    Matrix identity;

    Identity_Matrix()
    {
        identity.values[0][0] = 1;
        identity.values[0][1] = 0;
        identity.values[1][0] = 0;
        identity.values[1][1] = 1;
    }
};

struct Point {
    int x, y;

    Point linear_transf(const Matrix matrix, const Point A);
};