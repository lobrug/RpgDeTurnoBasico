#ifndef WEAPON_H_INCLUDED
#define WEAPON_H_INCLUDED

#include <iostream>
#include "Item.h"

class Weapon : public Item{
    public:
        Weapon(std::string n, short d) : Item(n), damage(d) {}

        void show() const override{
            std::cout << "Weapon: " << name << " // " << "Damage: " << damage << '\n';
        }

    private:
        short damage;
};
#endif WEAPON_H_INCLUDED