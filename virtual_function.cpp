#include <iostream>
#include <string>
using namespace std;

class Media {
protected:
    string title, publication;

public:
    virtual void read() {
        cout << "Enter title : ";
        getline(cin >> ws, title);
        cout << "Enter publication : ";
        getline(cin >> ws, publication);
    }

    virtual void show() const {
        cout << "Title : " << title << ", Publication : "
             << publication << '\n';
    }

    virtual ~Media() {}
};

class Book : public Media {
    int pages = 0;

public:
    void read() override {
        cout << "\n Book Data \n";
        Media::read();
        cout << "Enter number of pages : ";
        cin >> pages;
    }

    void show() const override {
        Media::show();
        cout << "Pages : " << pages << '\n';
    }
};

class Tape : public Media {
    float time = 0.0f;

public:
    void read() override {
        cout << "\n Tape Data \n";
        Media::read();
        cout << "Enter playing time (mins) : ";
        cin >> time;
    }

    void show() const override {
        Media::show();
        cout << "Time : " << time << " mins\n";
    }
};

int main() {
    Media* m1 = new Book();
    Media* m2 = new Tape();

    m1->read();
    m2->read();

    cout << "\n Output \n";
    m1->show();
    m2->show();

    delete m1;
    delete m2;

    return 0;
}
