/*

Modify the code given in ILO B and add the following functions:
a.) A function to compute for the area of a triangle
b.) A function to compute for the perimeter of a triangle
c.) A function that determines whether the triangle is acute-angled, obtuse-angled or ‘others.’

*/

#include <iostream>
#include <cmath>
using namespace std;

class Triangle{
private:
    double totalAngle, angleA, angleB, angleC;
    double totalSide, sideA, sideB, sideC;

public:
    Triangle(double A, double B, double C);
    void setAngles(double A, double B, double C);
    void setSides(double A, double B, double C);
    const bool validateTriangle();
    const double computeArea(); // function to compute area of triangle
    const double computePerimeter(); // function to compute perimeter of triangle
    const string determineTriangleType(); // function to determine triangle type
};

Triangle::Triangle(double A, double B, double C) {
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A+B+C;
}

void Triangle::setAngles(double A, double B, double C) {
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A+B+C;
}

void Triangle::setSides(double A, double B, double C) {
    sideA = A;
    sideB = B;
    sideC = C;
    totalSide = A+B+C;
}

const bool Triangle::validateTriangle() {
    return (totalAngle <= 180);
} 

const double Triangle::computeArea() {
    // Using Heron's formula to compute area of triangle
    double s = (sideA + sideB + sideC) / 2;
    return sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
}

const double Triangle::computePerimeter() {
    return sideA + sideB + sideC;
}

const string Triangle::determineTriangleType() {
    if (angleA < 90 && angleB < 90 && angleC < 90) {
        return "Acute-angled";
    } else if (angleA > 90 || angleB > 90 || angleC > 90) {
        return "Obtuse-angled";
    } else {
        return "Other";
    }
}

// Main Code that runs
int main(){
    Triangle set1(0, 0, 0); // Create a triangle object
    set1.setAngles(40, 30, 110); // Set the angles of the triangle
    set1.setSides(5, 6, 7); // Set the sides of the triangle
    if(set1.validateTriangle()){
        cout << "The shape is a valid triangle.\n";
        cout << "Area: " << set1.computeArea() << endl;
        cout << "Perimeter: " << set1.computePerimeter() << endl;
        cout << "Triangle Type: " << set1.determineTriangleType() << endl;
    } else {
        cout << "The shape is NOT a valid triangle.\n";
    }

    return 0;
} 

