/****************************************************************************************************
 * * Program name: CS162 Project4
 * * Author: Taekyoung Kim
 * * Date: 02/21/2019
 * * Description: This is Barbarian.cpp file for CS162 Project4
 * * This project demonstrates a fantasy combat Tournament game between two teams.
 * * Users can choose their players from 5 characters that have different ability and power.
 * * Also, this program use circular linked list and doubly linked list to proceed the game.
 ******************************************************************************************************/

#include "Barbarian.h"
#include <iostream>

//constructor
Barbarian::Barbarian()
         :Character("Barbarian", 12, 0)
{

}

//destructor
Barbarian::~Barbarian()= default;

/*********************************************************************************
 * * This Attack() function call Dice function with its data and get the result.
 * * Then, it returns its result.
 ********************************************************************************/

int Barbarian::Attack() {

    int roll = Character::Dice(2, 6);
    //std::cout << "Attacker: "<<getName()<<" Attacker's roll: "<<roll<<std::endl;

    return roll;

}

/**************************************************************************************
 * * This Defense() function takes integer number as its argument and that integer
 * * is the attacker's roll number. The, this function calls dice function and
 * * calculates damage and shows defender's roll number and armor and the damage.
 * * @param at
 **************************************************************************************/

void Barbarian::Defense(int at) {

    int numOfDef = Character::Dice(2, 6);
    int damage;
    damage = at -(numOfDef + armor);

    //std::cout<<"Defender: "<<name;
    //std::cout<<"  Defender's roll: "<<numOfDef<<std::endl;
   // std::cout<<"Defender's Armor: "<<armor<<"  Strength: "<<getStrength()<<std::endl;

    if(damage >= getStrength()) {

        //std::cout << "Total inflicted Damage: " << getStrength() << std::endl;
        setStrength(0);

    }
    else if (damage > 0 && damage < getStrength()) {

        //std::cout << "Total inflicted Damage: " << damage << std::endl;
        setStrength(strength - damage);
    }
    else if(damage <= 0)
    {
        //std::cout << "Total inflicted Damage: " << 0 << std::endl;
        damage = 0;

    }

}

int Barbarian::recovery() {

    int recover = Character::recovery();

    int newPower = getStrength() + int(12 * recover * 0.1);

    if(newPower < 12 )
    {
        return newPower;
    }
    else //newPower >=12
    {
        return 12;
    }

}