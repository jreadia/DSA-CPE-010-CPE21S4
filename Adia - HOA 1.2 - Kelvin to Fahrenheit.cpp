// Converting Kelvin to Fahrenheit
#include <iostream>
using namespace std;

// Function that converts Kelvin to Fahrenheit
float kelvin_to_fahrenheit(float kelvin) {
  float fahrenheit = ((kelvin - 273.15) * 1.8) + 32;
  return fahrenheit;
}

// Main program that runs
int main() {
  float kelvin;
  cout << "Enter temperature in Kelvin: ";
  cin >> kelvin;

  float fahrenheit = kelvin_to_fahrenheit(kelvin);
  cout << "Temperature in fahrenheit: " << fahrenheit << endl;

return 0;
}
