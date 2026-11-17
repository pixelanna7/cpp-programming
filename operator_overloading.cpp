#include <iostream>
using namespace std;

class Complex {
private:
    float real;
    float imag;

public:
    Complex(float r = 0, float i = 0) {
        real = r;
        imag = i;
    }

    void input() {
        cout << "Enter real part : ";
        cin >> real;
        cout << "Enter imaginary part : ";
        cin >> imag;
    }

    Complex operator++() {
        ++real;
        ++imag;
        return *this;
    }

    Complex operator++(int) {
        Complex temp = *this;
        real++;
        imag++;
        return temp;
    }

    Complex operator--() {
        --real;
        --imag;
        return *this;
    }

    Complex operator--(int) {
        Complex temp = *this;
        real--;
        imag--;
        return temp;
    }

    Complex operator+(const Complex& obj) {
        Complex temp;
        temp.real = real + obj.real;
        temp.imag = imag + obj.imag;
        return temp;
    }

    Complex operator-(const Complex& obj) {
        Complex temp;
        temp.real = real - obj.real;
        temp.imag = imag - obj.imag;
        return temp;
    }

    void display() {
        if (imag >= 0)
            cout << real << " + " << imag << "i" << endl;
        else
            cout << real << " - " << -imag << "i" << endl;
    }
};

int main() {
    Complex c1, c2, c1_inc, c1_dec, c2_inc, c2_dec, sum, diff;

    cout << "Enter first Complex Number :" << endl;
    c1.input();

    c1_inc = c1;
    c1_dec = c1;

    ++c1_inc;
    cout << "Incremented first number : ";
    c1_inc.display();

    --c1_dec;
    cout << "Decremented first number : ";
    c1_dec.display();

    cout << "\n Enter Second Complex Number : ";
    c2.input();

    c2_inc = c2;
    c2_dec = c2;

    ++c2_inc;
    cout << "Incremented second number : ";
    c2_inc.display();

    --c2_dec;
    cout << "Decremented second number : ";
    c2_dec.display();

    cout << "Addition of numbers : ";
    sum = c1_dec + c2_dec;
    sum.display();

    diff = c1_dec - c2_dec;
    cout << "Subtraction of numbers : ";
    diff.display();

    return 0;
}
