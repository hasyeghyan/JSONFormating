#ifndef COURSE_HPP
#define COURSE_HPP

#include <iostream>
#include <string>
#include <vector>

class Course {
    private:
        std::string title;
        int credits;
        bool mandatory;
    public:
        Course() {}
        Course(const std::string& t, int c,bool m) : title{t}, credits{c}, mandatory{m} {}
        std::string getTitle() const { return title; }
        int getCredits() const { return credits; }        
        bool getMandatory() const { return mandatory; }
        
        void setTitle(const std::string& t) {
            title = t;
        }

        void setCredits(int c) {
            if (c >= 0) {
                credits = c;
            }
        }

        void setMandatory(bool m) {
            mandatory = m;
        }

        void print() const {
            std::cout << "Title: " << title 
            << ", credits: " << credits 
            << ", is mandatory?: " << (mandatory == true ? "Yes" : "No") 
            << std::endl;
        }
};

#endif