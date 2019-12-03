#pragma once

#include "item.hpp"

#include <vector>

/**
 * @brief The Model class
 *
 * Singleton model
 *
 * Provide access to application's data from anywhere
 *
 * Contains list of items
 */
class Model {
private:
    static Model * instance;

    std::vector<Item *> items;

public:
    static Model * getInstance() {
        if (instance == nullptr) instance = new Model;
        return instance;
    }

    std::vector<Item*>& getItems() { return items; }

};

Model * Model::instance = nullptr;
