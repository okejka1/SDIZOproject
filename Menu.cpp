#include "Menu.h"
#include "Table/Table.h"
#include "DoubleLinkedList/DoubleLinkedList.h"
#include "Heap/Heap.h"


using namespace std;

void Menu::menuTable() {

    Table myTable;

    string fileName;

    int val;
    int index;
    int option = -1;

    do {
        cout << "\n==== TABLE MENU ====\n";
        cout << "1.Load your table from file\n";
        cout << "2.Delete\n";
        cout << "3.Add\n";
        cout << "4.Find entered value\n";
        cout << "5.Generate a table\n";
        cout << "6.Display the table\n";
        cout << "7.Time tests\n";
        cout << "8.Exit\n";
        cin >> option;

        std::cin.clear();
        fflush(stdin);

        switch (option) {

            case 1: // loading from a file
                cout << "Enter your file name:";
                cin >> fileName;
                fileName = "..\\Input\\" + fileName;
                myTable.loadFromFile(fileName);
                myTable.display();
                break;
            case 2: // deleting a value from given index
                cout << "Enter index:";
                cin >> index;
                myTable.deleteFromTable(index);
                myTable.display();
                break;
            case 3: // adding a given value to given index
                cout << "Enter index:";
                cin >> index;
                cout << "Enter value:";
                cin >> val;
                myTable.addValue(index, val);
                myTable.display();
                break;
            case 4: // searching for a given value
                cout << "Enter value:";
                cin >> val;
                myTable.IsValueInTable(val);
                break;
            case 5: // generating an array
                cout << "Enter the size of your array:";
                cin >> val;
                myTable.generateTable(val);
                myTable.display();
                break;
            case 6: // displaying a table
                myTable.display();
                break;
            case 7: // time measurements and some tests
                break;
            case 8: // exit
                break;
            default:
                cout << "Input error!\n";
                break;
        }
    } while (option != 8);
}

void Menu::menuList() {

    DoubleLinkedList myList;

    string fileName;
    int val;
    int option = -1;
    int index;

    do {
        cout << "\n==== LIST MENU ====\n";
        cout << "1.Load your list from file\n";
        cout << "2.Delete\n";
        cout << "3.Add\n";
        cout << "4.Find entered value\n";
        cout << "5.Generate a random list \n";
        cout << "6.Display the list\n";
        cout << "7.Time tests\n";
        cout << "8.Exit\n";
        cin >> option;

        std::cin.clear();
        fflush(stdin);

        switch (option) {

            case 1: // loading from a file
                cout << "Enter your file name:";
                cin >> fileName;
                fileName = "..\\Input\\" + fileName;
//                    myList.clear();
                myList.loadFromFile(fileName);
                myList.displayList();
                break;
            case 2: // deleting a value from given index
                cout << "Enter value:";
                cin >> val;
                myList.removeGiven(val);
                myList.displayList();
                break;
            case 3: // adding a given value to the list
                cout << "Enter index:";
                cin >> index;
                cout << "Enter value:";
                cin >> val;
                cout << endl;
                myList.addElement(index, val);
                myList.displayList();
                break;
            case 4: // searching for a given value
                cout << "Enter value:";
                cin >> val;
                myList.isValueInList(val);
                break;
            case 5: // generating an array
                cout << "Enter the size of your list:";
                cin >> val;
                myList.generateList(val);
                myList.displayList();
                break;
            case 6: // displaying a table
                myList.displayList();
                break;
            case 7: // time measurements and some tests
                break;
            case 8: // exit
                break;
            default:
                cout << "Input error!\n";
                break;
        }
    } while (option != 8);


}

void Menu::menuHeap() {

    Heap myHeap;


    string fileName;

    int val;
    int option = -1;

    do {
        cout << "\n==== TABLE MENU ====\n";
        cout << "1.Load your heap from file\n";
        cout << "2.Delete\n";
        cout << "3.Add\n";
        cout << "4.Find entered value\n";
        cout << "5.Generate the heap\n";
        cout << "6.Display the heap\n";
        cout << "7.Time tests\n";
        cout << "8.Exit\n";
        cin >> option;

        std::cin.clear();
        fflush(stdin);

        switch (option) {

            case 1: // loading from a file
//                cout << "Enter your file name:";
//                cin >> fileName;
//                fileName = "..\\Input\\" + fileName;
//                myHeap.loadFromFile(fileName);
//                myHeap.display();
//                break;
            case 2: // deleting a value from given index
//                cout << "Enter index:";
//                cin >> index;
//                myHeap.deleteFromTable(index);
//                myHeap.display();
//                break;
            case 3: // adding a given value to the heap
                cout << "Enter value:";
                cin >> val;
                myHeap.insertVal(val);
                myHeap.displayHeap();
                break;
//            case 4: // searching for a given value
//                cout << "Enter value:";
//                cin >> val;
//                myHeap.IsValueInTable(val);
//                break;
            case 5: // generating the heap
                cout << "Enter the size of your heap:";
                cin >> val;
                myHeap.generateHeap(val);
                myHeap.displayHeap();
                break;
            case 6: // displaying the heap
                myHeap.displayHeap();
                break;
            case 7: // time measurements and some tests
                break;
            case 8: // exit
                break;
            default:
                cout << "Input error!\n";
                break;
        }
    } while (option != 8);
}

