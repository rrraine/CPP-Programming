#include <iostream>
#include "course.cpp"
using namespace std;

int main(){
    Course *s = new Course("CSIT221");
    char op; 
    string name, rem;
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

            case 'n':
                student = new Student;
                cout << "Enter name: ";
                cin.ignore();
                getline(cin, student->name);
                cout << "Enter program: ";
                cin >> student->course;
                cout << "Enter year: ";
                cin >> student->year;
                s->addByName(student);
                break;

            case 'y':
                student = new Student;
                cout << "Enter name: ";
                cin.ignore();
                getline(cin, student->name);
                cout << "Enter program: ";
                cin >> student->course;
                cout << "Enter year: ";
                cin >> student->year;
                s->addByYear(student);
                break;
            case 'r':
                cout << "Who to remove? ";
                cin.ignore();
                getline(cin, name);
                rem = s->remove(name);
                if (rem != ""){
                    cout << "A student removed from " << rem << endl;
                } else {
                    cout << "No student removed." << endl;
                }
            case 'c':
                cout << "Who cheated?: ";
                cin >> name;
                cout << "Remove " << s->removeCheaters(name) << " student/s" << endl;
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