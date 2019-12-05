#include "message.h"
#include <pthead.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void message_create(message_t* data, int sender, int reciever, char* message);
{
  data -> sender = sender;
  data -> receiever = reciever;
  data -> message = message;
}

void message_free(message_t* message);
{
  free(message -> message);
}
