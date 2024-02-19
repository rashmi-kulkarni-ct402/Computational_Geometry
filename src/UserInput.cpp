#include "../headers/UserInput.h"
#include <iostream>

Utility::UserInput::UserInput() {}

Geometry::GeomVector Utility::UserInput::vector1()
{
    return mVector1;
}

Geometry::GeomVector Utility::UserInput::vector2()
{
    return mVector2;
}

Geometry::GeomVector Utility::UserInput::normalVector()
{
    return mNormalVector;
}

Geometry::Point3D Utility::UserInput::point()
{
    return mPoint;
}

double Utility::UserInput::vectorLength()
{
    return mVectorLength;
}

double Utility::UserInput::scalarValue()
{
    return mScalarValue;
}

LinearAlgebra::Matrix Utility::UserInput::matrix()
{
    return mMatrix;
}

int Utility::UserInput::axisChoice()
{
    return mAxisChoice;
}

void Utility::UserInput::askVector1()
{
    double x, y, z;
    std::cout << "Enter x, y, z coordinates for vector 1: ";
    std::cin >> x >> y >> z;
    Geometry::GeomVector vector(x, y, z);
    mVector1 = vector;
    std::cout << "Vector 1: (" << mVector1.x() << ", " << mVector1.y() << ", " << mVector1.z() << ")" << std::endl;
}

void Utility::UserInput::askVector2()
{
    double x, y, z;
    std::cout << "Enter x, y, z coordinates for vector 2: ";
    std::cin >> x >> y >> z;
    Geometry::GeomVector vector(x, y, z);
    mVector2 = vector;
    std::cout << "Vector 2: (" << mVector2.x() << ", " << mVector2.y() << ", " << mVector2.z() << ")" << std::endl;
}

void Utility::UserInput::askNormalVector()
{
    double x, y, z;
    std::cout << "Enter x, y, z coordinates for normal vector of plane: ";
    std::cin >> x >> y >> z;
    Geometry::GeomVector vector(x, y, z);
    mNormalVector = vector;
    std::cout << "Normal vector: (" << mVector2.x() << ", " << mVector2.y() << ", " << mVector2.z() << ")" << std::endl;
}

void Utility::UserInput::askPoint()
{
    double pX, pY, pZ;
    std::cout << "Enter the coordinates of a point on the plane: ";
    std::cin >> pX >> pY >> pZ;
    Geometry::Point3D point(pX, pY, pZ);
    mPoint = point;
    std::cout << "Point: (" << point.x() << ", " << point.y() << ", " << point.z() << ")" << std::endl;
}

void Utility::UserInput::askVectorLength()
{
    double length;
    std::cout << "Enter the desired length: ";
    std::cin >> length;
    mVectorLength = length;
}

void Utility::UserInput::askScalarValue()
{
    double scalarValue;
    std::cout << "Enter a scalar value: ";
    std::cin >> scalarValue;
    mScalarValue = scalarValue;
}

void Utility::UserInput::askMatrix()
{
    double a, b, c, d, e, f, g, h, i;
    std::cout << "Enter the elements of the 3 x 3 matrix: ";
    std::cin >> a >> b >> c >> d >> e >> f >> g >> h >> i;
    LinearAlgebra::Matrix matrix(a, b, c, d, e, f, g, h, i);
    mMatrix = matrix;
}

void Utility::UserInput::askAxisChoice()
{
    std::cout << "Select axis (0 --> X, 1 --> Y, 2 --> Z): ";
    int axisChoice;
    std::cin >> axisChoice;
    mAxisChoice = axisChoice;
}

Utility::UserInput::~UserInput() {}