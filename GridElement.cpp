//
//  GridElement.cpp
//  Mazegame1_0
//
//  Created by Stijn on 22/12/2018.
//

#include "GridElement.hpp"
#include "Konstant.h"
#include "Directions.hpp"
#include "ofMain.h"

gridElement::gridElement(){
    for(int i = 0; i<DIRECTIONS;i++){
        myNeighbours[i] = nullptr;
        hasWalls[i]=false;
    }
    on = false;    
}

void gridElement::setNeighbour(Directions direction,gridElement* grid){
   myNeighbours[direction] = grid;
}


void gridElement::setCoor(int loc[2]){
    gridLocation[0] = loc[0];
    gridLocation[1] = loc[1];//gebrekig c++
}

void gridElement::draw(){
    ofSetLineWidth(4);
    if(on){
        ofSetColor(int((gridLocation[0]*230)/MAZE_SIZE),0, 255-int((gridLocation[1]*230)/MAZE_SIZE));
        
        
    }else{
        ofSetColor(0, int((gridLocation[0]*230)/MAZE_SIZE), 255-int((gridLocation[1]*230)/MAZE_SIZE));}
        ofDrawRectangle(gridLocation[0], gridLocation[1], GRID_ELEMENT_SIZE, GRID_ELEMENT_SIZE);
        ofSetColor(0,0,0);
        drawWalls();
}

void gridElement::drawWalls(){
    
    if(hasWalls[0]){
        ofDrawLine(gridLocation[0], gridLocation[1], gridLocation[0]+GRID_ELEMENT_SIZE, gridLocation[1]);}
    if(hasWalls[1]){
        ofDrawLine(gridLocation[0]+GRID_ELEMENT_SIZE, gridLocation[1], gridLocation[0]+GRID_ELEMENT_SIZE, gridLocation[1]+GRID_ELEMENT_SIZE);}
    if(hasWalls[2]){
        ofDrawLine(gridLocation[0], gridLocation[1]+GRID_ELEMENT_SIZE, gridLocation[0]+GRID_ELEMENT_SIZE, gridLocation[1]+GRID_ELEMENT_SIZE);}
    if(hasWalls[3]){
        ofDrawLine(gridLocation[0], gridLocation[1], gridLocation[0], gridLocation[1]+GRID_ELEMENT_SIZE);}
    
}

void gridElement::flipVisibility(){
    on=!on;
    
}

void gridElement::trigger(){
}

void gridElement::getPressed(){
    for(gridElement* neighbour: myNeighbours){
        neighbour->flipVisibility();
    }
    
    for(int i = 0; i<DIRECTIONS; i++){
        hasWalls[i]=!hasWalls[i];
        myNeighbours[i]->hasWalls[oppositeDirection((Directions)i)] =! myNeighbours[i]->hasWalls[oppositeDirection((Directions)i)];
    }
    
//    for(int i = 0; i<DIRECTIONS; i++){
//        setWalls((Directions)i);
//    }
}

bool gridElement::checkMouse(int x, int y){
    if(x>gridLocation[0] && x<gridLocation[0]+GRID_ELEMENT_SIZE && y>gridLocation[1] && y<gridLocation[1]+GRID_ELEMENT_SIZE){
        return true;
    }else {return false;}
}

void gridElement::setWalls(Directions direction){
    hasWalls[direction] = true;
    
    if(myNeighbours[direction]->hasWalls[oppositeDirection(direction)] == false){
        myNeighbours[direction]->setWalls(oppositeDirection(direction));
    }
}

void gridElement::removeWalls(Directions direction){
    hasWalls[direction] = false;
    
    if(myNeighbours[direction]->hasWalls[oppositeDirection(direction)] == true){
        myNeighbours[direction]->removeWalls(oppositeDirection(direction));
    }
    
}

bool gridElement::hasWall(Directions direction){
    if(hasWalls[direction]){
        return true;}
    else{
        return false;}
    
}



