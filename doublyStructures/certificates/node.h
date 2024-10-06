#include <iostream>
#include "person.h"
using namespace std;

struct node{
    Person* person;
    node* next;
    node* prev;  
};