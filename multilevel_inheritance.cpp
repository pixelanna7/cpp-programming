#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

class Student {
protected:
    string name;
    int roll;

public:
    void getinput() {
        cout << "Enter name :" << endl;
        cin >> name;
        cout << "Enter roll number :";
        cin >> roll;
    }

    void displayinput() const {
        cout << "Name :" << name << endl;
        cout << "Roll no. :" << roll << endl;
    }
};

class Exam : public Student {
protected:
    float m[6];

public:
    void getmarks() {
        cout << "Enter the marks for 6 subjects :";
        for (int i = 0; i < 6; i++)
            cin >> m[i];
    }

    void displaymarks() const {
        cout << "Marks of 6 subjects are :\n";
        for (int i = 0; i < 6; i++)
            cout << m[i] << " ";
    }
};

class Result : public Exam {
private:
    float total;

public:
    void calculateresult() {
        total = 0;
        for (int i = 0; i < 6; i++) {
            total += m[i];
        }
    }

    void displayresult() {
        cout << "\nTotal Marks :" << total << endl;
    }
};

int main() {
    Result r;
    r.getinput();
    r.displayinput();
    r.getmarks();
    r.displaymarks();
    r.calculateresult();
    r.displayresult();

    return 0;
}
