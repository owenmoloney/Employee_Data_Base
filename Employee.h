//Owen Moloney
//February 21, 2024
//This is the .h file to define the classes of for managing an ecmployee list.
//

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Employee{
public:
      string name;
      int employeeID;
      double salary;

      Employee(string n, int id, double sal);

      void displayDetails() const;
};

class EmployeeManagementSystem {
private:
	vector<Employee> employees;
  	

public:
       void addEmployee(const Employee& emp);

       void displayAllEmployees() const;

       Employee* findEmployeeByID(int id);

       void updateEmployeeSalary(int id, double newSalary);

       void removeEmployee(int id);
};
#endif 

