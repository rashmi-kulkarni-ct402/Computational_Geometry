#include "../headers/VectorContainer.h"

std::vector<Geometry::GeomVector> Utility::VectorContainer::vectorList() const
{
    return mVectorList;
}

void Utility::VectorContainer::addVectorToVectorContainer(const Geometry::GeomVector &vector)
{
    mVectorList.push_back(vector);
}
