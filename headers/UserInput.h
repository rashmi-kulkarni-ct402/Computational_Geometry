#pragma once
#include "Vector3D.h"
#include "Point3D.h"
#include "Matrix.h"

namespace Utility
{
    class UserInput
    {
    public:
        UserInput();

        Geometry::Vector3D vector1();
        Geometry::Vector3D vector2();
        Geometry::Vector3D normalVector();
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
        Geometry::Vector3D mVector1;
        Geometry::Vector3D mVector2;
        Geometry::Vector3D mNormalVector;
        Geometry::Point3D mPoint;
        double mVectorLength;
        double mScalarValue;
        LinearAlgebra::Matrix mMatrix;
        int mAxisChoice;
    };
}