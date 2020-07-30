#ifndef PREDICATES
#define PREDICATES

#include "area.h"
#include "vertex.h"
#include "point.h"

bool left(tPointi a, tPointi b, tPointi c);
bool leftOn(tPointi a, tPointi b, tPointi c);
bool Collinear(tPointi a,tPointi b, tPointi c);
bool IntersectProp(tPointi a, tPointi b, tPointi c, tPointi d);
bool Intersect(tPointi a, tPointi b, tPointi c, tPointi d);
bool Xor(bool x, bool y);
bool Between(tPointi a, tPointi b, tPointi c);
bool Diagonalie(tVertex a, tVertex b);
bool Diagonal(tVertex a, tVertex b);

#endif
