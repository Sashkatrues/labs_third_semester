#include "fruit.h"
#include <iomanip>

FruitTree::FruitTree(const std::string& name, int age, TreeType type, double harvest_mass, int storage_duration_days) : Tree(name, age, type), harvest_mass(harvest_mass), storage_duration_days(storage_duration_days) {}

double FruitTree::get_harvest_mass() const
{
    return harvest_mass;
}

int FruitTree::get_storage_duration_days() const
{
    return storage_duration_days;
}

void FruitTree::set_harvest_mass(double new_mass)
{
    harvest_mass = new_mass;
}

void FruitTree::set_storage_duration_days(int new_duration)
{
    storage_duration_days = new_duration;
}

void FruitTree::print_info() const
{
    std::cout << "Fruit tree | Name: " << name
        << " | Age: " << age
        << " | Type: " << (type == TreeType::DECIDUOUS ? "Deciduous" : "Coniferous")
        << " | Harvest mass: " << std::fixed << std::setprecision(2) << harvest_mass
        << " kg | Storage duration: " << storage_duration_days << " days\n";
}
