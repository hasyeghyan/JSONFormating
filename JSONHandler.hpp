#ifndef JSONHANDLER_HPP
#define JSONHANDLER_HPP

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include "Student.hpp"
#include "Course.hpp"

class JSONHandler {
    public:       
        std::string serializeS(const Student& s);
        std::string serializeC(const Course& s);
        std::vector<Student> deserializeS(std::ifstream& file);
        std::vector<Course> deserializeC(std::ifstream& file);

        void moveToFile(std::vector<Student>& v, std::ofstream& file);
        void moveToFile(std::vector<Course>& v, std::ofstream& file);
};

#endif