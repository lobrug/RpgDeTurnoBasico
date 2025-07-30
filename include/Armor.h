#ifndef ARMOR_H_INCLUDED
#define ARMOR_H_INCLUDED

#include "Item.h"
#include <string>

class Armor : public Item{
    public:
        Armor(std::string n, short p) : Item(n), protection(p) {}

        void show() const override{
            std::cout << "Armor: " << name << " // " << "Protection: " << protection << '\n';
        }

    private:
        short protection;

};

#endif ARMOR_H_INCLUDED