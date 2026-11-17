#include <iostream> 
using namespace std; 
int main() { 
    float numerator, denominator; 
    cout << "Enter numerator: "; cin >> numerator; 
    cout << "Enter denominator: "; cin >> denominator; 
    try { 
        // Check for error condition 
        if (denominator == 0) { 
            // Throw an exception string if division by zero is attempted 
            throw "Error: Division by zero is not allowed!"; 
        } 
        // This won't execute if an exception is thrown 
        cout << "Result: " << (numerator / denominator) << endl; 
    } catch (const char* msg) { 
        // Catch and handle the thrown exception 
        cout << msg << endl; 
    } 
    return 0; 
}