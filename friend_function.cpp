#include <iostream>
using namespace std;

class ClassB;

class ClassA {
    int num;

public:
    void input() {
        cout << "Enter first number A : ";
        cin >> num;
    }

    void display() {
        cout << "A : " << num << " ";
    }

    friend void swapNumbers(ClassA&, ClassB&);
};

class ClassB {
    int num;

public:
    void input() {
        cout << "Enter second number B : ";
        cin >> num;
    }

    void display() {
        cout << "B : " << num << endl;
    }

    friend void swapNumbers(ClassA&, ClassB&);
};

void swapNumbers(ClassA& a, ClassB& b) {
    int temp = a.num;
    a.num = b.num;
    b.num = temp;
}

int main() {
    ClassA a;
    ClassB b;

    a.input();
    b.input();

    swapNumbers(a, b);

    cout << "After swapping : ";
    a.display();
    b.display();

    return 0;
}
