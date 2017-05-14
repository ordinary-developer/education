#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <iostream>
#include <sstream>

void readStudentList(std::list<std::string>& students, std::ifstream& istr) {
    std::string name;
    while (std::getline(istr, name)) {
        std::cout << "Read name " << name << std::endl;
        students.push_back(name);
    }
}

void readDroppedStudents(std::list<std::string>& students) {
    std::ifstream istr("dropped.txt");
    readStudentList(students, istr);
}

void readCourseLists(std::vector<std::list<std::string>>& lists) {
    for (int i = 1; ; i++) {
        std::ostringstream ostr;
        ostr << "course" << i << ".txt";

        std::ifstream istr(ostr.str().c_str());
        if (!istr) {
            std::cout << "Failed to open " << ostr.str() << std::endl;
            break;
        }
        std::list<std::string> newList;
        readStudentList(newList, istr);
        lists.push_back(newList);
    }
}

std::list<std::string> getTotalEnrollment(
        const std::vector<std::list<std::string>>& courseStudents,
        const std::list<std::string>& droppedStudents)
{
    std::list<std::string> allStudents;
    for (auto& lst : courseStudents) {
        allStudents.insert(end(allStudents), begin(lst), end(lst));
    }

    allStudents.sort();
    allStudents.unique();
    for (auto& str : droppedStudents) {
        allStudents.remove(str);
    }
    
    return allStudents;
}

auto main() -> int {
    std::vector<std::list<std::string>> courseStudents;
    std::list<std::string> droppedStudents;

    readCourseLists(courseStudents);
    readDroppedStudents(droppedStudents);

    std::list<std::string> finalList = 
        getTotalEnrollment(courseStudents, droppedStudents);

    for (const auto& name : finalList) {
        std::cout << name << std::endl;
    }

    return 0;
}
