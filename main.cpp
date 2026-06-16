#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int rollNo;
    float marks;

    void input() {
        cout << "\nEnter Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter Roll Number: ";
        cin >> rollNo;

        cout << "Enter Marks: ";
        cin >> marks;
    }

    void display() {
        cout << "\n-------------------";
        cout << "\nName: " << name;
        cout << "\nRoll No: " << rollNo;
        cout << "\nMarks: " << marks;
        cout << "\n-------------------\n";
    }
};

int main() {
    Student students[50];

    int count = 0;
    int choice;
    int searchRoll;
    bool found;

    do {
        cout << "\n===== STUDENT MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Student\n";
        cout << "2. Show Students\n";
        cout << "3. Search Student\n";
        cout << "4. Exit\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            if (count < 50) {
                students[count].input();
                count++;
                cout << "\nStudent Added!\n";
            }
            else {
                cout << "\nStorage Full!\n";
            }
            break;

        case 2:
            if (count == 0) {
                cout << "\nNo Students Added Yet.\n";
            }
            else {
                for (int i = 0; i < count; i++) {
                    students[i].display();
                }
            }
            break;

        case 3:
            found = false;

            cout << "\nEnter Roll Number: ";
            cin >> searchRoll;

            for (int i = 0; i < count; i++) {
                if (students[i].rollNo == searchRoll) {
                    students[i].display();
                    found = true;
                }
            }

            if (!found) {
                cout << "\nStudent Not Found.\n";
            }

            break;

        case 4:
            cout << "\nProgram Closed.\n";
            break;

        default:
            cout << "\nInvalid Choice.\n";
        }

    } while (choice != 4);

    return 0;
}
