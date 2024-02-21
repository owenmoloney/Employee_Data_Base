//Owen Moloney 
//Wednesday, February 21st 2024
//This is the .cpp file that manages the emplyee update system

#include "Employee.h"
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
//Construcotor for the employee class in the .h file
Employee::Employee(string n, int id, double sal) : name(n), employeeID(id), salary(sal){}

void Employee::displayDetails() const{
	cout<<"Employee ID: "<<employeeID<<endl;
	cout<<"Name: "<<name<<endl;
	cout<<"Salary: $"<<salary<<endl;
}
//adjusts the employee amount by one
void EmployeeManagementSystem::addEmployee(const Employee& emp)
{
	employees.push_back(emp);
}

void EmployeeManagementSystem::displayAllEmployees() const {
    for (const auto& emp : employees) 
    {
        emp.displayDetails();
        cout << "----------------\n";
    }
}

Employee* EmployeeManagementSystem::findEmployeeByID(int id) 
{
    for (auto& emp : employees)
    {
        if (emp.employeeID == id) 
	{
            return &emp;
        }
    }
    return nullptr;
}
//Updates employee Salary using the find employe function above
void EmployeeManagementSystem::updateEmployeeSalary(int id, double newSalary) 
{
    Employee* emp = findEmployeeByID(id);
    if (emp) 
    {
        emp->salary = newSalary;
        cout<<"Salary updated successfully.\n";
    }
    else 
    {
        cout<<"Employee not found.\n";
    }
}
void EmployeeManagementSystem::removeEmployee(int id) 
{
    auto it = remove_if(employees.begin(), employees.end(),
              [id](const Employee& emp) { return emp.employeeID == id; });

    if (it != employees.end()) 
    {
        employees.erase(it, employees.end());
        std::cout << "Employee removed successfully.\n";
    }
     else 
    {
        std::cout << "Employee not found.\n";
    }
}
//Starting main code which will use the classes and functoin definition to manages the employee system
int main() {
    EmployeeManagementSystem ems;
	//Default Employees
    ems.addEmployee(Employee("Ryan Schmitt", 101, 50000.0));
    ems.addEmployee(Employee("George Linn", 102, 60000.0));
    ems.addEmployee(Employee("Owen Moloney", 103, 65000.0));
	//Custom Employees
	cout<<"How many Employees to you want to add in addition(3 inlcuded already)";
	int answer;
	cin>>answer;
	cin.ignore();
	for(int i=0; i<answer; i++)
	{
	  cout<<"Employee #"<<i+4<<endl;
	   string name;
	   int id;
	   double sal;
	   cout<<"Enter Name: ";
	   getline(cin, name);
	   cout<<"Enter Id: ";
	   cin>> id;
	   cout<<"Enter Salary: ";
	   cin>>sal;
	   cin.ignore();
	   ems.addEmployee(Employee(name, id, sal));
	} 
    //Displaying the employess
    cout<<"All Employees"<<endl;
    ems.displayAllEmployees();
	
    // Removing an employee
    cout<<"Enter the ID of the employee you want to remove: ";
    int removalID;
    cin>>removalID;
    ems.removeEmployee(removalID);

    // Displaying all employees after removal
    cout<<"All Employees after Removal: "<<endl;
    ems.displayAllEmployees();

    return 0;
}

