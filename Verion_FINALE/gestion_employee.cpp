#include "gestion_employee.h"
#include <regex>
#include <iostream>
#include <iomanip>
#include <QMessageBox>
#include <algorithm>

// ===================================================
//                ADD EMPLOYEE
// ===================================================
void GestionEmployee::addEmployee(const Employee& emp)
{
    std::regex cinRegex("^[0-9]{8}$");
    if (!std::regex_match(emp.cin, cinRegex)) {
        QMessageBox::warning(nullptr, "Invalid CIN", "❌ CIN must contain exactly 8 digits.");
        return;
    }

    std::regex nameRegex("^[A-Za-zÀ-ÖØ-öø-ÿ\\s]+$");
    if (!std::regex_match(emp.fullName, nameRegex) || emp.fullName.length() < 3) {
        QMessageBox::warning(nullptr, "Invalid Name", "❌ Full name must contain only letters and spaces (min 3 characters).");
        return;
    }

    std::regex positionRegex("^[A-Za-z\\s]+$");
    if (!std::regex_match(emp.position, positionRegex) || emp.position.empty()) {
        QMessageBox::warning(nullptr, "Invalid Position", "❌ Position must contain only letters.");
        return;
    }

    if (emp.address.length() < 5) {
        QMessageBox::warning(nullptr, "Invalid Address", "❌ Address must contain at least 5 characters.");
        return;
    }

    std::regex salaryRegex("^[0-9]+(\\.[0-9]{1,2})?$");
    if (!std::regex_match(emp.salary, salaryRegex) || std::stod(emp.salary) <= 0) {
        QMessageBox::warning(nullptr, "Invalid Salary", "❌ Salary must be a positive number.");
        return;
    }

    std::vector<std::string> validStatuses = {"Active", "Inactive", "On Probation", "Resigned", "Terminated"};
    if (std::find(validStatuses.begin(), validStatuses.end(), emp.status) == validStatuses.end()) {
        QMessageBox::warning(nullptr, "Invalid Status",
                             "❌ Status must be one of:\nActive, Inactive, On Probation, Resigned, Terminated.");
        return;
    }

    // Check for duplicate CIN
    for (const auto& e : employees) {
        if (e.cin == emp.cin) {
            QMessageBox::warning(nullptr, "Duplicate CIN",
                                 "❌ Employee with this CIN already exists.");
            return;
        }
    }

    employees.push_back(emp);
    QMessageBox::information(nullptr, "Success",
                             QString::fromStdString("✅ Employee '" + emp.fullName + "' added successfully."));
}

// ===================================================
//                DISPLAY ALL EMPLOYEES
// ===================================================
void GestionEmployee::displayEmployees() const
{
    if (employees.empty()) {
        QMessageBox::information(nullptr, "No Employees", "⚠️ No employees to display.");
        return;
    }

    std::cout << std::left
              << std::setw(12) << "CIN"
              << std::setw(20) << "Full Name"
              << std::setw(15) << "Position"
              << std::setw(25) << "Address"
              << std::setw(10) << "Salary"
              << std::setw(15) << "Status"
              << "\n";

    std::cout << std::string(97, '-') << "\n";

    for (const auto& e : employees) {
        std::cout << std::left
                  << std::setw(12) << e.cin
                  << std::setw(20) << e.fullName
                  << std::setw(15) << e.position
                  << std::setw(25) << e.address
                  << std::setw(10) << e.salary
                  << std::setw(15) << e.status
                  << "\n";
    }
}

// ===================================================
//                EDIT EMPLOYEE
// ===================================================
bool GestionEmployee::editEmployee(const std::string& cin, const Employee& updated)
{
    std::regex cinRegex("^[0-9]{8}$");
    if (!std::regex_match(updated.cin, cinRegex)) {
        QMessageBox::warning(nullptr, "Invalid CIN", "❌ CIN must contain exactly 8 digits.");
        return false;
    }

    std::regex nameRegex("^[A-Za-zÀ-ÖØ-öø-ÿ\\s]+$");
    if (!std::regex_match(updated.fullName, nameRegex) || updated.fullName.length() < 3) {
        QMessageBox::warning(nullptr, "Invalid Name", "❌ Full name must contain only letters and spaces (min 3 characters).");
        return false;
    }

    std::regex positionRegex("^[A-Za-z\\s]+$");
    if (!std::regex_match(updated.position, positionRegex) || updated.position.empty()) {
        QMessageBox::warning(nullptr, "Invalid Position", "❌ Position must contain only letters.");
        return false;
    }

    if (updated.address.length() < 5) {
        QMessageBox::warning(nullptr, "Invalid Address", "❌ Address must contain at least 5 characters.");
        return false;
    }

    std::regex salaryRegex("^[0-9]+(\\.[0-9]{1,2})?$");
    if (!std::regex_match(updated.salary, salaryRegex) || std::stod(updated.salary) <= 0) {
        QMessageBox::warning(nullptr, "Invalid Salary", "❌ Salary must be a positive number.");
        return false;
    }

    std::vector<std::string> validStatuses = {"Active", "Inactive", "On Probation", "Resigned", "Terminated"};
    if (std::find(validStatuses.begin(), validStatuses.end(), updated.status) == validStatuses.end()) {
        QMessageBox::warning(nullptr, "Invalid Status",
                             "❌ Status must be one of:\nActive, Inactive, On Probation, Resigned, Terminated.");
        return false;
    }

    for (auto& e : employees) {
        if (e.cin == cin) {
            e = updated;
            QMessageBox::information(nullptr, "Success",
                                     QString::fromStdString("✏️ Employee with CIN " + cin + " updated successfully."));
            return true;
        }
    }

    QMessageBox::warning(nullptr, "Not Found",
                         QString::fromStdString("❌ Employee with CIN " + cin + " not found."));
    return false;
}

// ===================================================
//                DELETE EMPLOYEE
// ===================================================
bool GestionEmployee::deleteEmployee(const std::string& cin)
{
    for (auto it = employees.begin(); it != employees.end(); ++it) {
        if (it->cin == cin) {
            QMessageBox::information(nullptr, "Deleted",
                                     QString::fromStdString("🗑️ Employee '" + it->fullName + "' removed."));
            employees.erase(it);
            return true;
        }
    }

    QMessageBox::warning(nullptr, "Not Found",
                         QString::fromStdString("❌ Employee with CIN " + cin + " not found."));
    return false;
}

// ===================================================
//                FIND EMPLOYEE
// ===================================================
Employee* GestionEmployee::findEmployee(const std::string& cin)
{
    for (auto& e : employees) {
        if (e.cin == cin)
            return &e;
    }
    return nullptr;
}

// ===================================================
//                GET SORTED EMPLOYEES
// ===================================================
std::vector<Employee> GestionEmployee::getSorted(const std::string& field) const
{
    std::vector<Employee> sorted = employees; // copy

    if (field == "CIN") {
        std::sort(sorted.begin(), sorted.end(),
                  [](const Employee& a, const Employee& b) { return a.cin < b.cin; });
    }
    else if (field == "Name") {
        std::sort(sorted.begin(), sorted.end(),
                  [](const Employee& a, const Employee& b) { return a.fullName < b.fullName; });
    }
    else if (field == "Salary") {
        std::sort(sorted.begin(), sorted.end(),
                  [](const Employee& a, const Employee& b) { return std::stod(a.salary) < std::stod(b.salary); });
    }

    return sorted;
}
