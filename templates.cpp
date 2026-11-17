#include <iostream> 
using namespace std; 
// Template class allowing Stack to hold any data type 'T' 
template <typename T> 
class Stack { 
    T arr[10]; 
    int top; 
public: 
    Stack() { top = -1; } // Initialize empty stack 
    // Push a generic value onto the stack 
    void push(T val) { 
        if (top < 9) arr[++top] = val; 
    } 
    void display() { 
        cout << "Stack contents: "; 
        for (int i = 0; i <= top; i++) cout << arr[i] << " "; 
        cout << endl; 
    } 
}; 
int main() { 
    Stack<int> s; // Instantiate a stack specifically for integers 
    int val1, val2; 
    cout << "Enter two integers to push to stack: "; 
    cin >> val1 >> val2; 
    s.push(val1);  
    s.push(val2);  
    s.display(); 
    return 0; 
} 
