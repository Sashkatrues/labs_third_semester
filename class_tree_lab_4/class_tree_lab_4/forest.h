#ifndef FOREST_H
#define FOREST_H

#include "tree.h"

class ForestTree : public Tree
{
protected:
    double wood_amount;
public:
    ForestTree(const std::string& name,
        int age,
        TreeType type,
        double wood_amount);

    double get_wood_amount() const;
    void set_wood_amount(double new_amount);

    void print_info() const override;
};

#endif
