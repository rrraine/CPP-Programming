#include <iostream>
#include <cstdlib>
#include <cmath>
#include "student.h"

class Course {
    Student** student;
    int size, capacity;
    string topic;

    void reduce(){
        if (size <= capacity * 2.0 / 3){
            capacity = max(ceil(capacity * 0.75), 5.0);
            student = (Student**) realloc (student, capacity*sizeof(Student*));
        }       
    }

    void addSize(){
        if (size == capacity){
            capacity = ceil(capacity*1.5);
            student = (Student**) realloc (student, capacity*sizeof(Student*));
        }
    }
    public:

    Course(string topic){
        this->topic = topic;
        size = 0;
        capacity = 5;
        student = (Student**) calloc(capacity, sizeof(Student*));
    }

    void add(Student* s){
        addSize();
        student[size++] = s;

    }

    void addByName(Student* s){
     
        addSize();

        for (int i = 0; i < size; i++){
            if (student[i]->name.compare(s->name) > 0){
                size++;
                // shift students from left to right to insert the s

                for (int j = size - 1; j >= i; j--){
                    student[j] = student[j - 1];
                }
                student[i] = s;
                return;
            }
        }

        // else if sa huli ang student
        student[size++] = s;
        
    }

    void addByYear(Student* s){
 
        addSize();
  
        for (int i = 0; i < size; i++){
            if (student[i]->year < s->year){
                size++;
                for (int j = size - 1; j >= i; j-- ){
                    student[j] = student[j - 1];
                }
                student[i] = s;
                addSize();

            }
        }
        student[size++] = s;
    }
    // return the course
    string remove(string name){
        string course;
        for (int i = 0; i < size; i++){
            if (name == student[i]->name){
                course = student[i]->course;
                Student* temp = student[i];
                for (int j = i; j < size - 1; j++){
                    student[j] = student[j + 1];
                }
                size--;
                reduce();
                free(temp);
                return course;
            }
        }
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