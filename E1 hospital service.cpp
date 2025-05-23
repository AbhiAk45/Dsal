/*
QUESTION:
    Consider a scenario for Hospital to cater services to different kinds of patients as Serious
    (top priority), b) non-serious (medium priority), c) General Checkup (Least priority).
    Implement the priority queue to cater services to the patients.

OUTPUT:
    Hospital Management System
    1. Add Patient
    2. Serve Patient
    3. Display Patients
    4. Exit
    Enter your choice: 1
    Enter patient name: ADMIN
    Enter patient priority: 1
    Patient added successfully.
    Hospital Management System
    1. Add Patient
    2. Serve Patient
    3. Display Patients
    4. Exit
    Enter your choice: 1
    Enter patient name: SOUL
    Enter patient priority: 4
    Patient added successfully.
    Hospital Management System
    1. Add Patient
    2. Serve Patient
    3. Display Patients
    4. Exit
    Enter your choice: 2
    Serving patient: ADMIN
    Hospital Management System
    1. Add Patient
    2. Serve Patient
    3. Display Patients
    4. Exit
    Enter your choice: 3
    Patients in the queue:
    Name: SOUL, Priority: 4

*/


#include <iostream>
#include <queue>
#include <string>

using namespace std;

// Structure to represent a patient
struct Patient {
    string name;
    int priority; // Priority of the patient, lower value means higher priority

    // Constructor
    Patient(const string& name, int priority) : name(name), priority(priority) {}

    // Overloading the < operator to compare patients based on priority
    bool operator<(const Patient& other) const {
        // Higher priority patients should come before lower priority ones
        return priority > other.priority;
    }
};

// Function to display the menu options
void displayMenu() {
    cout << "Hospital Management System\n";
    cout << "1. Add Patient\n";
    cout << "2. Serve Patient\n";
    cout << "3. Display Patients\n";
    cout << "4. Exit\n";
}

int main() {
    priority_queue<Patient> patients; // Priority queue to store patients

    int choice;
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name;
                int priority;
                cout << "Enter patient name: ";
                cin >> name;
                cout << "Enter patient priority: ";
                cin >> priority;
                patients.push(Patient(name, priority));
                cout << "Patient added successfully.\n";
                break;
            }
            case 2: {
                if (patients.empty()) {
                    cout << "No patients to serve.\n";
                } else {
                    cout << "Serving patient: " << patients.top().name << endl;
                    patients.pop();
                }
                break;
            }
            case 3: {
                if (patients.empty()) {
                    cout << "No patients in the queue.\n";
                } else {
                    cout << "Patients in the queue:\n";
                    priority_queue<Patient> temp = patients; // Create a copy of the priority queue
                    while (!temp.empty()) {
                        cout << "Name: " << temp.top().name << ", Priority: " << temp.top().priority << endl;
                        temp.pop();
                    }
                }
                break;
            }
            case 4: {
                cout << "Exiting program.\n";
                break;
            }
            default: {
                cout << "Invalid choice. Please try again.\n";
                break;
            }
        }
    } while (choice != 4);

    return 0;
}

