//
//  MazeGrid.cpp
//  Mazegame1_0
//
//  Created by Stijn on 22/12/2018.
//

#include "MazeGrid.hpp"
#include "ofMain.h"
#include <cstdio>

MazeGrid::MazeGrid(){
    dummy.~gridElement();
    for(int i = 0; i<DIRECTIONS; i++){
        dummy.setNeighbour((Directions)i, &dummy);
    }
    
    int i =0;
    for(int x = 0; x<GRID_SIZE;x++){
        for(int y = 0; y<GRID_SIZE;y++){
            loc[x][y][0]=x*GRID_ELEMENT_SIZE;
            loc[x][y][1]=y*GRID_ELEMENT_SIZE;
            
            gridElements[x][y].~gridElement();
            gridElements[x][y].setCoor(loc[x][y]);
            i++;
        }
    }
    
    for (int y = 0; y < GRID_SIZE; y++) {
        for (int x = 0; x < GRID_SIZE; x++) {
            if (x > 0) {
                gridElements[x][y].setNeighbour(west, &gridElements[x - 1][y]);
            }else {
                gridElements[x][y].setNeighbour(west, &dummy);
                gridElements[x][y].setWalls(west);
            }
            
            if (x < GRID_SIZE - 1) {
                gridElements[x][y].setNeighbour(east, &gridElements[x + 1][y]);
            }else {gridElements[x][y].setNeighbour(east, &dummy);
                gridElements[x][y].setWalls(east);

            }
            
            if (y > 0) {
                gridElements[x][y].setNeighbour(north, &gridElements[x][y - 1]);
            }else {gridElements[x][y].setNeighbour(north, &dummy);
                gridElements[x][y].setWalls(north);

            }
            
            if (y < GRID_SIZE - 1) {
                gridElements[x][y].setNeighbour(south, &gridElements[x][y + 1]);
            }else {gridElements[x][y].setNeighbour(south, &dummy);
                gridElements[x][y].setWalls(south); 

            }
        }
    }
    
    for (int y = 0; y < GRID_SIZE; y++) {
        for (int x = 0; x < GRID_SIZE; x++) {
            gridElements[x][y].setWalls((Directions)(std::rand() % DIRECTIONS));
        }
    }
    
    myPlayer.~inMazePlayer();
}

void MazeGrid::draw(){
    bool color = false;
    for(int x = 0; x<GRID_SIZE;x++){
        for(int y = 0; y<GRID_SIZE;y++){
            gridElements[x][y].draw();
        }
    }
    myPlayer.draw();
}

void MazeGrid::clickOn(int m_x, int m_y){
    for(int x = 0; x<GRID_SIZE;x++){
        for(int y = 0; y<GRID_SIZE;y++){
            if(gridElements[x][y].checkMouse(m_x, m_y)){
                gridElements[x][y].getPressed();
            }
        }
    }
    Directions goToDirection = (Directions)(std::rand() % DIRECTIONS);
    myPlayer.doNextMove(&gridElements[myPlayer.inGridLocation[0]][myPlayer.inGridLocation[1]], goToDirection);
}

void MazeGrid::doMove( Directions direction){
    myPlayer.doNextMove(&gridElements[myPlayer.inGridLocation[0]][myPlayer.inGridLocation[1]], direction);
}
