#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

#include "area.h"
#include "point.h"
#include "stack.h"
#include "include/gfx.h"

#define MAX 50
#define GFX_WIDTH 500
#define GFX_HEIGHT 500

int Compare(const void *tpi, const void *tpj);
int ReadPoints(void);
void Squash(void);
void PrintPoints(int elements);
tStack Graham(void);

int ndelete;

int main(void){
  tStack top;

  gfx_open(GFX_WIDTH + 100,GFX_HEIGHT + 100,"Convex hull");
  gfx_color(255,255,0);

  puts("Reading the points...");
  n = ReadPoints();
  puts("Printing the points...");
  PrintPoints(n);
  puts("Finding the lowest...");
  FindLowest();
  puts("Qsorting ...");
  qsort(
        &P[1],				// Pointer to 1st elem
        n - 1,				// Number of elems
        sizeof(tsPoint),	//Size of each elem
        Compare
  );

  puts("Squashing ...");
  Squash();

  puts("Using Graham algorithm ...");
  top = Graham();
  gfx_color(46,246,0);
  puts("Printing the stack ...");
  PrintStack(top);
  gfx_flush();
  pause();
}

int ReadPoints(void){
  srand(time(NULL));
  int elements = rand() % MAX + 5;

  for(int i = 0; i <= elements; i++){
    P[i].vnum = i;
    P[i].v[X] = rand() % GFX_WIDTH;
    P[i].v[Y] = rand() % GFX_HEIGHT;
    // It shouldn't be a problem if i don't clear the
    // deletion flag, or at least i hope...
  }

  return elements;
}

void PrintPoints(int elements) {
  for(int i = 0; i <= elements; i++){
    gfx_point(P[i].v[X],P[i].v[Y]);
  }
}

void Squash(void){
  int i,j;
  i = 0; j = 0;
  while(i < n) {
    if(!P[i].delete) { // If not marked for deletion
      // Copy P[i] to P[J]
      memcpy(P[j].v,P[i].v,sizeof(P[j]));
      P[j].delete = P[j].delete;
      j++;
    }
    // Do nothing delete by skipping
    i++;
  }

  n = j;
}

tStack Graham(void){
  tStack top;
  int i;
  tPoint p1,p2;	// Two point on stack

  // Initialize stack;
  top = NULL;
  top = Push(&P[0],top);
  top = Push(&P[1],top);

  // Bottom two elements will never be removed
  i = 2;

  while(i < n) {
    p1 = top->next->p;
    p2 = top->p;
    if(left(p1->v,p2->v,P[i].v)) {
      top = Push(&P[i],top);
      i++;
    }else {
      top = Pop(top);
    }
  }

  return top;
}

int Compare(const void *tpi, const void *tpj){
  int a;	// Area
  int x,y;
  tPoint pi,pj;
  pi = (tPoint)tpi;
  pj = (tPoint)tpj;

  a = Area2(P[0].v,pi->v,pj->v);
  if(a > 0)
    return -1;
  else if(a < 0)
    return 1;
  else { // Collinear with P[0]
    x = abs(pi->v[X] - P[0].v[X]) - abs(pj->v[X] - P[0].v[X]);
    y = abs(pi->v[Y] - P[0].v[Y]) - abs(pj->v[Y] - P[0].v[Y]);

    if((x < 0) || (y < 0)){
      pi->delete = true;
      return -1;
    }else if((x > 0) || (y > 0)){
      pj->delete = true;
      return 1;
    }else { // Points are coincident
      if(pi->vnum > pj->vnum)
        pj->delete = true;
      else
        pi->delete = true;
      return 0;
    }
    ndelete++;
  }
}
