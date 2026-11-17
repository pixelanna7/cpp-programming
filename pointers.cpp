#include <iostream> 
using namespace std; 
class Box { 
int length; 
public: 
    void setLength(int length) { 
        // Application: The 'this' pointer distinguishes the class member from the local parameter 
        this->length = length;  
    } 
    void display() { 
        // 'this' explicitly points to the current object's attributes 
        cout << "Box length is: " << this->length << endl; 
    } 
}; 
int main() { 
    Box b; 
    int input; 
    cout << "Enter box length: "; cin >> input; 
    b.setLength(input); 
    b.display(); 
    return 0; 
} 