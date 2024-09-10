// Calculate the distance between two points
#include <iostream>
#include <cmath>
using namespace std;

// Function that calculates the distance between two points
float calculateDistance(float x1, float y1, float x2, float y2) {
    float x = x2 - x1;
    float y = y2 - y1;
    return sqrt((x * x) + (y * y));
}

// Main program that runs
int main() {
    float x1, y1, x2, y2;
    
    cout << "Enter coordinates of point 1 (x y): ";
    cin >> x1 >> y1;
    
    cout << "Enter coordinates of point 2 (x y): ";
    cin >> x2 >> y2;
    
    float distance = calculateDistance(x1, y1, x2, y2);
    
    cout << "The distance between the two points is: " << distance << endl;
    
return 0;
}
