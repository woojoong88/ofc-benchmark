#ifndef MYMESSAGES_H
#define MYMESSAGES_H

#include <pthread.h>

typedef enum { false, true } bool;

#define PORT_DIST 5001

#define SERVER_MESSAGES 2
#define CONNECT_REQUEST_MESSAGE  "1"
#define REPORT_MESSAGE "3"

#define CLIENT_MESSAGES 1
#define START_MESSAGE "2"

static bool sendReport = false;


//TODO: Considerar remover el resultado final como un buffer y
//      enviar todos mensajes impreso por pontalla en forma de archivo

static struct report {
  int sock;
  const char *hostname; // this shouldnt be const char * ?
  const char *buffer;
 } reports[] = {
   { 0 , "", "" },
   { '\0' }
 };

static struct status {
   int quantity;
   int connected;
   int reported;
 } clientsStatuses [] = {
   { -1, 0, 0 },
   { '\0' }
 };


void *connectReqMessage (void *context);

void *startMessage (void *context);

void *reportMessage (void *context);

#endif
