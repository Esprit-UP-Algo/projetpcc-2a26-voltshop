#ifndef GESTION_EMPLOYEE_H
#define GESTION_EMPLOYEE_H

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

struct Employee {
    std::string cin;         // 8-digit unique identifier
    std::string fullName;    // alphabetic + spaces
    std::string position;    // job title
    std::string address;     // address (min 5 chars)
    std::string salary;      // stored as string (VARCHAR in DB)
    std::string status;      // e.g. "Active", "Inactive", etc.
};

class GestionEmployee {
private:
    std::vector<Employee> employees;

public:
    // =====================================================
    //                BASIC CRUD OPERATIONS
    // =====================================================

    // Add a new employee (with validation)
    void addEmployee(const Employee& emp);

    // Display all employees in console
    void displayEmployees() const;

    // Edit an employee by CIN (returns true if updated)
    bool editEmployee(const std::string& cin, const Employee& updated);

    // Delete an employee by CIN (returns true if deleted)
    bool deleteEmployee(const std::string& cin);

    // Find employee by CIN (returns pointer or nullptr)
    Employee* findEmployee(const std::string& cin);

    // Get all employees (read-only access)
    const std::vector<Employee>& getAll() const { return employees; }

    // Get sorted copy of employees (does not modify original)
    std::vector<Employee> getSorted(const std::string& field) const;
};

#endif // GESTION_EMPLOYEE_H
