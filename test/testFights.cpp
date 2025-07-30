#include <iostream>
#include <vector>
#include "D:\CODES\RpgDeTurnoFoda\RpgDeTurnoBasico\include\Character.h"
#include "D:\CODES\RpgDeTurnoFoda\RpgDeTurnoBasico\include\Item.h"
#include "D:\CODES\RpgDeTurnoFoda\RpgDeTurnoBasico\include\Weapon.h"
#include "D:\CODES\RpgDeTurnoFoda\RpgDeTurnoBasico\include\Armor.h"

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

    Player.startFight(enemy1);
    Player.startFight(enemy2);
    Player.receiveItem(new Weapon("GodSlayer", 500));

    Player.exibirInventario();

    std::cout << Player.getLevel() << "-" << Player.getExp() << '\n';
    return 0;
}