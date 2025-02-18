#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <map>
#include <algorithm>
#include <numeric>
#include "Student1.h"
#include "Subject.h"

using namespace std;



class Group {
private:
    string name;
    vector<Student> students;
    vector<Subject> subjects;

public:
    Group(const string& name) : name(name) {}

    void addStudent(const Student& student) {
        students.push_back(student);
    }

    void addSubject(const Subject& subject) {
        subjects.push_back(subject);
    }

    void printGrades() const {
        cout << "Grades for group: " << name << endl;
        for (const auto& subject : subjects) {
            cout << subject.getName() << ": ";
            for (const auto& student : students) {
                const auto& grades = student.getGrades();
                cout << student.getName() << " - "
                    << (grades.size() > 0 ? grades[&student - &students[0]] : 0) << ", ";
            }
            cout << endl;
        }
    }

    void printAverageGrades() const {
        cout << "Average grades for students:" << endl;
        for (const auto& student : students) {
            cout << student.getName() << ": " << fixed << setprecision(2)
                << student.getAverageGrade() << endl;
        }
    }

    void printGroupAverage() const {
        double total = 0.0;
        int count = 0;
        for (const auto& student : students) {
            total += student.getAverageGrade();
            count++;
        }
        cout << "Group average: " << (count > 0 ? total / count : 0.0) << endl;
    }

    const vector<Student>& getStudents() const { return students; }
    const vector<Subject>& getSubjects() const { return subjects; }
};

void loadData(Group& group, const string& studentsFile, const string& subjectsFile, const string& gradesFile) {

    ifstream subjectsStream(subjectsFile);
    string subjectName;
    while (getline(subjectsStream, subjectName)) {
        group.addSubject(Subject(subjectName));
    }

    ifstream studentsStream(studentsFile);
    string studentName;
    while (getline(studentsStream, studentName)) {
        group.addStudent(Student(studentName));
    }


    ifstream gradesStream(gradesFile);
    string line;
    while (getline(gradesStream, line)) {
        istringstream iss(line);
        string name;
        iss >> name;
        double grade;
        for (size_t i = 0; i < group.getSubjects().size(); ++i) {
            if (iss >> grade) {
                for (auto& student : group.getStudents()) {
                    if (student.getName() == name) {
                        student.addGrade(grade);
                    }
                }
            }
        }
    }
};

