#include <iostream>
#include

#ifndef SDIZOPROJECT_TABLE_H
#define SDIZOPROJECT_TABLE_H


class Table {

public:

    int *tab; // pointer to the beginning of the table

    int size; // size of the table

    long results[7] = {0, 0, 0, 0, 0, 0, 0}; // table to store time measurements for an array tests
/*
result[0] ->  inserting an element at the beginning of an array
result[1] ->  inserting an element at the end of an array
result[2] ->  inserting an element at the random position of an array
result[3] ->  deleting an element at the beginning of an array
result[4] ->  deleting an element at the end  of an array
result[5] ->  deleting an element at the random position of an array
result[6] ->  searching for a random element of an array
*/


    //Methods

    Table();

    ~Table();

    void loadFromFile(std::string fileName);

    bool IsValueInTable(int val);

    void addValue(int index, int value);

    void addValueFront(int value);

    void addValueBack(int value);

    void deleteFromTableFront();

    void deleteFromTableBack();

    void deleteFromTable(int index);

    void display();

    void generateTable(int size);


   // void measureTime(int sizeOfStructure, long long *results, int numberOfTests);

    void measureTime(int numberOfTests);

    void measureTime();
};


#endif //SDIZOPROJECT_TABLE_H
