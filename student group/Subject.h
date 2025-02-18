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

using namespace std;

class Subject {
private:
    string name;

public:
    Subject(const string& name) : name(name) {}
    string getName() const { return name; }
};

class Student {
private:
    string name;
    vector<double> grades;

public:
    Student(const string& name) : name(name) {}

    void addGrade(double grade) {
        grades.push_back(grade);
    }

    string getName() const { return name; }
    const vector<double>& getGrades() const { return grades; }

    double getAverageGrade() const {
        if (grades.empty()) return 0.0;
        double sum = accumulate(grades.begin(), grades.end(), 0.0);
        return sum / grades.size();
    }
};

