#pragma once
#include "GeomVector.h"
#include "Point3D.h"
#include "Matrix.h"

namespace Utility
{
    class UserInput
    {
    public:
        UserInput() = default;
        ~UserInput() = default;

        Geometry::GeomVector vector1() const;
        Geometry::GeomVector vector2() const;
        Geometry::GeomVector normalVector() const;
        Geometry::Point3D point() const;
        double vectorLength() const;
        double scalarValue() const;
        LinearAlgebra::Matrix matrix() const;
        int axisChoice() const;

        void askVector1();
        void askVector2();
        void askNormalVector();
        void askPoint();
        void askVectorLength();
        void askScalarValue();
        void askMatrix();
        void askAxisChoice();

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