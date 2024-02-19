#include "../headers/TxtWriter.h"
#include <iostream>
#include <fstream>

Plotting::TxtWriter::TxtWriter() {}

void Plotting::TxtWriter::write(const std::string &filePath, const std::vector<Geometry::Vector3D> &vectors)
{
    std::ofstream outputFile(filePath);
    if (!outputFile.is_open())
    {
        std::cout << "Error opening file: " << filePath << std::endl;
        return;
    }

    for (const auto &vector : vectors)
    {
        outputFile << "0 0 0" << std::endl;
        outputFile << vector.x() << " " << vector.y() << " " << vector.z() << std::endl;
    }

    outputFile.close();
}

Plotting::TxtWriter::~TxtWriter() {}
