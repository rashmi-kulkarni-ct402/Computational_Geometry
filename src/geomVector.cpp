#include <iostream>
#include "../headers/GeomVector.h"
#include "../headers/Plane.h"
#include <cmath>

Geometry::GeomVector::GeomVector() : Point3D(0, 0, 0) {}
Geometry::GeomVector::GeomVector(double inX, double inY, double inZ) : Point3D(inX, inY, inZ) {}
Geometry::GeomVector::GeomVector(const Point3D &point) : Point3D(point) {}

// checks if two vectors are equal
bool Geometry::GeomVector::operator==(const GeomVector &otherVector) const
{
    return x() == otherVector.x() && y() == otherVector.y() && z() == otherVector.z();
}

// subtract operator
Geometry::GeomVector Geometry::GeomVector::operator-(const GeomVector &otherVector) const
{
    return Geometry::GeomVector(x() - otherVector.x(), y() - otherVector.y(), z() - otherVector.z());
}

// calculates magnitude of a vector
double Geometry::GeomVector::magnitude() const
{
    return std::sqrt(x() * x() + y() * y() + z() * z());
}

// normalizes a vector
Geometry::GeomVector Geometry::GeomVector::normalize() const
{
    double vectorMagnitude = magnitude();

    if (vectorMagnitude != 0)
    {
        return GeomVector(x() / vectorMagnitude, y() / vectorMagnitude, z() / vectorMagnitude);
    }
    else
    {
        // return zero vector
        return GeomVector();
    }
}

// sets vector length
Geometry::GeomVector Geometry::GeomVector::setVectorLength(double length)
{
    GeomVector normalized = normalize();
    return normalized.multiplyScalar(length);
}

// adds a scalar value to vector
Geometry::GeomVector Geometry::GeomVector::addScalar(double scalar) const
{
    return Geometry::GeomVector(Point3D::x() + scalar, Point3D::y() + scalar, Point3D::z() + scalar);
}

// substracts a scalar value from vector
Geometry::GeomVector Geometry::GeomVector::subtractScalar(double scalar) const
{
    return Geometry::GeomVector(Point3D::x() - scalar, Point3D::y() - scalar, Point3D::z() - scalar);
}

// multiplies vector by a scalar value
Geometry::GeomVector Geometry::GeomVector::multiplyScalar(double scalar) const
{
    return Geometry::GeomVector(Point3D::x() * scalar, Point3D::y() * scalar, Point3D::z() * scalar);
}

// divides vector by a scalar value
Geometry::GeomVector Geometry::GeomVector::divideScalar(double scalar) const
{
    if (scalar != 0)
    {
        return Geometry::GeomVector(Point3D::x() / scalar, Point3D::y() / scalar, Point3D::z() / scalar);
    }
    else
    {
        std::cerr << "Division by zero not possible!" << std::endl;
        return GeomVector();
    }
}

// adds a vector to current vector(this)
Geometry::GeomVector Geometry::GeomVector::addVector(const GeomVector &otherVector) const
{
    return Geometry::GeomVector(Point3D::x() + otherVector.x(), Point3D::y() + otherVector.y(), Point3D::z() + otherVector.z());
}

// calculates dot product of two vectors
double Geometry::GeomVector::dotProduct(const GeomVector &otherVector) const
{
    return x() * otherVector.x() + y() * otherVector.y() + z() * otherVector.z();
}

// calculates cross product of two vectors
Geometry::GeomVector Geometry::GeomVector::crossProduct(const GeomVector &otherVector) const
{
    double newX = y() * otherVector.z() - z() * otherVector.y();
    double newY = z() * otherVector.x() - x() * otherVector.z();
    double newZ = x() * otherVector.y() - y() * otherVector.x();
    return GeomVector(newX, newY, newZ);
}

// calculates direction cosines
std::tuple<double, double, double> Geometry::GeomVector::directionCosines() const
{
    double magnitudeResult = magnitude();

    // check if magnitude is zero value
    if (magnitudeResult == 0)
    {
        return std::make_tuple(0, 0, 0);
    }

    double cosAlpha = std::acos(x() / magnitudeResult) * (180.0 / M_PI);
    double cosBeta = std::acos(y() / magnitudeResult) * (180.0 / M_PI);
    double cosGamma = std::acos(z() / magnitudeResult) * (180.0 / M_PI);

    std::cout << "alpha :" << cosAlpha << ", beta :" << cosBeta << ", gamma :" << cosGamma << std::endl;
    return std::make_tuple(cosAlpha, cosBeta, cosGamma);
}

// multiplies vector by a matrix
Geometry::GeomVector Geometry::GeomVector::multiplyMatrix(const LinearAlgebra::Matrix &matrix) const
{
    double resultX = x() * matrix.element(0, 0) + y() * matrix.element(1, 0) + z() * matrix.element(2, 0);
    double resultY = x() * matrix.element(0, 1) + y() * matrix.element(1, 1) + z() * matrix.element(2, 1);
    double resultZ = x() * matrix.element(0, 2) + y() * matrix.element(1, 2) + z() * matrix.element(2, 2);
    return Geometry::GeomVector(resultX, resultY, resultZ);
}

// calculates distance between two vectors
double Geometry::GeomVector::distanceBetweenVectors(const GeomVector &otherVector) const
{
    double dx = x() - otherVector.x();
    double dy = y() - otherVector.y();
    double dz = z() - otherVector.z();
    return std::sqrt(dx * dx + dy * dy + dz * dz);
}

// calculates distance between vector and plane
double Geometry::GeomVector::distanceBetweenVectorAndPlane(const Geometry::Plane &plane) const
{
    double dX = x() - plane.pointOnPlane().x();
    double dY = y() - plane.pointOnPlane().y();
    double dZ = z() - plane.pointOnPlane().z();
    double dotProduct = dX * plane.normal().x() + dY * plane.normal().y() + dZ * plane.normal().z();
    double distance = std::abs(dotProduct) / plane.normal().magnitude();
    return distance;
}

// calculated angle between 2 vectors
double Geometry::GeomVector::angleBetweenVectors(const Geometry::GeomVector &other) const
{
    double dotProductResult = dotProduct(other);
    double magnitudeResult = magnitude() * other.magnitude();
    double angleRadians = acos(dotProductResult / magnitudeResult);
    // converting radians to degrees
    return angleRadians * (180.0 / M_PI);
}

// calculates angle between vector and axis
double Geometry::GeomVector::angleBetweenVectorAndAxis(int axis) const
{
    double dotProductResult = 0.0;
    double vectorMagnitude = magnitude();
    double axisMagnitude = 1.0;

    // x-axis
    if (axis == 0)
    {
        if (vectorMagnitude == 0.0)
        {
            return 0.0;
        }
        dotProductResult = x();
    }
    // y-axis
    else if (axis == 1)
    {
        if (vectorMagnitude == 0.0)
        {
            return 0.0;
        }
        dotProductResult = y();
    }
    // z-axis
    else if (axis == 2)
    {
        if (vectorMagnitude == 0.0)
        {
            return 0.0;
        }
        dotProductResult = z();
    }

    double angleRadians = std::acos(dotProductResult / (vectorMagnitude * axisMagnitude));
    // converting radians to degrees
    return angleRadians * (180.0 / M_PI);
}

// calculates angle between vector and plane
double Geometry::GeomVector::angleBetweenVectorAndPlane(const Geometry::Plane &plane) const
{
    // dot product (vector and plane's normal)
    double dotProductResult = dotProduct(plane.normal());
    // magnitude of vector and plane's normal
    double vectorMagnitude = magnitude();
    double normalMagnitude = plane.normal().magnitude();

    double angleRadians = std::acos(dotProductResult / (vectorMagnitude * normalMagnitude));
    // converting radians to degrees
    return angleRadians * (180.0 / M_PI);
}

// projection of vector on another vector
Geometry::GeomVector Geometry::GeomVector::projectionOnVector(const GeomVector &otherVector) const
{
    double dotProductResult = dotProduct(otherVector);
    double denominator = otherVector.dotProduct(otherVector);

    if (std::abs(denominator) == 0)
    {
        return GeomVector();
    }

    double scalarValue = dotProductResult / denominator;
    return otherVector.multiplyScalar(scalarValue);
}

// projection of vector on plane
Geometry::GeomVector Geometry::GeomVector::projectVectorOnPlane(const GeomVector &planeNormal) const
{
    GeomVector projection = projectionOnVector(planeNormal);
    GeomVector result = *this - projection;
    return result;
}
