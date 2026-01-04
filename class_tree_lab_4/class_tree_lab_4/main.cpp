#include <iostream>
#include <string>
#include "tree_container.h"

void print_menu()
{
    std::cout << "\n===== MENU =====\n";
    std::cout << "1. Add forest tree\n";
    std::cout << "2. Add fruit tree\n";
    std::cout << "3. Print all trees\n";
    std::cout << "4. Print sorted trees\n";
    std::cout << "5. Statistics\n";
    std::cout << "6. Load from file\n";
    std::cout << "7. Exit\n";
    std::cout << "=======================\n";
    std::cout << "Choose option: ";
}

int main()
{
    TreeContainer container;
    int choice = 0;

    while (true)
    {
        print_menu();
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 1)
        {
            std::string name;
            int age;
            int type_int;
            double wood;

            std::cout << "Enter tree name: ";
            std::getline(std::cin, name);
            std::cout << "Enter tree age: ";
            std::cin >> age;
            std::cout << "Enter type (0 - deciduous, 1 - coniferous): ";
            std::cin >> type_int;
            std::cout << "Enter wood amount (m3): ";
            std::cin >> wood;
            std::cin.ignore();

            TreeType t = (type_int == 0 ? TreeType::DECIDUOUS : TreeType::CONIFEROUS);
            container.add_tree(new ForestTree(name, age, t, wood));
            std::cout << "Forest tree added.\n";
        }
        else if (choice == 2)
        {
            std::string name;
            int age;
            int type_int;
            double harvest;
            int storage_days;

            std::cout << "Enter tree name: ";
            std::getline(std::cin, name);
            std::cout << "Enter tree age: ";
            std::cin >> age;
            std::cout << "Enter type (0 - deciduous, 1 - coniferous): ";
            std::cin >> type_int;
            std::cout << "Enter harvest mass (kg): ";
            std::cin >> harvest;
            std::cout << "Enter storage duration (days): ";
            std::cin >> storage_days;
            std::cin.ignore();

            TreeType t = (type_int == 0 ? TreeType::DECIDUOUS : TreeType::CONIFEROUS);
            container.add_tree(new FruitTree(name, age, t, harvest, storage_days));
            std::cout << "Fruit tree added.\n";
        }
        else if (choice == 3)
        {
            if (container.get_size() == 0)
            {
                std::cout << "No trees.\n";
            }
            else
            {
                container.print_all_trees();
            }
        }
        else if (choice == 4)
        {
            container.print_sorted_trees();
        }
        else if (choice == 5)
        {
            std::cout << "Deciduous trees: " << container.count_deciduous() << "\n";
            std::cout << "Coniferous trees: " << container.count_coniferous() << "\n";
            std::cout << "Forest trees: " << container.count_forest() << "\n";
            std::cout << "Fruit trees: " << container.count_fruit() << "\n";
        }
        else if (choice == 6)
        {
            std::string filename;
            std::cout << "Enter filename: ";
            std::getline(std::cin, filename);
            container.load_from_file(filename);
        }
        else if (choice == 7)
        {
            break;
        }
        else
        {
            std::cout << "Wrong option.\n";
        }
    }

    return 0;
}
