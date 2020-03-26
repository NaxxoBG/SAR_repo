//  Hello World client
//  Connects REQ socket to tcp://localhost:5559
//  Sends "Hello" to server, expects "World" back

#include <ctype.h>

#include "zhelpers.h"

int main (void)
{
    void *context = zmq_ctx_new ();

    //  Socket to talk to server
    void *requester = zmq_socket (context, ZMQ_REQ);
    zmq_connect (requester, "tcp://localhost:5559");
	
    int request_nbr;

	int a = 0;
	
    for (request_nbr = 0; request_nbr != 10; request_nbr++) {
		a = 0;
    	
		if (scanf(" %d", &a) != 1)
		{
			printf("Not a number! request: %d [%s]\n", request_nbr, "Error");
			fgetc(stdin);
			continue;
		}
    	
		char buffer[10];
		snprintf(buffer, 10, "%d", a);
		
        s_send (requester, buffer);
        char *string = s_recv (requester);

    	if (strcmp(string, "Error") == 0)
    	{
			printf("Received reply %d [%s]\n", request_nbr, string);
		}
		else {
			a = atoi(string);
			if (a >= 1111111111 || a < 0)
			{
				printf("Received reply %d [%s]\n", request_nbr, "Error");
			}
			else {
				printf("Received reply %d [%s]\n", request_nbr, string);
			}
		}
        free (string);
    }
    zmq_close (requester);
    zmq_ctx_destroy (context);
    return 0;
}
