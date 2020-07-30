#ifndef VERTEX
#define VERTEX

#include <stdlib.h>
#include <stdbool.h>

#include "point.h"

typedef struct tVertexStructure tsVertex;	// Used only in NEW()
typedef tsVertex *tVertex;

struct tVertexStructure {
  int vnum;		// index
  tPointi v;	// Coordinates
  bool ear;		// True iff an ear
  tVertex next,prev;
};

tVertex vertices; // Head of ciruclar list

#define NEW(p,type) \
  if((p = (type *) malloc(sizeof(type))) == NULL) { \
  printf("New: Out of memory\n");	\
  exit(EXIT_FAILURE);	\
  }

#define ADD(head,p) \
  if(head) { \
  	p->next = head; \
  	p->prev = head->prev; \
  	head->prev = p; \
  	p->prev->next = p; \
  } else { \
  	head = p; \
	head->next = head->prev = p; \
  }

#define FREE(p) if(p) { free((char *) p); } else { p = NULL;};

#endif
