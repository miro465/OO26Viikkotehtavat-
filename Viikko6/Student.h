#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>

class Student {
public:
    Student(std::string name, int age);
    ~Student();

    void setAge(int age);
    void setName(std::string name);

    std::string getName() const;
    int getAge() const;

    void printStudentInfo() const;   // ← TÄRKEÄÄ: const täällä!

private:
    std::string Name;
    int Age;
};

#endif // STUDENT_H
