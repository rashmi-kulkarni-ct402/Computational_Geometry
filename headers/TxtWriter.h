#pragma once
#include <string>
#include <vector>
#include "GeomVector.h"

namespace Plotting
{
    class TxtWriter
    {
    public:
        TxtWriter();

        void write(const std::string &filePath, const std::vector<Geometry::GeomVector> &vectors);
        ~TxtWriter();
    };
}