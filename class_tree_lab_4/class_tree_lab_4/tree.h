#ifndef TREE_H
#define TREE_H

#include <string>
#include <iostream>

enum class TreeType
{
    DECIDUOUS = 0,
    CONIFEROUS = 1
};

class Tree
{
protected:
    std::string name;
    int age;
    TreeType type;
public:
    Tree(const std::string& name, int age, TreeType type);
    virtual ~Tree() = default;

    const std::string& get_name() const;
    int get_age() const;
    TreeType get_type() const;

    void set_name(const std::string& new_name);
    void set_age(int new_age);

    virtual void print_info() const = 0;
};

#endif
