//
//  Directions.cpp
//  Mazegame1_0
//
//  Created by Stijn on 27/12/2018.
//

#include "Directions.hpp"

Directions oppositeDirection(Directions direction) {
    switch (direction) {
        case north:
            return south;
            
        case east:
            return west;
            
        case south:
            return north;
            
        case west:
            return east;
    }
    return north;
}
