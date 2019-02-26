/****************************************************************************************************
 * * Program name: CS162 Project4
 * * Author: Taekyoung Kim
 * * Date: 02/21/2019
 * * Description: This is BlueMen.h file for CS162 Project4
 * * This project demonstrates a fantasy combat Tournament game between two teams.
 * * Users can choose their players from 5 characters that have different ability and power.
 * * Also, this program use circular linked list and doubly linked list to proceed the game.
 ******************************************************************************************************/

#ifndef BLUEMEN_H
#define BLUEMEN_H
#include "Character.h"
#include <iostream>

class BlueMen:
        public Character
{

private:



public:

    BlueMen();
    ~BlueMen() override;
    int Attack() override;
    void Defense(int at) override;
    int recovery() override;

};


#endif //BLUEMEN_H
