#include <iostream>
#include "course.cpp"
using namespace std;

int main(){
    Course *s = new Course("CSIT221");
    char op;
    Student* student;

    do {
        cout << "Enter op: ";
        cin >> op;

        switch (op) {
            case 'a':
                student = new Student;
                cout << "Enter name: ";
                cin.ignore();
                getline(cin, student->name);
                cout << "Enter program: ";
                cin >> student->course;
                cout << "Enter year: ";
                cin >> student->year;
                s->add(student);
                break;
            case 'p':
                s->print();
                break;
            case 'x':
                cout << "Exiting...";
                break;
            
        }
    } while (op != 'x');
    return 0;
}