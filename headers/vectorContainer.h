#pragma once
#include <vector>
#include "GeomVector.h"

namespace Utility
{
    class VectorContainer
    {
    public:
        VectorContainer() = default;
        ~VectorContainer() = default;

        std::vector<Geometry::GeomVector> vectorList() const;
        void addVectorToVectorContainer(const Geometry::GeomVector &vector);

    private:
        std::vector<Geometry::GeomVector> mVectorList;
    };
}
