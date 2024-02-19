#pragma once
#include "GeomVector.h"
#include "Point3D.h"
#include "Matrix.h"

namespace Utility
{
    class UserInput
    {
    public:
        UserInput();

        Geometry::GeomVector vector1();
        Geometry::GeomVector vector2();
        Geometry::GeomVector normalVector();
        Geometry::Point3D point();
        double vectorLength();
        double scalarValue();
        LinearAlgebra::Matrix matrix();
        int axisChoice();

        void askVector1();
        void askVector2();
        void askNormalVector();
        void askPoint();
        void askVectorLength();
        void askScalarValue();
        void askMatrix();
        void askAxisChoice();

        ~UserInput();

    private:
        Geometry::GeomVector mVector1;
        Geometry::GeomVector mVector2;
        Geometry::GeomVector mNormalVector;
        Geometry::Point3D mPoint;
        double mVectorLength;
        double mScalarValue;
        LinearAlgebra::Matrix mMatrix;
        int mAxisChoice;
    };
}