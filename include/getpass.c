#include "getpass.h"

/*
  print prompt and read a no echoed input
  ATTENTION, for prevent memory leak you must
  do free(password) after call getpass2()
 */
char *getpass2(const char *prompt){
  struct termios tp,save;
  char *password;
  password = malloc(BUF_SIZE);

  printf("%s ", prompt);
  fflush(stdout);

  if(tcgetattr(STDIN_FILENO,&tp) == -1){
    ERROR_COMMON_POINTER("tchetattr()");
  }

  save = tp;
  tp.c_lflag &= ~ECHO;
  if(tcsetattr(STDIN_FILENO,TCSAFLUSH,&tp) == -1){
    ERROR_COMMON_POINTER("Setting the tp");
  }

  read(STDIN_FILENO,password,sizeof(password));

  if(tcsetattr(STDIN_FILENO,TCSAFLUSH,&save) == -1){
    ERROR_COMMON_POINTER("Saning tty");
  }

  return password;
}
