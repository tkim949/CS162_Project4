/****************************************************************************************************
 * * Program name: CS162 Project4
 * * Author: Taekyoung Kim
 * * Date: 02/21/2019
 * * Description: This is Queue.cpp file for CS162 Project4
 * * This project demonstrates a fantasy combat Tournament game between two teams.
 * * Users can choose their players from 5 characters that have different ability and power.
 * * Also, this program use circular linked list and doubly linked list to proceed the game.
 ******************************************************************************************************/

#include "Queue.h"
#include "inputVal.h"
#include <iostream>

//constructor
Queue::Queue() = default;

//destructor
Queue::~Queue() =default;

/*************************************************************
 * * This isEmpty() function check if the queue is empty.
 *************************************************************/

bool Queue::isEmpty(){

    if(head == nullptr)
    {
        return true;
    }
    else{
        return false;
    }
}

/****************************************************************
 * * This addBack() function add new integer value in the queue.
 * * @param val
 ****************************************************************/

void Queue::addBack(Character *cha){

    struct QNode *nLink = new QNode();
    
    nLink->charac = cha;

        if (isEmpty()) {
           //std::cout<<"First one added "<<nLink->value<<std::endl;
           head = nLink;
           head->next = head;
            
           return;
        }

        if(head->next == head) //there was only one node
        {   //std::cout<<"second one added "<<nLink->value<<std::endl;
	        head->next = nLink;
			head->prev = nLink;
			nLink->prev = head;
	        nLink->next = head; 
            //return;
        }

        else // there was two or more node
            {
			struct QNode *temp;	
            temp = head;
            do{
                temp = temp->next;

            }while(temp->next != head);
            //std::cout<<"added when 2 or more: "<<nLink->value<<std::endl;
            temp->next = nLink;
            nLink->prev = temp;
            nLink->next = head;
            head->prev = nLink;

        }

}

/**************************************************************************
 * * This getFront() function returns the first valdue in the queue.
 * * Also, this function is declared with int, so it has return.
 *************************************************************************/

Character* Queue::getFront(){

     //QNode *ptr = head;

     return this->head->charac;

}

/*************************************************************************
 * * This removeFront() function remove the front node in the queue.
 *************************************************************************/

void Queue::removeFront(){

    struct QNode *temp;
    temp = head;

    if(isEmpty())
    {
        std::cout<<"Queue is empty."<<std::endl;
        return;
    }


    if (head->next == head) // only one node
        {
            //std::cout<<"Delete when only one: "<<head->value<<std::endl;
            head = nullptr;
            delete head;
            return;

        }
    else if(temp->next == temp->prev)
   // else if(temp->next->next == head) //there were two nodes
    {
        //std::cout<<"Delete when two nodes: "<<temp->value<<std::endl;
        head = head->next;
        head->next = head;
        head->prev = head;
        delete temp;
        return;

    }
    else if(temp->next->next->next == head) //there were three nodes.
    {
        temp = temp->next;
        temp = temp->next;

        QNode *current;
        current = head;
        //std::cout<<"Delete when three nodes: "<<current->value<<std::endl;
        head = head->next;
        temp->next=head->next;
        head->prev = temp;
		temp->next = head;

        delete current;

    }

    else //if(temp->next->prev != head)
        {
            //finding the last one.
            do{
                temp = temp->next;
            }while(temp->next != head);

            QNode *current;
            current = head;
            //std::cout<<"Delete when 4 or more): "<<current->value<<std::endl;
            head = head->next;
            temp->next = head->next;
            head->next->prev = temp;
            temp->next = head;

            delete current;

        }

}

/*****************************************************************************************
 * * This printQueue() function shows the all values in the queue from the first to last
 *****************************************************************************************/

void Queue::printQueue(){

    struct QNode *temp;

    if(isEmpty())
    {
        std::cout<<"Queue is empty."<<std::endl;
        return;
    }

    else
    {
        //std::cout<<"Your queue is: ";

        temp = head;

        do{

            std::cout <<temp->charac->getNickName() << "   ";
            temp = temp->next;

        }while(temp != head);

    }

}

void Queue::moveBack() {

    struct QNode *temp;
    temp = head;

    if(temp->next == head) {
        return;
    }
    else if(temp->next->next == head) //two nodes

    {
        head = head->next;
        head = temp->next;
        head->prev= temp;

    }

    else // more than two nodes
    {
        do{
            temp = temp->next;
        }while(temp->next != head);

        QNode *current;
        current = head;
        head = head->next;
        temp->next = current;
        current->next = head;
        head->prev= current;

    }
}

/*********************************************************************
 * * This del() function deallocate the Queue Node memory.
 ********************************************************************/

void Queue::del(){
	
	
	if(isEmpty())
	{
	    return;
	}
	else{
		struct QNode *temp;
		struct QNode *gabage;
		temp = head;
		
		do{
			gabage = temp;
			temp = temp->next;
			delete gabage;
		}while(temp != head);
		head = nullptr;
	}

}


