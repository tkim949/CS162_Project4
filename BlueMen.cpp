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

    return roll;

}

/**************************************************************************************
 * * This Defense() function takes integer number as its argument and that integer
 * * is the attacker's roll number. The, this function calls dice function and
 * * calculates damage and set the new strength.
 * * Also, the Blue men's number of dice change depending on his strength change.
 * * So, this function check the dice number when it calls dice function.
 * * @param at
 **************************************************************************************/

void BlueMen::Defense(int at) {

    int numOfDef;
    int damage;

    if (strength > 8){

        numOfDef = Character::Dice(3, 6);
    }

    else if ((strength <= 8) && (strength > 4)) {

        numOfDef = Character::Dice(2, 6);

    }
    else //(strength <=4){
    {
        numOfDef = Character::Dice(1, 6);

    }

    damage = at -(numOfDef + armor);

    if(damage >= getStrength()) {

        setStrength(0);

    }
    else if (damage > 0 && damage < getStrength()) {

        setStrength(strength - damage);
    }
    else if(damage <= 0)
    {
        damage =0;

    }

}

/*************************************************************************************
 * * This new recovery() function rolls a dice and add strength.
 * * However, the new strength cannot exceed the original strength.
 *************************************************************************************/

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