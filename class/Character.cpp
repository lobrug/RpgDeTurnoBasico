#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>  

class Character{
    public:
        std::string name;

        Character(std::string name)
            :
            name(name), health(100), mana(50), strength(20), exp(0), level(1) {}

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

        //terminar os getters e setter
        short getExp() const {return exp;}
        short getMana() const {return mana;}
        void setLevel(int NewLevel){level = NewLevel;}


    private:
        short health;
        short mana;
        short strength;
        short exp;
        short level;
        
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
            mana+=10;
            exp=0;
            std::cout << name << " leveled up!";
        }
};

#endif PERSON_H_INCLUDED