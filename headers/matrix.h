#pragma once

namespace LinearAlgebra
{
    class Matrix
    {
    public:
        Matrix() = default;
        Matrix(double inA, double inB, double inC, double inD, double inE, double inF, double inG, double inH, double inI);
        ~Matrix() = default;

        double element(int inRow, int inCol) const;

    private:
        double mMatrix[3][3];
    };
}