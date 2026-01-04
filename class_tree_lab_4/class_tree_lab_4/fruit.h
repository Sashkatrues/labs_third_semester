#ifndef FRUIT_H
#define FRUIT_H

#include "tree.h"

class FruitTree : public Tree
{
protected:
    double harvest_mass;
    int storage_duration_days;
public:
    FruitTree(const std::string& name,
        int age,
        TreeType type,
        double harvest_mass,
        int storage_duration_days);

    double get_harvest_mass() const;
    int get_storage_duration_days() const;

    void set_harvest_mass(double new_mass);
    void set_storage_duration_days(int new_duration);

    void print_info() const override;
};

#endif
