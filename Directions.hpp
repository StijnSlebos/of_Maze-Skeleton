//
//  Directions.hpp
//  Mazegame1_0
//
//  Created by Stijn on 27/12/2018.
//

#ifndef Directions_hpp
#define Directions_hpp

#include <stdio.h>

#define DIRECTIONS 4

enum Directions{
    north = 0,
    east = 1,
    south = 2,
    west = 3
};

Directions oppositeDirection(Directions);

#endif /* Directions_hpp */
