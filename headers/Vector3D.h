#pragma once
#include "Point3D.h"
#include "Matrix.h"

namespace Geometry
{
    class Plane;
    class Vector3D : public Point3D
    {
    public:
        Vector3D();
        Vector3D(double inX, double inY, double inZ);
        Vector3D(const Geometry::Point3D &point);

        bool operator==(const Vector3D &otherVector) const;    // equality operator
        Vector3D operator-(const Vector3D &otherVector) const; // subtraction operator

        double magnitude() const;                // vector magnitude
        Vector3D normalize() const;              // normalize vector
        Vector3D setVectorLength(double length); // set vector length

        Vector3D addScalar(double scalar) const;      // add scalar to vector
        Vector3D subtractScalar(double scalar) const; // subtract scalar from vector
        Vector3D multiplyScalar(double scalar) const; // multiply scalar with vector
        Vector3D divideScalar(double scalar) const;   // divide vector by scalar

        Vector3D addVector(const Vector3D &otherVector) const;              // add vector to current vector (this)
        double dotProduct(const Vector3D &otherVector) const;               // vector dot product
        Vector3D crossProduct(const Vector3D &otherVector) const;           // vector cross product
        void directionCosines() const;                                      // direction cosines
        Vector3D multiplyMatrix(const LinearAlgebra::Matrix &matrix) const; // vector-matrix multiplication

        double distanceBetweenVectors(const Vector3D &otherVector) const;         // distance between two vectors
        double distanceBetweenVectorAndPlane(const Geometry::Plane &plane) const; // distance between vector and plane

        double angleBetweenVectors(const Vector3D &other) const;     // angle between 2 vectors
        double angleBetweenVectorAndAxis(int axis) const;            // angle between vector & Plane
        double angleBetweenVectorAndPlane(const Plane &plane) const; // angle between vector & Plane

        Vector3D projectionOnVector(const Vector3D &otherVector) const;                           // projection of vector on another vector
        Vector3D projectVectorOnPlane(const Vector3D &vector, const Vector3D &planeNormal) const; // projection of vector on plane

        ~Vector3D();
    };
}