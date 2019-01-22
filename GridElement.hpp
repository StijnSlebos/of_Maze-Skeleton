//
//  GridElement.hpp
//  Mazegame1_0
//
//  Created by Stijn on 22/12/2018.
//

#ifndef GridElement_hpp
#define GridElement_hpp

#include <stdio.h>
#include "Konstant.h"
#include "Directions.hpp"

class gridElement{
public:
    gridElement();
    void setCoor(int [2]);
    void draw();
    void setNeighbour(Directions,gridElement*);
    void flipVisibility();
    void trigger();
    void setWalls(Directions);
    void removeWalls(Directions);
    
    void drawWalls();

    void getPressed();
    
    bool checkMouse(int,int);
    bool hasWall(Directions);
private:
    int timeToFlip = 2000; //ms
    int startTime;
    int gridLocation[2]; //0=x,1=y
    bool hasWalls [DIRECTIONS];
    gridElement* myNeighbours[DIRECTIONS];
    bool on;
    
};

#endif /* GridElement_hpp */
