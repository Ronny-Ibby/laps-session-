#include <iostream>
using namespace std;

int main() {
    int marks[8];
    int sum = 0;
    int minimum, maximum;
    int passCount = 0;

    cout << "CLASS RESULTS ANALYZER" << endl;
    cout << "----------------------" << endl;

    for (int i = 0; i < 8; i++) {
        cout << "Enter mark for student " << i + 1 << ": ";
        cin >> marks[i];

        if (marks[i] < 0 || marks[i] > 100) {
            cout << "Invalid mark. Enter a mark between 0 and 100." << endl;
            i--;
            continue;
        }

        sum += marks[i];

        if (i == 0) {
            minimum = marks[i];
            maximum = marks[i];
        } else {
            if (marks[i] < minimum)
                minimum = marks[i];

            if (marks[i] > maximum)
                maximum = marks[i];
        }

        if (marks[i] >= 50)
            passCount++;
    }

    double average = (double)sum / 8;

    cout << "\nCLASS RESULTS" << endl;
    cout << "--------------" << endl;

    for (int i = 0; i < 8; i++) {
        cout << "Student " << i + 1 << ": " << marks[i] << endl;
    }

    cout << "\nTotal marks: " << sum << endl;
    cout << "Average mark: " << average << endl;
    cout << "Highest mark: " << maximum << endl;
    cout << "Lowest mark: " << minimum << endl;
    cout << "Number of passes: " << passCount << endl;
    cout << "Number of failures: " << 8 - passCount << endl;

    int searchMark;
    bool found = false;

    cout << "\nEnter a mark to search for: ";
    cin >> searchMark;

    for (int i = 0; i < 8; i++) {
        if (marks[i] == searchMark) {
            cout << "Mark found for Student " << i + 1 << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Mark not found." << endl;
    }

    return 0;
}
