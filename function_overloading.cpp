#include <iostream>
#include <cmath>
using namespace std;

double AREA(double radius) {
    return 3.14 * radius * radius;
}

double AREA(double length, double breadth) {
    return length * breadth;
}

float AREA(float a, float b, float c) // prototype decln
{
    float s = (a + b + c) / 2.0f;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main() {
    double radius, length, breadth;
    float a, b, c;

    cout << "Enter the radius of circle :";
    cin >> radius;
    cout << "\n Area of circle :" << AREA(radius) << "\n";

    cout << "Enter the length and breadth of rectangle :";
    cin >> length >> breadth;
    cout << "\n Area of rectangle :" << AREA(length, breadth) << "\n";

    cout << "Enter the sides of triangle :";
    cin >> a >> b >> c;
    cout << "\n Area of triangle :" << AREA(a, b, c) << "\n";

    return 0;
}
