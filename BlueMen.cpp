/****************************************************************************************************
 * * Program name: CS162 Project4
 * * Author: Taekyoung Kim
 * * Date: 02/21/2019
 * * Description: This is BlueMen.cpp file for CS162 Project4
 * * This project demonstrates a fantasy combat Tournament game between two teams.
 * * Users can choose their players from 5 characters that have different ability and power.
 * * Also, this program use circular linked list and doubly linked list to proceed the game.
 ******************************************************************************************************/

#include "BlueMen.h"
#include <iostream>

//Character
BlueMen::BlueMen() //= default;
        :Character("Blue men", 12, 3)
{
}

//Destructor
BlueMen::~BlueMen() = default ;

/*********************************************************************************
 * * This Attack() function call Dice function with its data and get the result.
 * * Then, it returns its result.
 ********************************************************************************/

int BlueMen::Attack() {

    int roll = Character::Dice(2, 10);

    //std::cout << "Attacker: "<<getName()<<" Attacker's roll: "<<roll<<std::endl;

    return roll;

}

/**************************************************************************************
 * * This Defense() function takes integer number as its argument and that integer
 * * is the attacker's roll number. The, this function calls dice function and
 * * calculates damage and shows defender's roll number and armor and the damage.
 * * Also, the Blue men's number of dice change depending on his strength change.
 * * So, this function check the dice number when it calls dice function.
 * * @param at
 **************************************************************************************/

void BlueMen::Defense(int at) {

    int numOfDef;
    int damage;

    if (strength > 8){

        //std::cout<< "Defender Blue men has 3 dices."<<std::endl;
        numOfDef = Character::Dice(3, 6);
    }

    else if ((strength <= 8) && (strength > 4)) {

        //std::cout << "Defender Blue men has 2 dices now." << std::endl;
        numOfDef = Character::Dice(2, 6);

    }
    else //(strength <=4){
    {
        //std::cout<< "Defender Blue men 1 dice now."<<std::endl;
        numOfDef = Character::Dice(1, 6);

    }

    damage = at -(numOfDef + armor);

    //std::cout<<"Defender: "<<name;
    //std::cout<<"  Defender's roll: "<<numOfDef<<std::endl;
    //std::cout<<"Defender's Armor: "<<armor<<"  Strength: "<<getStrength()<<std::endl;

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
        damage =0;

    }

}

int BlueMen::recovery() {

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