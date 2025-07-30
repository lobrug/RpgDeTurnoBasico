#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED

#include <iostream>
#include <string>
#include <vector> 
#include "Item.h"

class Character{
    public:
        std::string name;
        int posx, posy;

        Character(std::string name)
            :
            name(name), posx(1), posy(1), health(1000), mana(50), strength(20), exp(0), level(1) {}

        void receiveItem(Item* item){
            if(inventory.size() < 10) {
                inventory.push_back(item);
            }else{
                std::cout << "Not possible (Full Inventory)" << '\n';
            }
        }

        void exibirInventario() const {
            std::cout << "Inventory from " << name << ":\n";
            for (Item* item : inventory) {
                item->show();
            }
    }

        void walk(int x, int y, int map[10][10]){
            if(map[posx+x][posy+y] != 1) posx+=x, posy+=y;
        }
        
        void receiveDamage(int damage){
            health-=damage;
            if (health < 0){
                health = 0;
                exp-=10;
            } 
                
        }

        void attack(Character& enemy){
            if(enemy.health <= 0){
                std::cout << "Not possible to attack a enemy with 0 hp" << '\n';
                return;
            }

            std::cout << name << " attacked " << enemy.name << '\n';
            enemy.receiveDamage(strength);

            std::cout << "-----------------------" << '\n';
            std::cout << name << ": " << health << '\n';
            std::cout << enemy.name << ": " << enemy.health << '\n';
            std::cout << "-----------------------" << '\n';

            if(enemy.health == 0){
                receiveExp(enemy.level*10);
            }

        }

        
        void startFight(Character enemy){
            bool fight = true;
            short option = 0;


            while(fight){
                do{

                    std::cout << "Select an action\n" << "1 - Melee Atack\n" << "2 - Spell Atack\n";
                    std::cin >> option;

                    switch (option){

                    case 1:
                        attack(enemy);
                        break;
                    
                    case 2:
                        break;

                    default:
                        std::cout << "Invalid option\n";
                        break;
                    }
                    
                }while(option <= 0 || option > 2);
                
                if(enemy.health == 0 || health == 0) fight=false;
            }
        }

        //terminar os getters e setter
        short getExp() const {return exp;}
        short getMana() const {return mana;}
        short getLevel() const {return level;}
        void setHealth(int newHealth){health = newHealth;}
        void setLevel(int NewLevel){level = NewLevel;}


    private:
        short health;
        short mana;
        short strength;
        short exp;
        short level;
        std::vector<Item*> inventory;
        
        void receiveExp(int enemyExp){
            exp+=enemyExp;
            std::cout << name << " receive " << enemyExp << " exp" << '\n';

            switch(level){
                case 1:
                    if(exp >= 100){
                        newLevel();
                    }

                case 2:
                    if(exp >= 200){
                        newLevel();
                    }

                case 3:
                    if(exp >= 400){
                        newLevel();
                    }

                case 4:
                    if(exp >= 800){
                        newLevel();
                    }

                case 5:
                    if(exp >= 1600){
                        newLevel();
                    }
                }
        }

        void newLevel(){
            level++;
            health+=20;
            mana+=50;
            exp=0;
            std::cout << name << " leveled up!";
        }
};

#endif CHARACTER_H_INCLUDED