#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include "include/common.h"

/******************************************
 * Controlla se la STDIN_FILENO è		  *
 * in canonical mode oppure no			  *
 * e in caso fosse in non canonical mode  *
 * i valori di TIME e MIN				  *
 *******************************************/
int main(void){
  struct termios tp;

  if(tcgetattr(STDIN_FILENO,&tp) == -1){
    ERROR_COMMON_POINTER("tchetattr()");
  }

  // Check if the ICANON flag is set
  if(tp.c_lflag & ICANON){
    printf("Man you are in canonical mode");
  }else{
    printf("Man you are in non canonical mode");
    printf("TIME: %ld , MIN: %ld",(long)tp.c_cc[VMIN],(long)tp.c_cc[VTIME]);
  }
}
