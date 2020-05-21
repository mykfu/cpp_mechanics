//
// Created by user on 14.05.2020.
//

#include <iostream>
#include <vector>
using namespace std;

struct Employee {
    string name;
    string email;
    int age;
    double salary;
    void print() {
        cout << "Employee{\n";
        cout << "\tName: " << name << endl;
        cout << "\temail: " << email << endl;
        cout << "\tage: " << age << endl;
        cout << "\tsalary: " << salary << endl;
        cout << "}\n";
    }
};

struct Department {
    string name;
    Employee director;
};

struct Organization {
    string name;
    string type;
    vector<Employee> employees;
    void print() {
        cout << "Organization{\n";
        cout << "\tName: " << name << endl;
        cout << "\ttype: " << type << endl;
        for (int i = 0; i < employees.size(); ++i) {
            employees[i].print();
        }
        cout << "}\n";
    }
};

void printEmployee(Employee &employee) {
    cout << "Employee{\n";
    cout << "\tName: " << employee.name << endl;
    cout << "\temail: " << employee.email << endl;
    cout << "\tage: " << employee.age << endl;
    cout << "\tsalary: " << employee.salary << endl;
    cout << "}\n";
}

void printOrg(Organization &org) {
    cout << "Organization{\n";
    cout << "\tName: " << org.name << endl;
    cout << "\ttype: " << org.type << endl;
    for (int i = 0; i < org.employees.size(); ++i) {
        printEmployee(org.employees[i]);
    }
    cout << "}\n";
}

int main() {
    cout << "Employee" << endl;
    string name = "John Doe";
    string email = "john_doe@example.com";
    int age = 45;
    double salary = 2000.00;

    Employee john;
    john.name = name;
    john.email = email;
    john.age = age;
    john.salary = salary;

    Employee ivan = {"Ivan Petrov", "ivan@mail.ru", 18, 200.00};

//    printEmployee(john);
//    printEmployee(ivan);
    john.print();
    ivan.print();

    vector<Employee> empls;
    empls.push_back(john);
    empls.push_back(ivan);

    Organization kfu;
    kfu.name = "KFU";
    kfu.type = "FGAO";
    kfu.employees = empls;

//    printOrg(kfu);
    kfu.print();
}