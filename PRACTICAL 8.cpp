#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <limits>
using namespace std;

int main() {
    string fullName;
    string firstName;
    string username;
    string text1, text2;
    int studentID;

    cout << "STRING OPERATIONS - USERNAME GENERATOR" << endl;
    cout << "--------------------------------------" << endl;

    cout << "Enter your full name: ";
    getline(cin, fullName);

    if (fullName.empty()) {
        cout << "Name cannot be empty." << endl;
        return 0;
    }

    cout << "Length of your name: " << fullName.length() << endl;
    cout << "First character: " << fullName[0] << endl;

    if (fullName.find(' ') != string::npos) {
        cout << "Your name contains a space." << endl;
    } else {
        cout << "Your name does not contain a space." << endl;
    }

    size_t spacePosition = fullName.find(' ');
    firstName = fullName.substr(0, spacePosition);

    string shortName = firstName.substr(0, 3);

    for (int i = 0; i < shortName.length(); i++) {
        shortName[i] = tolower(shortName[i]);
    }

    cout << "Enter your student ID: ";
    cin >> studentID;

    stringstream ss;
    ss << studentID;

    username = shortName + ss.str();

    cout << "Generated username: " << username << endl;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\nEnter the first string: ";
    getline(cin, text1);

    cout << "Enter the second string: ";
    getline(cin, text2);

    if (text1 == text2) {
        cout << "The two strings are equal." << endl;
    } else {
        cout << "The two strings are different." << endl;
    }

    return 0;
}
