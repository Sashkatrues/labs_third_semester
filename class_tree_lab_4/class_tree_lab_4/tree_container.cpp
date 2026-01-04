#include "tree_container.h"
#include <algorithm>
#include <fstream>
#include <iostream>

TreeContainer::~TreeContainer()
{
    for (Tree* t : trees)
    {
        delete t;
    }
}

void TreeContainer::add_tree(Tree* tree)
{
    if (tree) {
        trees.push_back(tree);
    }
}

void TreeContainer::remove_tree(std::size_t index)
{
    if (index >= trees.size())
    {
        return;
    }
    delete trees[index];
    trees.erase(trees.begin() + static_cast<std::ptrdiff_t>(index));
}

void TreeContainer::print_all_trees() const
{
    for (const Tree* t : trees)
    {
        t->print_info();
    }
}

void TreeContainer::print_sorted_trees() const
{
    if (trees.empty())
    {
        std::cout << "No trees.\n";
        return;
    }
    std::vector<Tree*> sorted = trees;
    std::sort(sorted.begin(), sorted.end(), [](const Tree* a, const Tree* b)
    {
        if (a->get_name() != b->get_name())
        {
            return a->get_name() < b->get_name();
        }
        return a->get_age() > b->get_age();
    });

    std::cout << "\n===== TREES SORTED (name asc, age desc) =====\n";
    for (const Tree* t : sorted)
    {
        t->print_info();
    }
}

int TreeContainer::count_deciduous() const
{
    int c = 0;
    for (const Tree* t : trees)
    {
        if (t->get_type() == TreeType::DECIDUOUS)
        {
            ++c;
        }
    }
    return c;
}

int TreeContainer::count_coniferous() const
{
    int c = 0;
    for (const Tree* t : trees)
    {
        if (t->get_type() == TreeType::CONIFEROUS)
        {
            ++c;
        }
    }
    return c;
}

int TreeContainer::count_forest() const
{
    int c = 0;
    for (const Tree* t : trees)
    {
        if (dynamic_cast<const ForestTree*>(t))
        {
            ++c;
        }
    }
    return c;
}

int TreeContainer::count_fruit() const
{
    int c = 0;
    for (const Tree* t : trees)
    {
        if (dynamic_cast<const FruitTree*>(t))
        {
            ++c;
        }
    }
    return c;
}

void TreeContainer::load_from_file(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cout << "Cannot open file: " << filename << "\n";
        return;
    }
    std::string kind;
    std::string name;
    int age;
    int type_int;
    double param1;
    int param2;

    while (file >> kind)
    {
        file >> name >> age >> type_int;
        TreeType t = (type_int == 0 ? TreeType::DECIDUOUS : TreeType::CONIFEROUS);

        if (kind == "Forest")
        {
            file >> param1;
            add_tree(new ForestTree(name, age, t, param1));
        }
        else if (kind == "Fruit")
        {
            file >> param1 >> param2;
            add_tree(new FruitTree(name, age, t, param1, param2));
        }
    }
    file.close();
    std::cout << "Trees loaded from file.\n";
}

std::size_t TreeContainer::get_size() const
{
    return trees.size();
}
