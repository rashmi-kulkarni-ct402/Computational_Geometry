#pragma once
#include <string>
#include <vector>
#include "Vector3D.h"

namespace Plotting
{
    class TxtWriter
    {
    public:
        TxtWriter();

        void write(const std::string &filePath, const std::vector<Geometry::Vector3D> &vectors);
        ~TxtWriter();
    };
}