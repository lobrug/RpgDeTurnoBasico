#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include <iostream>
#include <string>

class Item {
    public:
        Item(std::string n) : name(n) {}
        virtual void show() const = 0;
        virtual ~Item() {}
    protected:
        std::string name;

};

#endif ITEM_H_INCLUDED