#ifndef POINT
#define POINT

#include <stdbool.h>

#define X 0
#define Y 1
//typedef enum {FALSE,TRUE} bool;

#define DIM 2	// Dimension of points

typedef int tPointi[DIM];	// Type integer point

typedef struct tPointStructure tsPoint;
typedef tsPoint *tPoint;
struct tPointStructure {
  int vnum;
  tPointi v;
  bool delete;
};

#define PMAX 1000	// Max # of points
typedef tsPoint tPointArray[PMAX];
static tPointArray P;
static int n = 0; 			// Actual # of points

#endif
