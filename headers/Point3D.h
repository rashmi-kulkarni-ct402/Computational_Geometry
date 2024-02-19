#pragma once
namespace Geometry
{
    class Point3D
    {
    public:
        Point3D();
        Point3D(double inX, double inY, double inZ);

        double x() const;
        double y() const;
        double z() const;
        void setX(double inX);
        void setY(double inY);
        void setZ(double inZ);

        bool operator<(const Point3D &other) const;

        ~Point3D();

    private:
        double mX;
        double mY;
        double mZ;
    };
}
