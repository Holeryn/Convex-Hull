#include "predicates.h"

bool left(tPointi a, tPointi b, tPointi c) {
  return Area2(a,b,c) > 0;
}

bool leftOn(tPointi a, tPointi b, tPointi c) {
  return Area2(a,b,c) >= 0;
}

bool Collinear(tPointi a,tPointi b, tPointi c){
  return Area2(a,b,c) == 0;
}

bool IntersectProp(tPointi a, tPointi b, tPointi c, tPointi d){
  // Eliminate improper cases
  if( Collinear(a,b,c) || Collinear(a,b,d)
      || Collinear(c,d,a) || Collinear(c,d,b))
    return false;

  return Xor(left(a,b,c),left(a,b,d)) && Xor(left(c,d,a),left(c,d,b));
}

bool Xor(bool x, bool y) {
  return !x ^ !y; // the arguments are negated
  // for ensure that they are 0/1 values
}

bool Between(tPointi a, tPointi b, tPointi c){
  tPointi ba,ca;

  if(!Collinear(a,b,c))
    return false;

  // If ab not vertical, check betweennes on x; else on y
  if(a[X] != b[X])
    return((a[X] <= c[X]) && (c[X] <= b[X])) ||
      ((a[X] >= c[X]) && (c[X] >= b[X]));
  else
    return((a[Y] <= c[Y]) && (c[Y] <= b[Y])) ||
      ((a[Y] >= c[Y]) && (c[Y] >= b[Y]));
}

bool Intersect(tPointi a, tPointi b, tPointi c, tPointi d){
  if(IntersectProp(a,b,c,d))
    return true;
  else if(Between(a,b,c) || Between(a,b,d) ||
          Between(c,d,a) || Between(c,d,b))
    return true;
  else
    return false;
}


bool Diagonalie(tVertex a, tVertex b) {
  tVertex c,c1;

  // For each (c,c1) of P
  c = vertices;

  do {
    c1 = c->next;
    // Skip edges incident to a or b
    if((c != a) && (c1 != a) &&
       (c != b) && (c1 != b) &&
       Intersect(a->v,b->v,c->v,c1->v))
      return false;

    c = c->next;
  } while(c != vertices);

  return true;
}

bool InCone(tVertex a, tVertex b) {
  tVertex a0,a1; // a0,a,a1 are consecutive vertices

  a1 = a->next;
  a0 = a->prev;

  // If a is a convex vertex ...
  if(leftOn(a->v,a1->v,a0->v))
    return left(a->v,b->v,a0->v) &&
      left(b->v,a->v,a1->v);
  else // Is a reflex (concavo)
    return !(leftOn(a->v,b->v,a1->v) && leftOn(b->v,a->v,a0->v));
}

bool Diagonal(tVertex a, tVertex b) {
  return InCone(a,b) && InCone(b,a) && Diagonalie(a,b);
}
