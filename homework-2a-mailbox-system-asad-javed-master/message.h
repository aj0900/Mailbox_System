#ifndef MESSAGE_H
#define MESSAGE_H

#include <pthead.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct message_t {
  int sender;
  int reciever;
  char* message;
}

void message_create(message_t* data, int sender, int reciever, char* message); //create a message

void message_free(message_t* message); ////free the storage associated with the message

#endif
