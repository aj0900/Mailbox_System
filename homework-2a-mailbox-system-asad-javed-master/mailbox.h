#ifndef MAILBOX_H
#define MAILBOX_H

#include "message.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "mailbox.h"

void mailbox_init(mailbox_t* mailboxes, int number_of_addresses); //inside mailbox

void mailbox_send(mailbox_t* mailboxes, message_t* message); //send message

message_t* message_receive(mailbox_t* mailboxes, int receiver); //recieving message

message_t* message_receive_poll(mailbox_t* mailboxes, int receiver); //recieving message w/o wait

int message_available(mailbox_t* mailboxes, int receiver); //message available or not

typedef struct mailbox{
  int size;
  mailbox_entry_t **entries;
} mailbox_t;

typedef struct mailbox_entry{
  message_t** messages;
  int size, head, tail;
  pthread_mutex_t lock;
  pthread_cond_t is_not_full, is_not_empty;
} mailbox_entry_t;

#endif
