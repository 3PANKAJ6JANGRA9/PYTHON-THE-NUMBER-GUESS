#include <iostream>
#include <fstream>
using namespace std;

class Student {
public:
    int roll;
    char name[50];
    float marks;

    void getData() {
        cout << "Enter Roll No: ";
        cin >> roll;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Marks: ";
        cin >> marks;
    }

    void showData() {
        cout << "Roll No: " << roll << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks << endl;
        cout << "-----------------------\n";
    }
};

void addStudent() {
    Student s;
    ofstream fout("student.txt", ios::app);
    s.getData();
    fout.write((char*)&s, sizeof(s));
    fout.close();
    cout << "Record added successfully!\n";
}

void showAll() {
    Student s;
    ifstream fin("student.txt");
    while (fin.read((char*)&s, sizeof(s))) {
        s.showData();
    }
    fin.close();
}

int main() {
    int choice;
    do {
        cout << "\n1. Add Record";
        cout << "\n2. Show All Records";
        cout << "\n3. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: addStudent(); break;
        case 2: showAll(); break;
        case 3: cout << "Exiting..."; break;
        default: cout << "Invalid Choice!\n";
        }
    } while (choice != 3);
    return 0;
}
