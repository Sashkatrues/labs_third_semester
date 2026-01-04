#include "forest.h"
#include <iomanip>

ForestTree::ForestTree(const std::string& name, int age, TreeType type, double wood_amount) : Tree(name, age, type), wood_amount(wood_amount) {}

double ForestTree::get_wood_amount() const
{
    return wood_amount;
}

void ForestTree::set_wood_amount(double new_amount)
{
    wood_amount = new_amount;
}

void ForestTree::print_info() const
{
    std::cout << "Forest tree | Name: " << name
        << " | Age: " << age
        << " | Type: " << (type == TreeType::DECIDUOUS ? "Deciduous" : "Coniferous")
        << " | Wood amount: " << std::fixed << std::setprecision(2) << wood_amount
        << " m3\n";
}
