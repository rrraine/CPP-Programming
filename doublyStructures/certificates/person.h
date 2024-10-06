#include <iostream>
using namespace std;

struct Person{
    string firstName;
    string lastName;
    int age;
    int requests[4];


    void print_name(){
        cout << firstName << " " << lastName << " (" << age << ") ";
    }

    int requestCount(){
        int sum = 0;
        for (int i = 0; i < 4; i++){
            sum += requests[i];
        }
        return sum;
    }
};

typedef struct Person Person;