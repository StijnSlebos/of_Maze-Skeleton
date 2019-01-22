//
//  inMazePlayer.hpp
//  Mazegame1_0
//
//  Created by Stijn on 29/12/2018.
//

#ifndef inMazePlayer_hpp
#define inMazePlayer_hpp

#include <stdio.h>
#include "Konstant.h"
#include "Directions.hpp"
#include "GridElement.hpp"

class inMazePlayer{
public:
    inMazePlayer();
    
    void draw();
    void doNextMove(gridElement*, Directions);
    void doMove(Directions);
    
    bool canMove(Directions,gridElement*);
    
    int inGridLocation[2];
private:
    
    
    
    
    
    
    
};


#endif /* inMazePlayer_hpp */
