#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

enum Status {
    PASS,
    FAIL
};

struct Student {
    int id;
    string name;
    double mark1;
    double mark2;
    double mark3;
    double average;
    Status status;
};
int main() {
    Student students[5];
    for (int i = 0; i < 5; i++) {
        cout << "\nEnter details for Student " << i + 1 << endl;
        cout << "Enter ID: ";
        cin >> students[i].id;
        cout << "Enter name: ";
        cin >> students[i].name;
        cout << "Enter first mark: ";
        cin >> students[i].mark1;
        cout << "Enter second mark: ";
        cin >> students[i].mark2;
        cout << "Enter third mark: ";
        cin >> students[i].mark3;
        students[i].average =
            (students[i].mark1 +
             students[i].mark2 +
             students[i].mark3) / 3;
        if (students[i].average >= 50) {
            students[i].status = PASS;
        } else {
            students[i].status = FAIL;
        }
    }

    cout << " ";

    cout << left
         << setw(10) << "ID"
         << setw(15) << "NAME"
         << setw(12) << "AVERAGE"
         << "STATUS" << endl;

    cout << " ";

    for (int i = 0; i < 5; i++) {

        cout << left
             << setw(10) << students[i].id
             << setw(15) << students[i].name
             << setw(12) << fixed << setprecision(2)
             << students[i].average;

        if (students[i].status == PASS) {
            cout << "PASS";
        } else {
            cout << "FAIL";
        }

        cout << endl;
    }

    int searchID;

    cout << "\nEnter student ID to search: ";
    cin >> searchID;

    bool found = false;

    for (int i = 0; i < 5; i++) {

        if (students[i].id == searchID) {

            cout << "\nStudent found!" << endl;
            cout << "ID: " << students[i].id << endl;
            cout << "Name: " << students[i].name << endl;
            cout << "Average: " << students[i].average << endl;

            if (students[i].status == PASS) {
                cout << "Status: PASS" << endl;
            } else {
                cout << "Status: FAIL" << endl;
            }

            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student ID not found." << endl;
    }

    cout << " ";

    double test1 = 49.99;
    double test2 = 50.00;

    cout << "Average 49.99: "
         << (test1 >= 50 ? "PASS" : "FAIL") << endl;

    cout << "Average 50.00: "
         << (test2 >= 50 ? "PASS" : "FAIL") << endl;

    return 0;
}
