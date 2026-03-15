#include "JSONHandler.hpp"


int main() {
    Student student1("Hasmik", 20, 19);
    Student student2("Gurgen", 18, 19);
    Student student3("Miqayel", 25, 20);
    Student student4("Narek", 23, 15);
    Student student5("Levon", 21, 14);

    std::vector<Student> v1{student1, student2, student3, student4, student5};
     
    std::ofstream file1("file.json");
    JSONHandler handler1;
    handler1.moveToFile(v1,file1);

    std::ifstream file2("Course.json");
    JSONHandler handler2;
    std::vector<Course> v2 = handler2.deserializeC(file2);
    for (auto x : v2)  x.print();
    
    return 0;
}





