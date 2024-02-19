## Computational_Geometry

# Vector Operations Project
This project provides a set of classes and functions for performing various operations on 3D vectors.

# Classes
GeomVector
The GeomVector class represents a 3D vector and provides the following operations:

equalityCheck(): Checks equality with another vector.
magnitude(): Calculates the magnitude of the vector.
normalize(): Normalizes the vector.
setVectorLength(): Sets the length of the vector.
addScalar(), subtractScalar(), multiplyScalar(), divideScalar(): Scalar operations on the vector.
addVector(): Adds another vector to this vector.
dotProduct(): Calculates the dot product with another vector.
crossProduct(): Calculates the cross product with another vector.
directionCosines(): Calculates the direction cosines of the vector.
multiplyMatrix(): Multiplies the vector by a matrix.
distanceBetweenVectors(): Calculates the distance between two vectors.
distanceBetweenVectorAndPlane(): Calculates the distance between the vector and a plane.
angleBetweenVectors(): Calculates the angle between two vectors.
angleBetweenVectorAndAxis(): Calculates the angle between the vector and an axis.
angleBetweenVectorAndPlane(): Calculates the angle between the vector and a plane.
projectionOnVector(): Projects the vector onto another vector.
projectionOnPlane(): Projects the vector onto a plane.

# Other Classes
TxtWriter: A utility class for writing vectors to a text file.
Matrix: A class representing a 3x3 matrix.
Plane: A class representing a plane in 3D space.
Point3D: A base class representing a point in 3D space.
UserInput: A utility class for handling user input.
VectorContainer: A class for managing a collection of vectors.

# Inheritance
The GeomVector class is inherited from the Point3D class, which provides basic functionality for representing a point in 3D space.
