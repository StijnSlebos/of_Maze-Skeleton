//
//  MazeGrid.hpp
//  Mazegame1_0
//
//  Created by Stijn on 22/12/2018.
//

#ifndef MazeGrid_hpp
#define MazeGrid_hpp

#include <stdio.h>
#include "Konstant.h"
#include "Directions.hpp"
#include "GridElement.hpp"
#include "inMazePlayer.hpp"

class MazeGrid{
public:
    MazeGrid();
    void draw();
    void clickOn(int, int);
    void doMove(Directions);
    
    
    
private:
    int loc[GRID_SIZE][GRID_SIZE][2];
    gridElement gridElements[GRID_SIZE][GRID_SIZE];
    gridElement myGrid[GRID_SIZE*GRID_SIZE];
    gridElement dummy;
    inMazePlayer myPlayer;
};

#endif /* MazeGrid_hpp */
