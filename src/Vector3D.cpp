#include <iostream>
#include "../headers/Vector3D.h"
#include "../headers/Plane.h"
#include <cmath>

Geometry::Vector3D::Vector3D() : Point3D(0, 0, 0) {}
Geometry::Vector3D::Vector3D(double inX, double inY, double inZ) : Point3D(inX, inY, inZ) {}
Geometry::Vector3D::Vector3D(const Point3D &point) : Point3D(point) {}

// checks if two vectors are equal
bool Geometry::Vector3D::operator==(const Vector3D &otherVector) const
{
    return x() == otherVector.x() && y() == otherVector.y() && z() == otherVector.z();
}

// subtract operator
Geometry::Vector3D Geometry::Vector3D::operator-(const Vector3D &otherVector) const
{
    return Geometry::Vector3D(x() - otherVector.x(), y() - otherVector.y(), z() - otherVector.z());
}

// calculates magnitude of a vector
double Geometry::Vector3D::magnitude() const
{
    return std::sqrt(x() * x() + y() * y() + z() * z());
}

// normalizes a vector
Geometry::Vector3D Geometry::Vector3D::normalize() const
{
    double vectorMagnitude = magnitude();
    return Vector3D(x() / vectorMagnitude, y() / vectorMagnitude, z() / vectorMagnitude);
}

// sets vector length
Geometry::Vector3D Geometry::Vector3D::setVectorLength(double length)
{
    Vector3D normalized = normalize();
    Vector3D scaledVector = normalized.multiplyScalar(length);
    setX(scaledVector.x());
    setY(scaledVector.y());
    setZ(scaledVector.z());
    return scaledVector;
}

// adds a scalar value to vector
Geometry::Vector3D Geometry::Vector3D::addScalar(double scalar) const
{
    return Geometry::Vector3D(Point3D::x() + scalar, Point3D::y() + scalar, Point3D::z() + scalar);
}

// substracts a scalar value from vector
Geometry::Vector3D Geometry::Vector3D::subtractScalar(double scalar) const
{
    return Geometry::Vector3D(Point3D::x() - scalar, Point3D::y() - scalar, Point3D::z() - scalar);
}

// multiplies vector by a scalar value
Geometry::Vector3D Geometry::Vector3D::multiplyScalar(double scalar) const
{
    return Geometry::Vector3D(Point3D::x() * scalar, Point3D::y() * scalar, Point3D::z() * scalar);
}

// divides vector by a scalar value
Geometry::Vector3D Geometry::Vector3D::divideScalar(double scalar) const
{
    if (scalar != 0)
    {
        return Geometry::Vector3D(Point3D::x() / scalar, Point3D::y() / scalar, Point3D::z() / scalar);
    }
    else
    {
        std::cout << "Division by zero not possible!" << std::endl;
        return *this;
    }
}

// adds a vector to current vector(this)
Geometry::Vector3D Geometry::Vector3D::addVector(const Vector3D &otherVector) const
{
    return Geometry::Vector3D(Point3D::x() + otherVector.x(), Point3D::y() + otherVector.y(), Point3D::z() + otherVector.z());
}

// calculates dot product of two vectors
double Geometry::Vector3D::dotProduct(const Vector3D &otherVector) const
{
    return x() * otherVector.x() + y() * otherVector.y() + z() * otherVector.z();
}

// calculates cross product of two vectors
Geometry::Vector3D Geometry::Vector3D::crossProduct(const Vector3D &otherVector) const
{
    double newX = y() * otherVector.z() - z() * otherVector.y();
    double newY = z() * otherVector.x() - x() * otherVector.z();
    double newZ = x() * otherVector.y() - y() * otherVector.x();
    return Vector3D(newX, newY, newZ);
}

// calculates direction cosines
void Geometry::Vector3D ::directionCosines() const
{
    double magnitudeResult = magnitude();
    double alpha;
    double beta;
    double gamma;
    // check if magnitude is non-zero value
    if (magnitudeResult != 0.0)
    {
        alpha = std::acos(this->x() / magnitude()) * (180.0 / M_PI);
        beta = std::acos(this->y() / magnitude()) * (180.0 / M_PI);
        gamma = std::acos(this->z() / magnitude()) * (180.0 / M_PI);
    }
    else
    {
        alpha = beta = gamma = 0.0;
    }
    std::cout << "alpha :" << alpha << ", beta :" << beta << ", gamma :" << gamma << std::endl;
}

// multiplies vector by a matrix
Geometry::Vector3D Geometry::Vector3D::multiplyMatrix(const LinearAlgebra::Matrix &matrix) const
{
    double resultX = x() * matrix.element(0, 0) + y() * matrix.element(1, 0) + z() * matrix.element(2, 0);
    double resultY = x() * matrix.element(0, 1) + y() * matrix.element(1, 1) + z() * matrix.element(2, 1);
    double resultZ = x() * matrix.element(0, 2) + y() * matrix.element(1, 2) + z() * matrix.element(2, 2);
    return Geometry::Vector3D(resultX, resultY, resultZ);
}

// calculates distance between two vectors
double Geometry::Vector3D::distanceBetweenVectors(const Vector3D &otherVector) const
{
    double dx = x() - otherVector.x();
    double dy = y() - otherVector.y();
    double dz = z() - otherVector.z();
    return std::sqrt(dx * dx + dy * dy + dz * dz);
}

// calculates distance between vector and plane
double Geometry::Vector3D::distanceBetweenVectorAndPlane(const Geometry::Plane &plane) const
{
    double dX = x() - plane.pointOnPlane().x();
    double dY = y() - plane.pointOnPlane().y();
    double dZ = z() - plane.pointOnPlane().z();
    double dotProduct = dX * plane.normal().x() + dY * plane.normal().y() + dZ * plane.normal().z();
    double distance = std::abs(dotProduct) / plane.normal().magnitude();
    return distance;
}

// calculated angle between 2 vectors
double Geometry::Vector3D::angleBetweenVectors(const Geometry::Vector3D &other) const
{
    double dotProductResult = dotProduct(other);
    double magnitudeResult = magnitude() * other.magnitude();
    std::cout << "1: " << dotProductResult << "2: " << magnitudeResult << std::endl;
    double angleRadians = acos(dotProductResult / magnitudeResult);
    // converting radians to degrees
    return angleRadians * (180.0 / M_PI);
}

// calculates angle between vector and axis
double Geometry::Vector3D::angleBetweenVectorAndAxis(int axis) const
{
    double dotProductResult = 0.0;
    double vectorMagnitude = magnitude();
    double axisMagnitude = 1.0; // Assuming axis is a unit vector

    // x-axis
    if (axis == 0)
    {
        dotProductResult = x();
    }
    // y-axis
    else if (axis == 1)
    {
        dotProductResult = y();
    }
    // z-axis
    else if (axis == 2)
    {
        dotProductResult = z();
    }

    double angleRadians = std::acos(dotProductResult / (vectorMagnitude * axisMagnitude));
    // converting radians to degrees
    return angleRadians * (180.0 / M_PI);
}

// calculates angle between vector and plane
double Geometry::Vector3D::angleBetweenVectorAndPlane(const Geometry::Plane &plane) const
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
Geometry::Vector3D Geometry::Vector3D::projectionOnVector(const Vector3D &otherVector) const
{
    double dotProductResult = dotProduct(otherVector);
    double denominator = otherVector.dotProduct(otherVector);

    if (std::abs(denominator) == 0)
    {
        return Vector3D();
    }

    double scalarValue = dotProductResult / denominator;
    return otherVector.multiplyScalar(scalarValue);
}

// projection of vector on plane
Geometry::Vector3D Geometry::Vector3D::projectVectorOnPlane(const Vector3D &vector, const Vector3D &planeNormal) const
{
    Vector3D projection = vector.projectionOnVector(planeNormal);
    Vector3D result = vector - projection;
    return result;
}

// destructor
Geometry::Vector3D::~Vector3D()
{
}