#pragma once
#include "GeomVector.h"
// #include "Point3D.h"

namespace Geometry
{
    class Plane
    {
    public:
        Plane();
        Plane(const Geometry::GeomVector &normal, const Geometry::Point3D &pointOnPlane);

        GeomVector normal() const;
        Point3D pointOnPlane() const;

        ~Plane();

    private:
        GeomVector mNormal;
        Point3D mPointOnPlane;
    };
}