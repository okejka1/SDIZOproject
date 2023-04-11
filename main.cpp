#include <iostream>
#include "Menu.h"

using namespace std;


int main() {

    Menu menu;
    int option = -1;

    cout << "Structures of algorithms and computational complexity - Mikolaj Hajder 264478" << endl;

    do {
        cout << "\n==== MAIN MENU ====\n";
        cout << "1.Table\n";
        cout << "2.List\n";
        cout << "3.Heap\n";
        cout << "4.Exit\n";
        cout << "Choose an option: ";
        cin >> option;

        std::cin.clear();
        fflush(stdin);

        switch (option) {

            case 1:
                cout << "You've chosen a table!\n";
                menu.menuTable();
                break;
            case 2:
                cout << "You've chosen a list!\n";
                menu.menuList();
                break;
            case 3:
                cout << "You've chosen a heap!\n";
                menu.menuHeap();
                break;
            case 4:
                cout << "bye\n";
                break;
            default:
                cout << "Input error! - make sure to chose an option available from the main menu!";
                break;
        }
    } while (option != 4);

}

