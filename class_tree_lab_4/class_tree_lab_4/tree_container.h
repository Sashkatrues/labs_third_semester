#ifndef TREE_CONTAINER_H
#define TREE_CONTAINER_H

#include <vector>
#include <string>
#include "tree.h"
#include "forest.h"
#include "fruit.h"

class TreeContainer
{
private:
    std::vector<Tree*> trees;
public:
    TreeContainer() = default;
    ~TreeContainer();

    void add_tree(Tree* tree);
    void remove_tree(std::size_t index);

    void print_all_trees() const;
    void print_sorted_trees() const;

    int count_deciduous() const;
    int count_coniferous() const;
    int count_forest() const;
    int count_fruit() const;

    void load_from_file(const std::string& filename);

    std::size_t get_size() const;
};

#endif
