#pragma once

#include <QString>

/**
 * @brief The Item class
 *
 * Some item to display in list
 */
class Item {
private:
    QString name;
public:
    Item(QString name) : name(name) {}
    ~Item() = default;

    QString getName() { return name; }
};
