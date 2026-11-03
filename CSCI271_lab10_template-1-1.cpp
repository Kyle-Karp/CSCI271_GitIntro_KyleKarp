// ===========================================
// CSCI 271 – Lab 10: Student Information Management (Struct + File I/O)
// Objective:
// Practice using struct, functions, and file I/O in C++.
// The program automatically creates sample student records,
// saves them to a file, reads them back, and displays results.
// ===========================================

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
// =======================
// Struct Definition
// =======================
struct Student {
    string id;
    string name;
    string major;
    string hobby;
    double gpa = 0;
    string email;
    string city;
};

// =======================
// Function Prototypes 
// =======================
void saveToFile(Student s[], int n, const string& filename);
int loadFromFile(Student s[], const string& filename);
void displayAll(Student s[], int n);
int countHonors(Student s[], int n);
void queryByCity(Student s[], int n, const string& city);

// =======================
// Function Definitions
// =======================

// Step 2 – Write all students to file
void saveToFile(Student s[], int n, const string& filename) {
    ofstream outFile(filename);
    for (int i = 0; i < n; i++) {
        outFile << s[i].id << " " << s[i].name << " " << s[i].major << " " << s[i].hobby
                << " " << s[i].gpa << " " << s[i].email << " " << s[i].city << endl;
    }
    outFile.close();
    cout << "[1] Data saved to " << filename << endl;
}

// Step 3 – Read students from file
int loadFromFile(Student s[], const string& filename) {
    ifstream inFile(filename);
    string line;
    int count = 0;

    while (inFile >> s[count].id >> s[count].name >> s[count].major >> s[count].hobby
                  >> s[count].gpa >> s[count].email >> s[count].city) {
        count++;
    }
    inFile.close();
    cout << "[2] Loaded " << count << " students from " << filename << endl;
    return count;
}

// Step 4 – Display all students
void displayAll(Student s[], int n) {
    cout << "\n[3] Displaying all students:" << endl;
    cout << "---------------------------------------" << endl;
    for (int f = 0; f < n; f++) {
        cout << s[f].id << " " << s[f].name << " (" << s[f].major << ") - " << s[f].city << " - GPA: " << s[f].gpa << endl;
    }
}

// Step 5 – Count students with GPA >= 3.0
int countHonors(Student s[], int n) {
    int count = 0;
    for (int g = 0; g < n; g++) {
        if (s[g].gpa >= 3.0) {
            count++;
        }
    }
    return count;
}

// Step 6 – Query by city
void queryByCity(Student s[], int n, const string& city) {
    cout << "\n[5] Students from " << city <<":" << endl;
    bool found = false;

    for (int c = 0; c < n; c++) {
        if (s[c].city == city) {
            cout << s[c].name << " (" << s[c].major << ", GPA " << s[c].gpa << ")\n";
            found = true;
        }
    }
    if (found != true) {
        cout << "No students found in that city." << endl;
    }
}

// =======================
// Main Function
// =======================
int main() {
    Student students[100];
    int n = 3;

    // Step 1 – Create and store sample data
    students[0] = {"S01", "Tom", "MATH", "Football", 2.8, "tom@google.com", "Modesto"};
    students[1] = {"S02", "Alice", "CS", "Reading", 3.5, "alice@google.com", "Modesto"};
    students[2] = {"S03", "Scott", "CS", "Basketball", 3.2, "scott@google.com", "SanJose"};

    // Step 2 – Write to file
    saveToFile(students, n, "students.txt");

    // Step 3 – Read back from file
    Student loaded[100];
    int count = loadFromFile(loaded, "students.txt");

    // Step 4 – Display all students
    displayAll(loaded, count);

    // Step 5 – Count honors students
    cout << "\n[4] Students with GPA >= 3.0: "
         << countHonors(loaded, count) << endl;

    // Step 6 – Query by city (example: Modesto)
    queryByCity(loaded, count, "Modesto");

    cout << "\nProgram finished." << endl;
    return 0;
}
