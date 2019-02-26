/****************************************************************************************************
 * * Program name: CS162 Project4
 * * Author: Taekyoung Kim
 * * Date: 02/21/2019
 * * Description: This is Game.cpp file for CS162 Project4
 * * This project demonstrates a fantasy combat Tournament game between two teams.
 * * Users can choose their players from 5 characters that have different ability and power.
 * * Also, this program use circular linked list and doubly linked list to proceed the game.
 ******************************************************************************************************/
#include <iostream>
#include <random>
#include <climits>
#include "Game.h"
#include "inputVal.h"
#include "Character.h"
#include "HarryP.h"
#include "Barbarian.h"
#include "BlueMen.h"
#include "Medusa.h"
#include "Vampire.h"
#include "Queue.h"
#include "stack.h"

Game::Game() = default;
Game::~Game() = default;


/***********************************************************************************************************
 * * This play() function hosts the combat tournament game between two teams so it shows menu that has all
 * * characters' speciality and prompts users to choose players for two team.
 * * After every rounds end, it shows who wins. And then, finally when one team wins, it asks users to see
 * * the fallen warriors' list. Also, it asks users to play again.
 ***********************************************************************************************************/

void Game::play() {

    double numOfW;
    int numOfPlayer;
    Queue TeamA;
    Queue TeamB;

    stack losers;
    int numOfPick = 0;
    double fighter1;
    int numForP1;

    double playChoose;
    int playGo;

    std::cout << "Welcome to the Fantasy Combat Tournament!" << std::endl;
    std::cout << "1. Play " << std::endl;
    std::cout << "2. Exit " << std::endl;
    std::cin >> playChoose;
    playGo = choiceBTwo(playChoose);


    if (playGo == 1) {


            std::cout << "\nWelcome to the Fantasy Combat Tournament!" << std::endl;
            std::cout << "Now, you will create two teams, and each team has its own warriors." << std::endl;
            std::cout << "Warriors who get a higher number in dices win the game." << std::endl;
            std::cout << "Then, the team that has last winner wins" << std::endl;
            std::cout << "Warriors are 5 types and they have different ability and skills."<<std::endl;
            std::cout << "Some of characters has armor that can be added to the sum" << std::endl;
            std::cout << "Also, you can make same characters fight. Let me introduce them." << std::endl;
            std::cout << "\nNumber 1: Vampire. Her strength is 18, highest one and her armor is 1." << std::endl;
            std::cout << "            Although her attack and defence ability are lower than others, " << std::endl;
            std::cout << "            she has special skill, Charm." << std::endl;
            std::cout << "\nNumber 2: Barbarian. His strength is 12. His ability for attack " << std::endl;
            std::cout << "            and defense is average, 0 armor." << std::endl;
            std::cout << "\nNumber 3: Blue Men. his attach and defense ability are the highest, " << std::endl;
            std::cout << "            and he has 3 armor. But, he lose a weakness. His defense" << std::endl;
            std::cout << "            will decrease as same as he lose the strength by 1/3." << std::endl;
            std::cout << "\nNumber 4: Medusa, her attack and defense ability is a little lower than others,";
            std::cout << "            \nbut she has Glare. If she roll number 12 on her dice, she will win the game.";
            std::cout << "            \nShe also has 3 armor." << std::endl;
            std::cout << "\nNumber 5: Happy porter, he has average attack and defense abilities and 0 armor";
            std::cout << "            \nHowever, he has special skill, Hogwarts that allows him a second life ";
            std::cout << "            \nwith 20 strengths. But, this is only one time chance." << std::endl;

        do {
            std::cout << "\nNow please choose warriors. Players for each team should be between 1 and 5." << std::endl;
            std::cout << "You should choose warrior types and then give them a nick name." << std::endl;

            for (int i = 0; i < 2; i++) {

                if (i == 0) {
                    std::cout << "\nHow many warriors do you pick for the Team A?" << std::endl;
                    std::cout << "Input your number for Team A: ";
                }

                else //i == 1
                {
                    std::cout << "\nHow many warriors do you pick for the Team B?" << std::endl;
                    std::cout << "Input your number for Team B: ";
                }

                //std::cin.clear();
                //std::cin.ignore(INT_MAX, '\n');
                std::cin >> numOfW;
                numOfPlayer = inputVal(numOfW);

                for (int j = 0; j < numOfPlayer; j++) {

                    //std::cin.clear();
                    //std::cin.ignore(INT_MAX, '\n');
                    std::cout << "Pick number: " << j + 1 << " player: ";
                    std::cin >> fighter1;
                    numForP1 = inputVal(fighter1);

                    std::string str;

                    //Set teams depending on user's choice.
                    switch (numForP1) {

                        case 1:
                            player1 = new Vampire();
                            std::cout << "Your choice for player "<<j+1<< ": 'Vampire' " << std::endl;
                            break;
                        case 2:
                            player1 = new Barbarian();
                            std::cout << "Your choice for player "<<j+1<< ": 'Barbarian' " << std::endl;
                            break;
                        case 3:
                            player1 = new BlueMen();
                            std::cout << "Your choice for player "<<j+1<< ":'Blue men' " << std::endl;
                            break;
                        case 4:
                            player1 = new Medusa();
                            std::cout << "Your choice for player "<<j+1<< ": 'Medusa' " << std::endl;
                            break;
                        case 5:
                            player1 = new HarryP();
                            std::cout << "Your choice for player "<<j+1<<": 'Harry Potter' " << std::endl;
                            break;
                        default:
                            break;
                    }
                    numOfPick++;
                    std::cin.clear();
                    std::cin.ignore(INT_MAX, '\n');
                    std::cout << "Now give him/her a nick name: ";
                    std::getline(std::cin, str);

                    if(!str.empty()) {
                        player1->setNickName(str);
                    }
                    else{

                        do {
                            std::cout << "You didn't input the name. Please give them a name." << std::endl;
                            std::getline(std::cin, str);
                        }while(str.empty());
                        player1->setNickName(str);
                    }


                    if (i == 0) {
                        TeamA.addBack(player1);
                    }

                    else //i == 1
                    {
                        TeamB.addBack(player1);
                    }
                }
				
                std::cout<<std::endl;
				
            }

            //Shows each team's player lists.
            std::cout<<"The Team A List: ";
            TeamA.printQueue();
            std::cout<<std::endl;
            std::cout<<"The Team B List: ";
            TeamB.printQueue();
            std::cout<<std::endl;

            int round = 1;
            int impact;
            int ptsTeamA = 0;
            int ptsTeamB = 0;
            double seeListO;
            int seeList;
            int recoverStr;


            do {
                std::cout << "--------------" << std::endl;
                std::cout << "  Round: " << round << std::endl;
                std::cout << "--------------" << std::endl;
                std::cout << "Match: " << TeamA.getFront()->getNickName() << " of Team A Vs. "
                          << TeamB.getFront()->getNickName()
                          << " of Team B" << std::endl;


                do {

                    for (int i = 0; i < 2; i++) {
                        // When TeamA attacks
                        if (i == 0) {

                            impact = TeamA.getFront()->Attack();
                            TeamB.getFront()->Defense(impact);

                            if (TeamB.getFront()->getStrength() <= 0) {

                                break;

                            }
                        }
                        // When TeamB attacks.
                        else // i=1
                        {
                            impact = TeamB.getFront()->Attack();
                            TeamA.getFront()->Defense(impact);

                            if (TeamA.getFront()->getStrength() <= 0) {

                                break;

                            }

                        }
                    }

                } while (TeamA.getFront()->getStrength() > 0 && TeamB.getFront()->getStrength() > 0);

                std::cout<<std::endl;

                //When TeamA's player wins.
                if (TeamB.getFront()->getStrength() <= 0) {

                    std::cout<<"TeamA: "<<TeamA.getFront()->getNickName()<<" wins!"<<std::endl;
                    ptsTeamA ++;

                    losers.addFirst(TeamB.getFront());
                    TeamB.removeFront();

                    std::cout<<"Strength before recover: "<<TeamA.getFront()->getStrength()<<", ";
                    recoverStr = TeamA.getFront()->recovery();
                    TeamA.getFront()->setStrength(recoverStr);
                    std::cout<<"Strength after recover: "<<TeamA.getFront()->getStrength()<<std::endl;
                    TeamA.addBack(TeamA.getFront());
                    TeamA.removeFront();

                }
               // When TeamB's player wins.
                else if (TeamA.getFront()->getStrength() <= 0) {

                    std::cout<<"TeamB: "<<TeamB.getFront()->getNickName()<<" wins!"<<std::endl;
                    ptsTeamB ++;

                    losers.addFirst(TeamA.getFront());
                    TeamA.removeFront();

                    std::cout<<"Strength before recover: "<<TeamB.getFront()->getStrength()<<", ";
                    recoverStr = TeamB.getFront()->recovery();

                    TeamB.getFront()->setStrength(recoverStr);
                    std::cout<<"Strength after recover: "<<TeamB.getFront()->getStrength()<<std::endl;
                    TeamB.addBack(TeamB.getFront());
                    TeamB.removeFront();
                }

                round++;
                std::cout << std::endl;

            } while(!TeamA.isEmpty() && !TeamB.isEmpty());

            //Check each teams' points and which team wins.
            std::cout<<"Team A points: "<<ptsTeamA<<" vs Team B points: "<<ptsTeamB<<std::endl;

            if(TeamA.isEmpty()) {

                std::cout<<"The winner is Team B"<<std::endl;
            }

            else if(TeamB.isEmpty()) {

                std::cout<<"The winner is Team A"<<std::endl;

            }

            //Asks users if they want to see the fallen warriors' list.
            //std::cin.clear();
            //std::cin.ignore(INT_MAX, '\n');
            std::cout<<"Do you want to see the warriors' list who perish in the combats."<<std::endl;
            std::cout<<"If you want to see it, please input 1. If no, input 2: ";
            std::cin>>seeListO;
            seeList = choiceBTwo(seeListO);

            if(seeList == 1){

                losers.displayList();
            }
            else {
                std::cout<<"So you don't want to see the list. Okay."<<std::endl;
            }

            //Ask users if they want to play again.
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::cout << "\nDo you want to play again? " << std::endl;
            std::cout << "1. Play again" << std::endl;
            std::cout << "2. Exit " << std::endl;
            std::cin >> playChoose;
            playGo = choiceBTwo(playChoose);
            std::cout << "----------------------------------------------------" << std::endl;

            TeamA.del();
            TeamB.del();
            losers.del();
			

         } while (playGo == 1);

        std::cout<<"You want to exit. Good bye!"<<std::endl;

    }

    else{

        std::cout<<"You don't want to play. See you in the Next time."<<std::endl;

    }


}
