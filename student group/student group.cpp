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
#include "Group.h"

using namespace std;

using namespace std;


int main() {
    setlocale(LC_ALL, "ru");

    Group group("Group A");

    string studentsFile, subjectsFile, gradesFile;
    cout << "Enter the name of the students file: ";
    cin >> studentsFile;
    cout << "Enter the name of the subjects file: ";
    cin >> subjectsFile;
    cout << "Enter the name of the grades file: ";
    cin >> gradesFile;

    loadData(group, studentsFile, subjectsFile, gradesFile);

    group.printGrades();
    group.printAverageGrades();
    group.printGroupAverage();

    return 0;
}