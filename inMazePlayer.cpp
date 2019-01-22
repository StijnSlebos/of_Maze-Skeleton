//
//  inMazePlayer.cpp
//  Mazegame1_0
//
//  Created by Stijn on 29/12/2018.
//

#include "inMazePlayer.hpp"
#include "ofMain.h"

inMazePlayer::inMazePlayer(){
    inGridLocation[0] = 5;//std::rand() % GRID_SIZE;
    inGridLocation[1] = 5;//std::rand() % GRID_SIZE;
}

void inMazePlayer::draw(){
    ofSetColor(200, 20, 20);
    ofDrawEllipse(inGridLocation[0]*GRID_ELEMENT_SIZE+GRID_ELEMENT_SIZE/2, inGridLocation[1]*GRID_ELEMENT_SIZE+GRID_ELEMENT_SIZE/2, 10, 10);
}


void inMazePlayer::doNextMove(gridElement* myLocation , Directions goToDirection){
    //Directions goToDirection = (Directions)(std::rand() % DIRECTIONS);
    //if in direction there is no wall, do move, otherwise, doNextMove.
    if(canMove(goToDirection, myLocation)){
        doMove(goToDirection);
    }//else{doNextMove(myLocation);}
    
}

void inMazePlayer::doMove(Directions direction){
    if(direction == north){
        inGridLocation[1] -=1;
    }else if(direction == east){
        inGridLocation[0] +=1;
    }else if(direction == south){
        inGridLocation[1] +=1;
    }else if(direction == west){
        inGridLocation[0] -=1;
    }
}

bool inMazePlayer::canMove(Directions direction, gridElement* myLocation){
        if(!myLocation->hasWall(direction)){
            return true;
        }else{
            return false;
        }
    }
