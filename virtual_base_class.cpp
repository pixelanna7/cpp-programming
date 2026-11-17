#include <iostream> 
using namespace std; 
class Student { 
protected: 
    int roll; 
public: 
    void inputRoll() { cout << "Enter roll number: "; cin >> roll; } 
}; 
// Virtual inheritance prevents duplicate Student instances in Result  
class Test : virtual public Student { 
protected: 
    float marks; 
public: 
    void inputMarks() { cout << "Enter test marks: "; cin >> marks; } 
}; 
// Virtual inheritance here as well 
class Sports : virtual public Student { 
protected: 
    float score; 
public: 
    void inputScore() { cout << "Enter sports score: "; cin >> score; } 
}; 
// Inherits from both Test and Sports, but only gets one copy of Student 
class Result : public Test, public Sports { 
public: 
    void displayTotal() { 
cout << "Total Mark for Roll " << roll << ": " << (marks + score) << endl; 
     } 
}; 
int main() { 
Result r; 
r.inputRoll();    
r.inputMarks();  
r.inputScore();  
r.displayTotal();  
return 0; 
} 