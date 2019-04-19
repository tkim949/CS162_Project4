/****************************************************************************************************
 * * Program name: CS162 Project4
 * * Author: Taekyoung Kim
 * * Date: 02/21/2019
 * * Description: This is inputVal.cpp file for CS162 Project4
 * * This project demonstrates a fantasy combat Tournament game between two teams.
 * * Users can choose their players from 5 characters that have different ability and power.
 * * Also, this program use circular linked list and doubly linked list to proceed the game.
 ******************************************************************************************************/


#include "inputVal.h"
#include "Game.h"
#include <iostream>
#include <climits>
#include <cctype>
#include <algorithm>


/*********************************************************************
 * * This function get double parameter and return an integer value
 * * after checking if it is digit and positive number and double.
 * * and it checks that number is between 1 and 5.
 **********************************************************************/

int inputVal(double in) {

    // Check type validation first using std::cin.fail()
    if( std::cin.good() && in > 0 && in < 6 && (in - (int)in == 0)) {
        return (int)in;
    }

    else{

        do {

            std::cout << "Wrong input! You need to input proper value!" << std::endl;

            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');

            std::cout << "Please try again. Input here: " << std::endl;
            std::cin >> in;
            //decimalCheck(input);

        } while(!(std::cin.good() && in > 0 && in < 6 && (in - (int)in == 0) ));

    }

    return (int)in;
}



/****************************************************************************************
 * * This function get double parameter and return an integer value
 * * after checking if it isn't double and only valid integer(both negative and positive)
 *****************************************************************************************/
int inputNum(double in) {

    // Check type validation first using std::cin.fail()
    if( std::cin.good() && (in - (int)in == 0)) {
        return (int)in;
    }

    else{

        do {

            std::cout << "Wrong input! You need to input proper value!" << std::endl;

            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');

            std::cout << "Please try again. Input here: ";
            std::cin >> in;


        } while(!(std::cin.good() && (in - (int)in == 0) ));

    }

    return (int)in;
}

/********************************************************************************
 * * This function get an integer parameter and check if it 1 or 2.
 ******************************************************************************/

int choiceBTwo(double in){

    if( std::cin.good() && (in == 1 || in == 2) && (in - (int)in == 0)) {
        return (int)in;
    }

    else{

        do {

            std::cout << "Wrong input! You need to input proper value!" << std::endl;

            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');

            std::cout << "Please try again. Input here: " << std::endl;
            std::cin >> in;
            //decimalCheck(input);

        } while(!(std::cin.good() && (in == 1 || in == 2) && (in - (int)in == 0) ));

    }

    return (int)in;
}

