#include <iostream>
#include <cmath>
#include <string>
#include <array>

using namespace std;

int main()
{
    int age = 19;
    int *pAge = &age;
    double gpa  = 2.7;
    string name  = "Mike";
    string *pName = &name;

    //deref a pointer
    cout << "Gpa:" << &*&*&gpa << endl;


    cout << "Var Age:" << pAge<< endl;
    cout << "Deref of pAge:" << *pAge<< endl;


    //cout pointer

    cout << "Age:" << &age << endl;
    cout << "Gpa:" << &gpa << endl;
    cout << "Name:" << &name << endl;


    return 0;
}











