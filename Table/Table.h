#include <iostream>
using namespace std;
#ifndef SDIZOPROJECT_TABLE_H
#define SDIZOPROJECT_TABLE_H


class Table {

public:

    int *tab; // pointer to the beginning of the table

    int size; // size of the table


    //Methods

    Table();

    ~Table();

    void loadFromFile(string fileName);

    bool IsValueInTable(int val);

    void addValue(int index, int value);

    void addValueFront(int value);

    void addValueBack(int value);

    void deleteFromTableFront();

    void deleteFromTableBack();

    void deleteFromTable(int index);

    void display();

    void generateTable(int size);



};


#endif //SDIZOPROJECT_TABLE_H
