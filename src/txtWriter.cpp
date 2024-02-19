#include "../headers/TxtWriter.h"
#include <iostream>
#include <fstream>

void Plotting::TxtWriter::write(const std::string &filePath, const std::vector<Geometry::GeomVector> &vectors)
{
    // creating an output file stream
    std::ofstream outputFile(filePath);

    // checking for file opening error
    if (!outputFile.is_open())
    {
        std::cout << "Error opening file: " << filePath << std::endl;
        return;
    }

    // iterating each vector in the input vector list to write origin (0, 0, 0) and vector coordinates to the file
    for (const auto &vector : vectors)
    {
        outputFile << Geometry::Point3D().x() << " " << Geometry::Point3D().y() << " " << Geometry::Point3D().z() << std::endl;
        outputFile << vector.x() << " " << vector.y() << " " << vector.z() << std::endl;
    }
    // closing the file
    outputFile.close();
}
