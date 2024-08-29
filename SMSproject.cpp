#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    int rollNo;
    string name;
    string fatherName;
    string mobile;
    string dob;
    string address;
};

Student students[50]; // Array to store student records
int totalStudents = 0; // Total number of students

void saveToFile() {
    ofstream outFile("student_records.txt"); // Open file for writing
    if (!outFile) {
        cout << "Error opening file for writing\n";
        return;
    }
    for (int i = 0; i < totalStudents; i++) {
        outFile << students[i].rollNo << "\n";
        outFile << students[i].name << "\n";
        outFile << students[i].fatherName << "\n";
        outFile << students[i].mobile << "\n";
        outFile << students[i].dob << "\n";
        outFile << students[i].address << "\n";
    }
    outFile.close();
    cout << "Student records saved to file.\n";
}

void loadFromFile() {
    ifstream inFile("student_records.txt"); // Open file for reading
    if (!inFile) {
        cout << "Error opening file for reading.\n";
        return;
    }
    totalStudents = 0;
    while (inFile >> students[totalStudents].rollNo) {
        inFile.ignore();
        getline(inFile, students[totalStudents].name);
        getline(inFile, students[totalStudents].fatherName);
        getline(inFile, students[totalStudents].mobile);
        getline(inFile, students[totalStudents].dob);
        getline(inFile, students[totalStudents].address);
        totalStudents++;
    }
    inFile.close();
    cout << "Student records loaded successfully.\n";
}

void addStudent() {
    cout << "Enter student details:\n";
    cout << "Roll No: ";
    cin >> students[totalStudents].rollNo;
    cin.ignore(); // Clear newline character from buffer
    cout << "Name: ";
    getline(cin, students[totalStudents].name);
    cout << "Father's Name: ";
    getline(cin, students[totalStudents].fatherName);
    cout << "Mobile: ";
    getline(cin, students[totalStudents].mobile);
    cout << "Date of Birth (DD/MM/YYYY): ";
    getline(cin, students[totalStudents].dob);
    cout << "Address: ";
    getline(cin, students[totalStudents].address);

    totalStudents++;
    cout << "Student added successfully!\n";
}

void displayStudent() {
    int roll;
    cout << "Enter roll number to display details: ";
    cin >> roll;

    for (int i = 0; i < totalStudents; i++) {
        if (students[i].rollNo == roll) {
            cout << "Student Details:\n";
            cout << "Roll No: " << students[i].rollNo << "\n";
            cout << "Name: " << students[i].name << "\n";
            cout << "Father's Name: " << students[i].fatherName << "\n";
            cout << "Mobile: " << students[i].mobile << "\n";
            cout << "Date of Birth: " << students[i].dob << "\n";
            cout << "Address: " << students[i].address << "\n";
            return;
        }
    }
    cout << "Student with Roll No " << roll << " not found.\n";
}

void editStudent() {
    int roll;
    cout << "Enter Roll No of the student to edit: ";
    cin >> roll;
    cin.ignore(); // Clear newline character from buffer

    for (int i = 0; i < totalStudents; i++) {
        if (students[i].rollNo == roll) {
            cout << "Enter new name: ";
            getline(cin, students[i].name);
            cout << "Enter new father's name: ";
            getline(cin, students[i].fatherName);
            cout << "Enter new mobile number: ";
            getline(cin, students[i].mobile);
            cout << "Enter new date of birth (DD/MM/YYYY): ";
            getline(cin, students[i].dob);
            cout << "Enter new address: ";
            getline(cin, students[i].address);

            cout << "Student details updated successfully!\n";
            return;
        }
    }
    cout << "Student with Roll No " << roll << " not found.\n";
}
  
    void deleteStudent(){
        int roll;
        cout<<"Enter roll number: ";
        cin>>roll;
        cin.ignore();
        
        int indexToDelete = -1;
    for (int i = 0; i < totalStudents; i++) {
        if (students[i].rollNo == roll) {
            indexToDelete = i;
            break;
        }
    }
    if (indexToDelete == -1) {
        cout << "No student found with Roll Number " << roll << ". Please check and try again.\n";
        return;
 }
  // Shift all students after the deleted student one position up
    for (int i = indexToDelete; i < totalStudents - 1; i++) {
        students[i] = students[i + 1];
    }

    totalStudents--;
    cout << "Student with Roll Number " << roll << " has been deleted successfully!\n";
}

int main() {
    int choice;
    loadFromFile();
    while (true) {
        cout << "\nStudent Management System\n";
        cout << "1. Add Student\n";
        cout << "2. Display Student Details\n";
        cout << "3. Edit Student Details\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear newline character from buffer

        switch (choice) {
            case 1:
                addStudent();
                saveToFile();
                break;
            case 2:
                displayStudent();
                break;
            case 3:
                editStudent();
                saveToFile(); // Save changes after editing
                break;
            case 4:
                deleteStudent();
                saveToFile(); // Save changes after deleting
                break;
            case 5:
                cout << "Exiting program. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}
