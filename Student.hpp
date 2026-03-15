#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <iostream>
#include <string>
#include <vector>

class Student {
    private:
        std::string name;
        int age;
        double gpa;
    public:
        Student(const std::string& n, int a, double g) : name{n}, age{a}, gpa{g} {}
        Student() {}
        
        std::string getName() const { return name; }
        int getAge() const { return age; }        
        double getGpa() const { return gpa; }

        void setName(const std::string& n) { name = n; }
        void setAge(int a) {
            if (a >= 0) {
                age = a;
            }
        }
        void setGpa(double g) { gpa = g; }

        void print() const {
            std::cout << "Name: " << name 
            << ", age: " << age 
            << ", gpa: " << gpa  
            << std::endl;
        }
};

#endif