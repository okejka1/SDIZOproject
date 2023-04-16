#include <iostream>
#include "Menu.h"


int main() {

    Menu menu;
    int option = -1;

    std::cout << "Structures of algorithms and computational complexity - Mikolaj Hajder 264478" << std::endl;

    do {
        std::cout << "\n==== MAIN MENU ====\n";
        std::cout << "1.Table\n";
        std::cout << "2.List\n";
        std::cout << "3.Heap\n";
        std::cout << "4.Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> option;

        std::cin.clear();
        fflush(stdin);

        switch (option) {

            case 1:
                std::cout << "You've chosen a table!\n";
                menu.menuTable();
                break;
            case 2:
                std::cout << "You've chosen a list!\n";
                menu.menuList();
                break;
            case 3:
                std::cout << "You've chosen a heap!\n";
                menu.menuHeap();
                break;
            case 4:
                std::cout << "bye\n";
                break;
            default:
                std::cout << "Input error! - make sure to chose an option available from the main menu!";
                break;
        }
    } while (option != 4);

}

