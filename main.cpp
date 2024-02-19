#include <iostream>
#include "./headers/Vector3D.h"
#include "./headers/Plane.h"
#include "./headers/UserInput.h"
#include "./headers/VectorContainer.h"
#include "./headers/TxtWriter.h"
#include <vector>
#include <string>

int main()
{
    int choice;
    Utility::VectorContainer vectorContainer;
    Plotting::TxtWriter txtWriter;
    Utility::UserInput userInput;
    std::string outputFilePath = "output/vectors3D.txt";
    userInput.askVector1();
    std::cout << "---------------------------------------------------" << std::endl;

    std::vector<Geometry::Vector3D> vectorsList;

    do
    {
        std::cout << "1. Equality check of two vectors" << std::endl
                  << "2. Magnitude of vector" << std::endl
                  << "3. Normalization of vector" << std::endl
                  << "4. Set Vector Length" << std::endl
                  << "5. Add scalar value to vector" << std::endl
                  << "6. Subtract scalar value from vector" << std::endl
                  << "7. Multiply vector with scalar value" << std::endl
                  << "8. Divide vector by scalar value" << std::endl
                  << "9. Add two vectors" << std::endl
                  << "10. Dot-product of 2 vectors" << std::endl
                  << "11. Crosst-product of 2 vectors" << std::endl
                  << "12. Direction cosines" << std::endl
                  << "13. Multiply vector with matrix" << std::endl
                  << "14. Distance between two vectors" << std::endl
                  << "15. Distance between vector and plane" << std::endl
                  << "16. Angle between two vectors" << std::endl
                  << "17. Angle between vector and axis" << std::endl
                  << "18. Angle between vector and plane" << std::endl
                  << "19. Projection on another vector" << std::endl
                  << "20. projection on plane" << std::endl;
        std::cout << "---------------------------------------------------" << std::endl;

        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cout << std::endl;

        switch (choice)
        {
        case 1:
        {
            // check equality of two vectors
            userInput.askVector2();
            if (userInput.vector1() == userInput.vector2())
            {
                std::cout << "Vector 1 and vector 2 are equal" << std::endl;
            }
            else
            {
                std::cout << "Vector 1 and vector 2 are not equal" << std::endl;
            }
            std::cout << "---------------------------------------------------" << std::endl;
        }
        break;

        case 2:
        {
            // calculate magnitude of a vector
            double vectorMagnitude = userInput.vector1().magnitude();
            std::cout << "Magnitude of vector: " << vectorMagnitude << std::endl;
            // adding vector to VectorContainer
            vectorContainer.addVectorToVectorContainer(userInput.vector1());
            txtWriter.write(outputFilePath, vectorContainer.vectorList());
            std::cout << "---------------------------------------------------" << std::endl;
        }
        break;

        case 3:
        {
            // normalization of a vector
            Geometry::Vector3D normalizedVector = userInput.vector1().normalize();
            std::cout << "Normalized vector: (" << normalizedVector.x() << ", " << normalizedVector.y() << ", " << normalizedVector.z() << ")" << std::endl;
            std::cout << "maginutde" << normalizedVector.magnitude() << std::endl;
            vectorContainer.addVectorToVectorContainer(normalizedVector);
            txtWriter.write(outputFilePath, vectorContainer.vectorList());
            std::cout << "---------------------------------------------------" << std::endl;
        }
        break;

        case 4:
        {
            // set vector length
            userInput.askVectorLength();
            std::cout << "Length of vector 1 (Before): " << userInput.vector1().magnitude() << std::endl;
            Geometry::Vector3D newVector = userInput.vector1().setVectorLength(userInput.vectorLength());
            std::cout << "Length of vector 1 (After): " << newVector.magnitude() << std::endl;
            vectorContainer.addVectorToVectorContainer(newVector);
            txtWriter.write(outputFilePath, vectorContainer.vectorList());
            std::cout << "---------------------------------------------------" << std::endl;
        }
        break;

        case 5:
        {
            // add scalar value to vector
            userInput.askScalarValue();
            Geometry::Vector3D resultVector = userInput.vector1().addScalar(userInput.scalarValue());
            std::cout << "Resulting vector after adding scalar value: (" << resultVector.x() << ", " << resultVector.y() << ", " << resultVector.z() << ")" << std::endl;
            vectorContainer.addVectorToVectorContainer(resultVector);
            txtWriter.write(outputFilePath, vectorContainer.vectorList());
            std::cout << "---------------------------------------------------" << std::endl;
        }
        break;

        case 6:
        {
            // subtract scalar value from vector
            userInput.askScalarValue();
            Geometry::Vector3D resultVector = userInput.vector1().subtractScalar(userInput.scalarValue());
            std::cout << "Resulting vector after subtracting scalar value: (" << resultVector.x() << ", " << resultVector.y() << ", " << resultVector.z() << ")" << std::endl;
            vectorContainer.addVectorToVectorContainer(resultVector);
            txtWriter.write(outputFilePath, vectorContainer.vectorList());
            std::cout << "---------------------------------------------------" << std::endl;
        }
        break;

        case 7:
        {
            // multiply vector with scalar value
            userInput.askScalarValue();
            Geometry::Vector3D resultVector = userInput.vector1().multiplyScalar(userInput.scalarValue());
            std::cout << "Resulting vector after multiplying by scalar value: (" << resultVector.x() << ", " << resultVector.y() << ", " << resultVector.z() << ")" << std::endl;
            vectorContainer.addVectorToVectorContainer(resultVector);
            txtWriter.write(outputFilePath, vectorContainer.vectorList());
            std::cout << "---------------------------------------------------" << std::endl;
        }
        break;

        case 8:
        {
            // divide vector by scalar value
            userInput.askScalarValue();
            Geometry::Vector3D resultVector = userInput.vector1().divideScalar(userInput.scalarValue());
            std::cout << "Resulting vector after dividing by scalar value: (" << resultVector.x() << ", " << resultVector.y() << ", " << resultVector.z() << ")" << std::endl;
            vectorContainer.addVectorToVectorContainer(resultVector);
            txtWriter.write(outputFilePath, vectorContainer.vectorList());
            std::cout << "---------------------------------------------------" << std::endl;
        }
        break;

        case 9:
        {
            // add a vector to this vector
            userInput.askVector2();
            Geometry::Vector3D resultVector = userInput.vector1().addVector(userInput.vector2());
            std::cout << "Vector after adding another vector: (" << resultVector.x() << ", " << resultVector.y() << ", " << resultVector.z() << ")" << std::endl;
            vectorContainer.addVectorToVectorContainer(resultVector);
            vectorContainer.addVectorToVectorContainer(userInput.vector1());
            vectorContainer.addVectorToVectorContainer(userInput.vector2());
            txtWriter.write(outputFilePath, vectorContainer.vectorList());
            std::cout << "---------------------------------------------------" << std::endl;
        }
        break;

        case 10:
        {
            // calculate dot product of two vectors
            userInput.askVector2();
            double resultVector = userInput.vector1().dotProduct(userInput.vector2());
            std::cout << "Dot product of vector 1 and vector 2: " << resultVector << std::endl;
            std::cout << "---------------------------------------------------" << std::endl;
        }
        break;

        case 11:
        {
            // calculate cross product of two vectors
            userInput.askVector2();
            Geometry::Vector3D resultVector = userInput.vector1().crossProduct(userInput.vector2());
            std::cout << "Cross product: (" << resultVector.x() << ", " << resultVector.y() << ", " << resultVector.z() << ")" << std::endl;
            vectorContainer.addVectorToVectorContainer(resultVector);
            txtWriter.write(outputFilePath, vectorContainer.vectorList());
            std::cout << "---------------------------------------------------" << std::endl;
        }
        break;

        case 12:
        {
            // calculate direction cosines
            userInput.vector1().directionCosines();
            std::cout << "---------------------------------------------------" << std::endl;
        }
        break;

        case 13:
        {
            // multiply vector with a matrix
            userInput.askMatrix();
            Geometry::Vector3D resultVector = userInput.vector1().multiplyMatrix(userInput.matrix());
            std::cout << "Resulting vector after multiplying with the matrix: (" << resultVector.x() << ", " << resultVector.y() << ", " << resultVector.z() << ")" << std::endl;
            vectorContainer.addVectorToVectorContainer(userInput.vector1());
            vectorContainer.addVectorToVectorContainer(resultVector);
            txtWriter.write(outputFilePath, vectorContainer.vectorList());
            std::cout << "---------------------------------------------------" << std::endl;
        }
        break;

        case 14:
        {
            // calculate distance between 2 vectors
            userInput.askVector1();
            userInput.askVector2();
            double distance = userInput.vector1().distanceBetweenVectors(userInput.vector2());
            std::cout << "Distance between vector 1 and 2: " << distance << std::endl;
            std::cout << "---------------------------------------------------" << std::endl;
        }
        break;

        case 15:
        {
            // calculate distance between vector and plane
            userInput.askNormalVector();
            userInput.askPoint();
            Geometry::Plane plane(userInput.normalVector(), userInput.point());
            double distance = userInput.vector1().distanceBetweenVectorAndPlane(plane);
            std::cout << "Distance between vector and plane: " << distance << std::endl;
            std::cout << "---------------------------------------------------" << std::endl;
        }
        break;

        case 16:
        {
            // calculate angle between 2 vectors
            userInput.askVector2();
            double angle = userInput.vector1().angleBetweenVectors(userInput.vector2());
            std::cout << "Angle between vectors: " << angle << " degrees" << std::endl;
            std::cout << "---------------------------------------------------" << std::endl;
        }
        break;

        case 17:
        {
            // angle between vector and axis
            userInput.askAxisChoice();
            double angle = userInput.vector1().angleBetweenVectorAndAxis(userInput.axisChoice());
            std::cout << "Angle between vector and axis: " << angle << " degrees" << std::endl;
            std::cout << "---------------------------------------------------" << std::endl;
        }
        break;

        case 18:
        {
            // angle between vector and plane
            userInput.askNormalVector();
            userInput.askPoint();
            Geometry::Plane plane(userInput.normalVector(), userInput.point());
            double angle = userInput.vector1().angleBetweenVectorAndPlane(plane);
            std::cout << "Angle between vector and plane: " << angle << " degrees" << std::endl;
            std::cout << "---------------------------------------------------" << std::endl;
        }
        break;

        case 19:
        {
            // projection of vector on another vector
            userInput.askVector2();
            Geometry::Vector3D resultVector = userInput.vector1().projectionOnVector(userInput.vector2());
            std::cout << "Projection of v1 onto v2: (" << resultVector.x() << ", " << resultVector.y() << ", " << resultVector.z() << ")" << std::endl;
            vectorContainer.addVectorToVectorContainer(userInput.vector1());
            vectorContainer.addVectorToVectorContainer(resultVector);
            txtWriter.write(outputFilePath, vectorContainer.vectorList());
            std::cout << "---------------------------------------------------" << std::endl;
        }
        break;

        case 20:
        {
            // projection on plane
            userInput.askNormalVector();
            Geometry::Vector3D resultVector = userInput.vector1().projectVectorOnPlane(userInput.vector1(), userInput.normalVector());
            std::cout << "Projection on plane: (" << resultVector.x() << ", " << resultVector.y() << ", " << resultVector.z() << ")" << std::endl;
            vectorContainer.addVectorToVectorContainer(resultVector);
            vectorContainer.addVectorToVectorContainer(userInput.normalVector());
            txtWriter.write(outputFilePath, vectorContainer.vectorList());
            std::cout << "---------------------------------------------------" << std::endl;
        }
        break;

        case 0:
        {
            std::cout << "Existing...Thank you!" << std::endl;
        }
        break;

        default:
        {
            std::cout << "Invalid choice, please try agian!" << std::endl;
        }
        break;
        }
    } while (choice != 0);
    std::cout << "***************************************************" << std::endl;
    return 0;
}
