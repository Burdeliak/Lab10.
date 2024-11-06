#include <iostream>
#include <vector>
#include <string>

enum Speciality { ComputerScience, Informatics, MathEconomics, PhysicsInformatics, LaborTraining };

struct Student {
    std::string surname;
    int course;
    Speciality speciality;
    int physicsGrade;
    int mathGrade;
    int informaticsGrade;
};

void inputStudentData(std::vector<Student>& students, int numberOfStudents) {
    for (int i = 0; i < numberOfStudents; i++) {
        Student student;
        std::cout << "Students Name: ";
        std::cin >> student.surname;
        std::cout << "course;: ";
        std::cin >> student.course;

        int spec;
        std::cout << "specific (0 - ComputerScience, 1 - Informatics, 2 - MathEconomics, 3 - PhysicsInformatics, 4 - LaborTraining): ";
        std::cin >> spec;
        student.speciality = static_cast<Speciality>(spec);

        std::cout << "physics: ";
        std::cin >> student.physicsGrade;
        std::cout << "math: ";
        std::cin >> student.mathGrade;
        std::cout << "informatics: ";
        std::cin >> student.informaticsGrade;

        students.push_back(student);
    }
}

int countExcellentStudents(const std::vector<Student>& students) {
    int count = 0;
    for (const auto& student : students) {
        if (student.physicsGrade == 5 && student.mathGrade == 5 && student.informaticsGrade == 5) {
            count++;
        }
    }
    return count;
}

double calculatePhysicsGradePercentage(const std::vector<Student>& students) {
    int countWithGrade5 = 0;
    for (const auto& student : students) {
        if (student.physicsGrade == 5) {
            countWithGrade5++;
        }
    }
    return (static_cast<double>(countWithGrade5) / students.size()) * 100;
}

void displayStudents(const std::vector<Student>& students) {
    std::cout << "¹\tname\tcourse\tspecific\tphysic\tmath\tinform\n";
    for (size_t i = 0; i < students.size(); i++) {
        std::cout << i + 1 << "\t" << students[i].surname << "\t" << students[i].course << "\t";

        switch (students[i].speciality) {
        case ComputerScience: std::cout << "ComputerScience\t"; break;
        case Informatics: std::cout << "Informatics\t"; break;
        case MathEconomics: std::cout << "MathEconomics\t"; break;
        case PhysicsInformatics: std::cout << "PhysicsInformatics\t"; break;
        case LaborTraining: std::cout << "LaborTraining\t"; break;
        }

        std::cout << students[i].physicsGrade << "\t"
            << students[i].mathGrade << "\t"
            << students[i].informaticsGrade << "\n";
    }
}

int main() {
    int numberOfStudents;
    std::cout << "numberOfStudent: ";
    std::cin >> numberOfStudents;

    std::vector<Student> students;
    inputStudentData(students, numberOfStudents);

    displayStudents(students);

    int excellentCount = countExcellentStudents(students);
    double physicsGradePercentage = calculatePhysicsGradePercentage(students);

    std::cout << "excellent': " << excellentCount << "\n";
    std::cout << "physicsGradePercentag '5': " << physicsGradePercentage << "%\n";

    return 0;
}
