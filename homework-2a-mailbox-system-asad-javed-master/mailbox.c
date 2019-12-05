#include "message.h"
#include "mailbox.h"
#include <pthead.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define LENGTH 20

mailbox_init(mailbox_t* mailbox, int number_of_addresses)
{
mailbox -> entries = (mailbox_entry*)malloc(number_of_addresses*sizeof(mailbox_entry*));
for (int i = 0; i < number_of_addresses; i++){
  mailbox -> entries[i].messages = (message_t*)malloc(LENGTH*sizeof(message_t*));
  mailbox -> entries[i].size = 0;
  mailbox -> entries[i].tail = 0;
  mailbox -> entries[i].head = 0;
 }
}

void mailbox_send(mailbox_t* mailbox, message_t* message);
{
  message_t message = *message;
  int reciever = message.reciever;
  pthread_mutex_lock(&(mailbox -> entries[reciever].mailbox_lock));
  if (mailbox -> entries[reciever].size == LENGTH){
    pthread_cond_wait(&(mailbox -> entries[reciever].is_not_full), &(mailbox -> entries [reciever].mailbox_lock));
  }
  int tail = mailbox -> entries[reciever].tail;
  mailbox -> entries[reciever].messages[tail + 1] = message;
  mailbox -> entries[reciever].tail++;
  mailbox -> entries[reciever].size++;
  pthread_cond_signal(&(mailbox -> entries[reciever].is_not_empty);
  pthread_mutex_unlock(&(mailbox -> entries[reciever].mailbox_lock));
}

message_t* message_receive(mailbox_t* mailboxes, int receiver);
{
  message_t message = *message;
  int reciever = message.reciever;
  pthread_mutex_lock(&(mailbox -> entries[reciever].mailbox_lock));
  if (mailbox -> entries[reciever].size == 0){
    pthread_cond_wait(&(mailbox -> entries[reciever].is_not_empty), &(mailbox -> entries [reciever].mailbox_lock));
  }
  message_t message_present;
  message_present = mailbox -> entries[reciever].messages[head];
  mailbox -> entries[reciever].head++;
  mailbox -> entries[reciever].size--;
  pthread_cond_signal(&(mailbox -> entries[reciever].is_not_full);
  pthread_mutex_unlock(&(mailbox -> entries[reciever].mailbox_lock));
  return &message_present;
}

message_t* message_receive_poll(mailbox_t* mailboxes, int receiver);
{
  message_t message = *message;
  int reciever = message.reciever;
  pthread_mutex_lock(&(mailbox -> entries[reciever].mailbox_lock));
  if (mailbox -> entries[reciever].size == 0){
    printf("No Message"):
    pthread_mutex_unlock(&(mailbox -> entries[reciever].mailbox_lock));
    return NULL;
  }
  message_t message_present;
  message_present = mailbox -> entries[reciever].messages[head];
  mailbox -> entries[reciever].head++;
  mailbox -> entries[reciever].size--;
  pthread_cond_signal(&(mailbox -> entries[reciever].is_not_full);
  pthread_mutex_unlock(&(mailbox -> entries[reciever].mailbox_lock));
  return &message_present;
}

int message_available(mailbox_t* mailboxes, int receiver);
{
  message_t message = *message;
  int reciever = message.reciever;
  pthread_mutex_lock(&(mailbox -> entries[reciever].mailbox_lock));
  if (mailbox -> entries[reciever].size == 0){
    printf("No message");
    pthread_mutex_unlock(&(mailbox -> entries[reciever].mailbox_lock));
    return 0;
  }
  else{
    printf("Message Available!");
    pthread_mutex_unlock(&(mailbox -> entries[reciever].mailbox_lock));
    return 1;
  }
}
