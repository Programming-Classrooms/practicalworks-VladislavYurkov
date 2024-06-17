#include "Student.hpp"

Student::Student() :
fullName("No name"),
course(0),
group(0)
{}

Student::Student(std::string line)
{
    std::string::size_type begInd = 0;
    std::string::size_type endInd = 0;
    
    endInd = line.find_first_of(" ", endInd);
    endInd = line.find_first_of(" ", endInd + 1);
    endInd = line.find_first_of(" ", endInd + 1);
    
    fullName = line.substr(begInd, endInd - begInd);

    begInd = endInd + 1;
    endInd = line.find_first_of(" ", endInd + 1);
    course = stoull(line.substr(begInd, endInd - begInd));

    begInd = endInd + 1;
    endInd = line.length();
    group = stoull(line.substr(begInd, endInd - begInd));

}

Student::~Student()
{}

void checkFile(std::ifstream& fileIn) {
    if(!fileIn.good()) {
        throw std::logic_error("File doesn't exist!");
    }
    if(!fileIn) {
        throw std::logic_error("File is not opened!");
    }
    if(fileIn.peek() == EOF) {
        throw std::logic_error("File is empty!");
    }
}

void readStudents(std::vector<Student>& studentArr, std::ifstream& fileIn)
{
    std::string line;
    while (std::getline(fileIn, line)) {
        studentArr.push_back(Student(line));
    }
}

bool isEarlierInAlphabet(const Student& first, const Student& second)
{
    return first.fullName <= second.fullName;
}

void sortByAlphabet(std::vector<Student>& studentsArr)
{
    std::sort(studentsArr.begin(), studentsArr.end(), isEarlierInAlphabet);
}

bool isEarlierInGroups(const Student& first, const Student& second)
{
    if (first.course < second.course) {
        return true;
    }
    else if (first.course > second.course) {
        return false;
    }
    else {
        if (first.group < second.group) {
            return true;
        }
        else if (first.group > second.group) {
            return false;
        }
        else {
            return first.fullName <= second.fullName;
        }
    }
}

void sortByGroups(std::vector<Student>& studentsArr) {
    std::sort(studentsArr.begin(), studentsArr.end(), isEarlierInGroups);
}

void printStudentsInFile(const std::vector<Student>& studentsArr, std::ofstream& fileOut)
{
    for (auto student : studentsArr) {
        fileOut << student.fullName << ' ' << student.course << ' ' << student.group << '\n';
    }
}
