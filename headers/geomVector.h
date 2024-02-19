#pragma once
#include "Point3D.h"
#include "Matrix.h"
#include <tuple>

namespace Geometry
{
    class Plane;
    class GeomVector : public Point3D
    {
    public:
        GeomVector();
        GeomVector(double inX, double inY, double inZ);
        GeomVector(const Geometry::Point3D &point);
        ~GeomVector() = default;

        bool operator==(const GeomVector &otherVector) const;      // equality operator
        GeomVector operator-(const GeomVector &otherVector) const; // subtraction operator

        double magnitude() const;                  // vector magnitude
        GeomVector normalize() const;              // normalize vector
        GeomVector setVectorLength(double length); // set vector length

        GeomVector addScalar(double scalar) const;      // add scalar to vector
        GeomVector subtractScalar(double scalar) const; // subtract scalar from vector
        GeomVector multiplyScalar(double scalar) const; // multiply scalar with vector
        GeomVector divideScalar(double scalar) const;   // divide vector by scalar

        GeomVector addVector(const GeomVector &otherVector) const;            // add vector to current vector (this)
        double dotProduct(const GeomVector &otherVector) const;               // vector dot product
        GeomVector crossProduct(const GeomVector &otherVector) const;         // vector cross product
        std::tuple<double, double, double> directionCosines() const;          // direction cosines
        GeomVector multiplyMatrix(const LinearAlgebra::Matrix &matrix) const; // vector-matrix multiplication

        double distanceBetweenVectors(const GeomVector &otherVector) const;       // distance between two vectors
        double distanceBetweenVectorAndPlane(const Geometry::Plane &plane) const; // distance between vector and plane

        double angleBetweenVectors(const GeomVector &other) const;   // angle between 2 vectors
        double angleBetweenVectorAndAxis(int axis) const;            // angle between vector & Plane
        double angleBetweenVectorAndPlane(const Plane &plane) const; // angle between vector & Plane

        GeomVector projectionOnVector(const GeomVector &otherVector) const;   // projection of vector on another vector
        GeomVector projectVectorOnPlane(const GeomVector &planeNormal) const; // projection of vector on plane
    };
}