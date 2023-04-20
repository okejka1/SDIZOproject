#include "Menu.h"
#include "Table/Table.h"
#include "DoubleLinkedList/DoubleLinkedList.h"
#include "Heap/Heap.h"


void Menu::menuTable() {

    Table myTable;

    std::string fileName;

    int val;
    int index;
    int option = -1;
    numberOfTests = 100;

    do {
        std::cout << "\n==== TABLE MENU ====\n";
        std::cout << "1.Load your table from file\n";
        std::cout << "2.Delete\n";
        std::cout << "3.Add\n";
        std::cout << "4.Find entered value\n";
        std::cout << "5.Generate a table\n";
        std::cout << "6.Display the table\n";
        std::cout << "7.Time tests\n";
        std::cout << "8.Exit\n";
        std::cin >> option;

        std::cin.clear();
        fflush(stdin);

        switch (option) {

            case 1: // loading from a file
                std::cout << "Enter your file name:";
                std::cin >> fileName;
                fileName = "..\\Input\\" + fileName;
                myTable.loadFromFile(fileName);
                myTable.display();
                break;
            case 2: // deleting a value from given index
                std::cout << "Enter index:";
                std::cin >> index;
                myTable.deleteFromTable(index);
                myTable.display();
                break;
            case 3: // adding a given value to given index
                std::cout << "Enter index:";
                std::cin >> index;
                std::cout << "Enter value:";
                std::cin >> val;
                myTable.addValue(index, val);
                myTable.display();
                break;
            case 4: // searching for a given value
                std::cout << "Enter value:";
                std::cin >> val;
                myTable.IsValueInTable(val);
                break;
            case 5: // generating an array
                std::cout << "Enter the size of your array:";
                std::cin >> val;
                myTable.generateTable(val);
                myTable.display();
                break;
            case 6: // displaying a table
                myTable.display();
                break;
            case 7: // time measurements and some tests
                std::cout << "Enter the size of your array to conduct tests" << std::endl;
                std::cin >> val;
                myTable.generateTable(val);
                myTable.measureTime(numberOfTests,val);
                break;
            case 8: // exit
                break;
            default:
                std::cout << "Input error!\n";
                break;
        }
    } while (option != 8);
}

void Menu::menuList() {

    DoubleLinkedList myList;

    std::string fileName;
    int val;
    int option = -1;
    int index;
    numberOfTests = 100;


    do {
        std::cout << "\n==== LIST MENU ====\n";
        std::cout << "1.Load your list from file\n";
        std::cout << "2.Delete\n";
        std::cout << "3.Add\n";
        std::cout << "4.Find entered value\n";
        std::cout << "5.Generate a random list \n";
        std::cout << "6.Display the list\n";
        std::cout << "7.Time tests\n";
        std::cout << "8.Exit\n";
        std::cin >> option;

        std::cin.clear();
        fflush(stdin);

        switch (option) {

            case 1: // loading from a file
                std::cout << "Enter your file name:";
                std::cin >> fileName;
                fileName = "..\\Input\\" + fileName;
//                    myList.clear();
                myList.loadFromFile(fileName);
                myList.displayList();
                break;
            case 2: // deleting a value from given index
                std::cout << "Enter value:";
                std::cin >> val;
                myList.removeGiven(val);
//                myList.removeFromIndex(val);
                myList.displayList();
                break;
            case 3: // adding a given value to the list
                std::cout << "Enter index:";
                std::cin >> index;
                std::cout << "Enter value:";
                std::cin >> val;
                std::cout << std::endl;
                myList.addElement(index, val);
                myList.displayList();
                break;
            case 4: // searching for a given value
                std::cout << "Enter value:";
                std::cin >> val;
                myList.isValueInList(val);
                break;
            case 5: // generating an array
                std::cout << "Enter the size of your list:";
                std::cin >> val;
                myList.generateList(val);
                myList.displayList();
                break;
            case 6: // displaying a table
                myList.displayList();
                break;
            case 7: // time measurements and some tests
                std::cout << "Enter the size of your double linked list to conduct tests" << std::endl;
                std::cin >> val;
                myList.generateList(val);
                myList.measureTime(numberOfTests, val);

                break;
            case 8: // exit
                break;
            default:
                std::cout << "Input error!\n";
                break;
        }
    } while (option != 8);


}

void Menu::menuHeap() {

    Heap myHeap;



    std::string fileName;

    int val;
    int option = -1;
    numberOfTests = 100;


    do {
        std::cout << "\n==== TABLE MENU ====\n";
        std::cout << "1.Load your heap from file\n";
        std::cout << "2.Delete\n";
        std::cout << "3.Add\n";
        std::cout << "4.Find entered value\n";
        std::cout << "5.Generate the heap\n";
        std::cout << "6.Display the heap\n";
        std::cout << "7.Time tests\n";
        std::cout << "8.Exit\n";

        std::cin.clear();
        fflush(stdin);

        std::cin >> option;


        switch (option) {

            case 1: // loading from a file
                std::cout << "Enter your file name:";
                std::cin >> fileName;
                fileName = "..\\Input\\" + fileName;
                myHeap.loadFromFile(fileName);
                myHeap.displayHeap();
                break;
            case 2: // deleting a value from given index
                std::cout << "Enter value to deletion:";
                std::cin >> val;
                myHeap.deleteVal(val);
                myHeap.displayHeap();
                break;
            case 3: // adding a given value to the heap
                std::cout << "Enter value:";
                std::cin >> val;
                myHeap.insertVal(val);
                myHeap.displayHeap();
                break;
            case 4: // searching for a given value
                std::cout << "Enter value:";
                std::cin >> val;
                myHeap.isValInHeap(val);
                break;
            case 5: // generating the heap
                std::cout << "Enter the size of your heap";
                std::cin >> val;
                myHeap.generateHeap(val);
                myHeap.displayHeap();
                break;
            case 6: // displaying the heap
                myHeap.displayHeap();
                break;
            case 7: // time measurements and some tests
                std::cout << "Enter the size of your heap to conduct tests" << std::endl;
                std::cin >> val;
                myHeap.generateHeap(val);
                myHeap.measureTime(numberOfTests,val);
                break;
            case 8: // exit
                break;
            default:
                std::cout << "Input error!\n";
                break;
        }
    } while (option != 8);
}

