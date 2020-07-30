#include "stack.h"

tStack Pop(tStack s) {
  tStack top;

  top = s->next;
  FREE(s);
  return top;
}

tStack Push(tPoint p, tStack top) {
  tStack s;

  // Get new cell and fill ti with point
  NEW(s,tsStack);
  s->p = p;
  s->next = top;
  return s;
}

void PrintStack(tStack t) {
  int firstx,firsty;
  int lastx,lasty;

  for(int i = 0; t ; i++) {
    if(i == 0){
      firstx = t->p->v[X];
      firsty = t->p->v[Y];
    }
    printf("vnum = %d\tx = %d\ty=%d\n",
           t->p->vnum,t->p->v[X],t->p->v[Y]);
    if(t->next)
      gfx_line(t->p->v[X],t->p->v[Y],t->next->p->v[X],t->next->p->v[Y]);
    lastx = t->p->v[X];
    lasty = t->p->v[Y];
    t = t->next;
  }
  gfx_line(firstx,firsty,lastx,lasty);
}


static void Swap(struct tPointStructure a, struct tPointStructure b)
{
  struct tPointStructure temp;
  temp = a;
  a = b;
  b = temp;
}

void FindLowest(void) {
  int i;
  int m = 0; // Index of lowest so far

  for(i = 1; i < n; i++)
    if((P[i].v[Y] < P[m].v[Y]) ||
       ((P[i].v[Y] == P[m].v[Y]) && (P[i].v[X] > P[m].v[X])))
      m = i;

  Swap(P[0],P[m]);
}
