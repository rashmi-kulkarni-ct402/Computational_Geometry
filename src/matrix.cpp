#include "../headers/Matrix.h"
#include <iostream>

LinearAlgebra::Matrix::Matrix(double a, double b, double c, double d, double e, double f, double g, double h, double i)
{
    matrix[0][0] = a;
    matrix[0][1] = b;
    matrix[0][2] = c;
    matrix[1][0] = d;
    matrix[1][1] = e;
    matrix[1][2] = f;
    matrix[2][0] = g;
    matrix[2][1] = h;
    matrix[2][2] = i;
}

double LinearAlgebra::Matrix::element(int row, int col) const
{
    return matrix[row][col];
}
