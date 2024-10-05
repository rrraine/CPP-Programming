#include <iostream>
#include <cstdlib>
#include <cmath>
#include "student.h"

class Course {
    Student** student;
    int size, capacity;
    string topic;

    void reduce(){

    }

    void addSize(){
        capacity = ceil(capacity*1.5);
        student = (Student**) realloc (student, capacity*sizeof(Student*));
    }
    public:

    Course(string topic){
        this->topic = topic;
        size = 0;
        capacity = 5;
        student = (Student**) calloc(capacity, sizeof(Student*));
    }

    void add(Student* s){
        if (size == capacity){
            addSize();
        }

        student[size++] = s;

    }

    void addByName(Student* s){
        if (size == capacity){
            addSize();
        }
        
    }

    void addByYear(Student* s){
        if (size == capacity){
            addSize();
        }

    }

    string remove(string name){
        return "";
    }

    void print(){
        
        cout << "Size: " << size << "/" << capacity << endl;

        for (int i = 0; i < capacity; i++){
            if (i >= size){
                cout << i + 1 << ". (none)" << endl;
            } else {
                Student* s = student[i];
                cout << i + 1 << ". " << s->name << " (" << s->course << ") - " << s->year << endl;
            }
        }
    }




};