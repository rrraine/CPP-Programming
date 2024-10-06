#include <iostream>
#include <cstdlib>
#include <cmath>
#include "student.h"

class Course {
    Student** student;
    Block** blocked;
    int size, capacity;
    int blockSize, blockCapacity = 5;

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

    void removeShift(int i){
         for (int j = i; i < size - 1; i++){
                    student[j] = student[j + 1];
                }
    }

    void increaseBlockCapacity(){
        if (blockSize == blockCapacity){
            capacity = ceil(blockCapacity * 1.5);
            blocked = (Block**)realloc(blocked, capacity * sizeof(Block*));
        }
    }
    public:

    Course(string topic){
        this->topic = topic;
        size = 0;
        capacity = 5;
        student = (Student**) calloc(capacity, sizeof(Student*));
        blocked = (Block**) calloc (blockCapacity, sizeof(Block*));
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

    int removeCheaters(string name) {
        int count = 0;

        for (int i = 0; i < size; i++){
            if (name == student[i]->name){
                // store the student in a temporary variable
                Student* temp = student[i];

                // shift the student to override the student
                removeShift(i);
                
                // reduced the size
                size--;

                // check if the size meet the needed condition for resizing
                reduce();
                count++; // increment count to track the number of cheaters

                blocked[blockSize++] = new Block(temp->course, temp->year);

                 Student *remove;
                for (int j = 0; j < size; j++) {
                    if (student[j]->course == temp->course && student[j]->year == temp->year) {
                        remove = student[j];
                        removeShift(j);
                        size--;
                        reduceCapacity();
                        count++;
                        j--;
                        free(remove);
                    }
                }
                free(temp);
                return count
                
        }
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


class Block{
    string program;
    int year;

    // create a contructor to immediately store the details
    Block(string program, int year) : program(program) , year(year) {};
};