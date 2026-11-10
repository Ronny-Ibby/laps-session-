#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>

using namespace std;

struct Student {
    int id;
    string name;
    double mark1, mark2, mark3;
    double average;
};

bool compareStudents(const Student& first, const Student& second) {
    if (first.average == second.average)
        return first.id < second.id;

    return first.average > second.average;
}

bool hasPassed(const Student& student) {
    return student.average >= 50.0;
}

int main() {

    const double passThreshold = 50.0;

    vector<Student> students;

    Student s;

    s.id = 101;
    s.name = "Gladys";
    s.mark1 = 80;
    s.mark2 = 85;
    s.mark3 = 90;
    s.average = 0;
    students.push_back(s);

    s.id = 102;
    s.name = "Vitcory";
    s.mark1 = 60;
    s.mark2 = 70;
    s.mark3 = 65;
    s.average = 0;
    students.push_back(s);

    s.id = 103;
    s.name = "Carla";
    s.mark1 = 90;
    s.mark2 = 90;
    s.mark3 = 90;
    s.average = 0;
    students.push_back(s);

    s.id = 104;
    s.name = "Daniel";
    s.mark1 = 45;
    s.mark2 = 50;
    s.mark3 = 55;
    s.average = 0;
    students.push_back(s);

    s.id = 105;
    s.name = "Tiara";
    s.mark1 = 90;
    s.mark2 = 90;
    s.mark3 = 90;
    s.average = 0;
    students.push_back(s);

    s.id = 106;
    s.name = "Frank";
    s.mark1 = 40;
    s.mark2 = 45;
    s.mark3 = 48;
    s.average = 0;
    students.push_back(s);

    for (int i = 0; i < students.size(); i++) {
        students[i].average =
            (students[i].mark1 + students[i].mark2 +
             students[i].mark3) / 3.0;
    }

    cout << fixed << setprecision(2);

    cout << "ORIGINAL ORDER\n";

    for (int i = 0; i < students.size(); i++) {
        cout << students[i].id << " "
             << students[i].name << " "
             << students[i].average << '\n';
    }

    sort(students.begin(), students.end(), compareStudents);

    cout << "\nSORTED ORDER\n";

    for (int i = 0; i < students.size(); i++) {
        cout << students[i].id << " "
             << students[i].name << " "
             << students[i].average << '\n';
    }

    int passCount = count_if(
        students.begin(),
        students.end(),
        hasPassed
    );

    cout << "\nStudents with average at least "
         << passThreshold << ": " << passCount << '\n';
    cout << "\nTOP THREE STUDENTS\n";

    int limit = min(3, (int)students.size());

    for (int i = 0; i < limit; i++) {
        cout << i + 1 << ". "
             << students[i].name
             << " - " << students[i].average << '\n';
    }

    return 0;
}
