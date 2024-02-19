#pragma once
#include <vector>
#include "Vector3D.h"

namespace Utility
{
    class VectorContainer
    {
    public:
        VectorContainer();

        std::vector<Geometry::Vector3D> vectorList() const;
        void addVectorToVectorContainer(const Geometry::Vector3D &vector);

        ~VectorContainer();

    private:
        std::vector<Geometry::Vector3D> mVectorList;
    };
}
