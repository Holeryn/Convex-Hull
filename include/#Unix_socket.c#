#include "Unix_socket.h"

int SUnixConnect(const char *name){
  int sfd;

  struct sockaddr_un addr;

  if((sfd = socket(AF_UNIX,SOCK_DGRAM,0)) == -1)
    return -1;

  memset(&addr,0,sizeof(struct sockaddr_un));
  addr.sun_family = AF_UNIX;
  strncpy(addr.sun_path,name,sizeof(struct sockaddr_un) - 1);

  if(bind(sfd,(struct sockaddr *)&addr,sizeof(struct sockaddr_un)) == -1)
    return -1;

  return sfd;
}
