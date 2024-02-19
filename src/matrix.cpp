#include "../headers/Matrix.h"
#include <iostream>

LinearAlgebra::Matrix::Matrix(double inA, double inB, double inC, double inD, double inE, double inF, double inG, double inH, double inI)
{
    mMatrix[0][0] = inA;
    mMatrix[0][1] = inB;
    mMatrix[0][2] = inC;
    mMatrix[1][0] = inD;
    mMatrix[1][1] = inE;
    mMatrix[1][2] = inF;
    mMatrix[2][0] = inG;
    mMatrix[2][1] = inH;
    mMatrix[2][2] = inI;
}

double LinearAlgebra::Matrix::element(int inRow, int inCol) const
{
    return mMatrix[inRow][inCol];
}
