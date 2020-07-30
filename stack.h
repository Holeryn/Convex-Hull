#ifndef STACK
#define STACK

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "point.h"
#include "vertex.h"
#include "include/gfx.h"

typedef struct tStackCell tsStack; 	// Used only in NEW()
typedef tsStack *tStack;
struct tStackCell {
  tPoint p;
  tStack next;
};

void FindLowest(void);
void PrintStack(tStack t);
tStack Push(tPoint p, tStack top);
tStack Pop(tStack s);

#endif
