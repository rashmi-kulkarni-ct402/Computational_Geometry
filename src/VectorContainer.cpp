#include "../headers/VectorContainer.h"

Utility::VectorContainer::VectorContainer() {}

std::vector<Geometry::Vector3D> Utility::VectorContainer::vectorList() const
{
    return mVectorList;
}

void Utility::VectorContainer::addVectorToVectorContainer(const Geometry::Vector3D &vector)
{
    mVectorList.push_back(vector);
}

Utility::VectorContainer::~VectorContainer() {}