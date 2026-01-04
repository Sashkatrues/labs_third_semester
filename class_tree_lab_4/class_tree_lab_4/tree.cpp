#include "tree.h"

Tree::Tree(const std::string& name, int age, TreeType type) : name(name), age(age), type(type) {}

const std::string& Tree::get_name() const
{
    return name;
}

int Tree::get_age() const
{
    return age;
}

TreeType Tree::get_type() const
{
    return type;
}

void Tree::set_name(const std::string& new_name)
{
    name = new_name;
}

void Tree::set_age(int new_age)
{
    age = new_age;
}
