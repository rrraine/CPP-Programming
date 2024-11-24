// array.hpp
// DO NOT modify this file.
// Only handle main.cpp
#pragma once
#include <iostream>
using namespace std;

class List {
    public:
    virtual void add(int num) = 0;
    virtual int& get(int pos) = 0;
    virtual int remove(int num) = 0;
    virtual void print() = 0;
};