#pragma once
#include "Vector3D.h"
// #include "Point3D.h"

namespace Geometry
{
    class Plane
    {
    public:
        Plane();
        Plane(const Geometry::Vector3D &normal, const Geometry::Point3D &pointOnPlane);

        Vector3D normal() const;
        Point3D pointOnPlane() const;

        ~Plane();

    private:
        Vector3D mNormal;
        Point3D mPointOnPlane;
    };
}