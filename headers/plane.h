#pragma once
#include "GeomVector.h"

namespace Geometry
{
    class Plane
    {
    public:
        Plane();
        Plane(const Geometry::GeomVector &normal, const Geometry::Point3D &pointOnPlane);
        ~Plane() = default;

        GeomVector normal() const;
        Point3D pointOnPlane() const;

    private:
        GeomVector mNormal;
        Point3D mPointOnPlane;
    };
}