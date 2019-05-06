//
// Created by cenicol on 5/4/19.
//

#ifndef ARRAY_TUTORIAL_CALLS_HPP
#define ARRAY_TUTORIAL_CALLS_HPP

#include "libdef.hpp"

#ifdef OLD

void CopyMap(Grid_type, Grid_type);
bool Enquire(void);
void Initialize(char *, Grid_type);
void Load(char const * filename, Grid_type);
int NeighborCount(int, int, Grid_type);
void WriteMap(Grid_type);

#else

void CopyMap(Map_type&, Map_type&);
bool Enquire();
void Initialize(char const * filename, Map_type&);
int NeighborCount(int, int, Map_type&);
void WriteMap(Map_type&);
#endif

#endif //ARRAY_TUTORIAL_CALLS_HPP
