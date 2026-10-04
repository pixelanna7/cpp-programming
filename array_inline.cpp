#include<iostream>
#include<iomanip>
#include <cstring>
using namespace std;
const int SIZE=10;
class Person{
    char name[64];
    int age;
    char address[64];
    float basic;
    float hra;//20% of basic
    float da;//50% of basic
    float ta;//fixed allowance
    float grossSalary;

public:    
    void calculateSalary(){
        hra=0.20f*basic;
        da=0.50f*basic;
        ta=1500.0f;
        grossSalary=basic+hra+da+ta;
    }
public:    
    void getdata(){ 
        cin.ignore(); // To ignore the newline character left by previous input
        cout<<"Enter name: ";
        cin.getline(name, 64);
        cout<<"Enter age: ";
        cin>> age;
        cin.ignore(); // To ignore the newline character left by cin>>
        cout<<"Enter address: ";
        cin.getline(address, 64);
        cout<<"Enter basic salary:Rs. ";
        cin>> basic;

        calculateSalary(); // Calculate salary components after getting basic salary
    }


//Default constructor
    Person(){
        strncpy(name, "Unknown", 63);
        name[63] = '\0';
        strncpy(address, "Unknown", 63);
        address[63] = '\0';
        age=0;
        basic=hra=da=ta=grossSalary=0.0f;
    }
    //Parametrized constructor: buids the salary components automatically
    Person(const char *n, int a, const char *addr, float b){
        strncpy(name, n, 63);  name[63]='\0';
        strncpy(address, addr, 63);  address[63]='\0';
        age=a;
        basic=b;
        calculateSalary();
    }

    int getAge() const { return age; }

    //(a Inline function to find the youngest and eldest person in the array of Person objects)
    static inline int findYoungest(const Person arr[], int n){
        int minAge=arr[0].age;
        for(int i=1;i<n;i++)
            if(arr[i].age<minAge)minAge=arr[i].age;
        return minAge;
    }

    static inline int findEldest(const Person arr[], int n){
        int maxAge=arr[0].age;
        for(int i=1;i<n;i++)
            if(arr[i].age>maxAge)maxAge=arr[i].age;
        return maxAge;

    }

    //(b)Salary slip
    void displaySalarySlip() const{
        cout<<fixed<<setprecision(2);
        cout<<"\nSalary Slip "<<endl;
        cout<<"--------------------------"<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Address: "<<address<<endl;
        cout<<"--------------------------"<<endl;
        cout<<left<< setw(20)<<"EARNINGS "<<right<< setw(10)<<"AMOUNT"<<endl;
        cout<<left<< setw(20)<<"Basic Salary: Rs."<<right<< setw(10)<<basic<<endl;
        cout<<left<< setw(20)<<"HRA: Rs."<<right<< setw(10)<<hra<<endl;
        cout<<left<< setw(20)<<"DA: Rs."<<right<< setw(10)<<da<<endl;
        cout<<left<< setw(20)<<"TA: Rs."<<right<< setw(10)<<ta<<endl;
        cout<<left<< setw(20)<<"GROSS SALARY: Rs."<<right<< setw(10)<<grossSalary<<endl;
        cout<<"--------------------------"<<endl;
    }
};

int main(){
    //Array of 10 Person objects(default constructor runs first)
    Person p[SIZE];
    // Read user details dynamically using a loop
    for (int i = 0; i < SIZE; i++) {
        cout << "\nEnter details for Person: " << (i + 1)<< endl;
        p[i].getdata();
    }

    //(a) youngest and eldest
    cout<<"\nYoungest person's age: "<<Person::findYoungest(p,SIZE)<<endl;
    cout<<"Eldest person's age: "<<Person::findEldest(p,SIZE)<<endl;

    //(b)Salary slip
    for(int i=0;i<SIZE;i++)
        p[i].displaySalarySlip();

    return 0;
}