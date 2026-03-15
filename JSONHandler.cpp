#include "JSONHandler.hpp"
#include "algorithm"

std::string JSONHandler::serializeS(const Student& s) {
    std::stringstream ss;
    ss << " {\n" << "  \"name\": " << "\"" << s.getName() <<  "\"" << ",\n" <<
    "  \"age\": " << s.getAge() << ",\n" << 
    "  \"gpa\": " << s.getGpa() << "\n" << " }"; 
    return ss.str();
}

std::string JSONHandler::serializeC(const Course &s) {
    std::stringstream ss;
    ss << " {\n"
       << "  \"title\": " << "\"" << s.getTitle() << "\"" << ",\n"
       << "  \"credits\": " << s.getCredits() << ",\n"
       << "  \"mandatory\": " << (s.getMandatory()? "\"Yes\"": "\"No\"") << "\n"
       << " }";
    return ss.str();
}

std::vector<Course> JSONHandler::deserializeC(std::ifstream& file) {
    std::vector<Course> vec;
    std::string buff;
    
    while (file >> buff) {
        if (buff.find("{") != std::string::npos) {
            Course course;
            while (file >> buff && buff.find("}") == std::string::npos) {
                if (buff.find("title") != std::string::npos) {
                    std::string title;
                    file >> title;
                    title.erase(std::remove(title.begin(), title.end(), ','), title.end());
                    title.erase(std::remove(title.begin(), title.end(), '"'), title.end());
                    course.setTitle(title);
                }
                else if (buff.find("credits") != std::string::npos) {
                    int credits;
                    file >> credits;
                    course.setCredits(credits);
                }
                else if (buff.find("mandatory") != std::string::npos) {
                    std::string mandatory;
                    file >> mandatory;
                    mandatory.erase(std::remove(mandatory.begin(), mandatory.end(), ','), mandatory.end());
                    mandatory.erase(std::remove(mandatory.begin(), mandatory.end(), '"'), mandatory.end());
                    
                    course.setMandatory(mandatory == "Yes");
                }
            }
        vec.push_back(course);
        }
    }
    return vec;  
}

std::vector<Student> JSONHandler::deserializeS(std::ifstream &file) {
    std::vector<Student> students;
    std::string buff;

    while (file >> buff) {
        if (buff.find("{") != std::string::npos) {
            Student temp;
            while (file >> buff && buff.find("}") == std::string::npos) {
                 if (buff.find("\"name\":") != std::string::npos) {
                    std::string name;
                    std::getline(file, name);

                    name.erase(std::remove(name.begin(), name.end(), '"'), name.end());
                    name.erase(std::remove(name.begin(), name.end(), ','), name.end());
                    
                    size_t first = name.find_first_not_of(" ");
                    if (first != std::string::npos) name = name.substr(first);

                    temp.setName(name);
                }
                else if (buff.find("\"age\":") != std::string::npos) {
                    int age = 0;
                    file >> age;
                    temp.setAge(age);
                }
                else if (buff.find("\"gpa\":") != std::string::npos) {
                    double gpa;
                    file >> gpa;
                    temp.setGpa(gpa);
                }
            }
            students.push_back(temp);
        }
    }
    return students;
}

void JSONHandler::moveToFile(std::vector<Student>& v, std::ofstream& file) {
    
    file << "[\n";

    for (int i{}; i < v.size(); ++i) {
       file << serializeS(v[i]);
       if (i != v.size() - 1) file << ",\n"; 
    }
    file << "\n]";
}

void JSONHandler::moveToFile(std::vector<Course>& c, std::ofstream& file) {
    file << "[\n";
    for (int i{}; i < c.size(); ++i) {
        file << serializeC(c[i]);
        if (i < c.size() - 1) file << ",\n";
    }
    file << "\n]";
}