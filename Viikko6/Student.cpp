#include "student.h"
#include <iostream>

Student::Student(std::string name, int age)
    : Name(name), Age(age)
{
}

Student::~Student() {
}

void Student::setAge(int age) {
    if (age >= 0) {
        Age = age;
    }
}

void Student::setName(std::string name) {
    if (!name.empty()) {
        Name = name;
    }
}

std::string Student::getName() const {
    return Name;
}

int Student::getAge() const {
    return Age;
}

void Student::printStudentInfo() const {
    std::cout << "Opiskelija " << Name << " ika " << Age << std::endl;
}
