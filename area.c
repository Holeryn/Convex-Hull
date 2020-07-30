#include "area.h"

int
Area2(tPointi a, tPointi b, tPointi c) {
  return (b[X] - a[X]) * (c[Y] - a[Y]) - (c[X] - a[X]) * (b[Y] - a[Y]);
}

int
AreaPoly2(void) {
  int sum = 0;
  tVertex p,a;

  p = vertices;
  a = p->next;

  do {
    sum += Area2(p->v,a->v,a->next->v);
    a = a->next;
  }while(a->next != vertices);

  return sum;
}
