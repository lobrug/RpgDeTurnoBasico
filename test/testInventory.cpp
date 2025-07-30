#include <iostream>
#include <vector>
#include "D:\CODES\RpgDeTurnoFoda\RpgDeTurnoBasico\class\Character.h"
#include "D:\CODES\RpgDeTurnoFoda\RpgDeTurnoBasico\class\Item.h"
#include "D:\CODES\RpgDeTurnoFoda\RpgDeTurnoBasico\class\Weapon.h"
#include "D:\CODES\RpgDeTurnoFoda\RpgDeTurnoBasico\class\Armor.h"

// int map[10][20] = {
//     {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//     {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//     {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//     {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//     {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//     {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//     {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//     {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//     {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//     {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},

// };

int main(){
    Character Player("Lorenzo");
    Character enemy1("Estrupilson jr.");
    Character enemy2("FilhoDAputa");

    Player.receiveItem(new Weapon("GodSlayer", 500));
    Player.receiveItem(new Armor("Armor of god", 1000));
    Player.receiveItem(new Weapon("GodSlayer", 500));
    Player.receiveItem(new Armor("Armor of god", 1000));
    Player.receiveItem(new Weapon("GodSlayer", 500));
    Player.receiveItem(new Armor("Armor of god", 1000));
    Player.receiveItem(new Weapon("GodSlayer", 500));
    Player.receiveItem(new Armor("Armor of god", 1000));
    Player.receiveItem(new Weapon("GodSlayer", 500));
    Player.receiveItem(new Armor("Armor of god", 1000));
    Player.receiveItem(new Weapon("GodSlayer", 500));


    Player.exibirInventario();

    return 0;
}