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
    	
		if (scanf(" %d", &a) != 1) // read input from console, if input does not contain digits, report error and continue
		{
			printf("Not a number! request: %d [%s]\n", request_nbr, "Error");
			fgetc(stdin); // clear newline so scanf waits
			continue;
		}
    	
		char buffer[10];
		snprintf(buffer, 10, "%d", a); // store int to char buffer
		
        s_send (requester, buffer);
        char *string = s_recv (requester);

    	if (strcmp(string, "Error") == 0) // if server sent error, print to console
    	{
			printf("Received reply %d [%s]\n", request_nbr, string);
		}
		else {
			a = atoi(string); // otherwise, convert received string to int
			if (a >= 1111111111 || a < 0) // check if it is negative or larger than the one specified in requirements
			{
				printf("Received reply %d [%s]\n", request_nbr, "Error");
			}
			else {
				printf("Received reply %d [%s]\n", request_nbr, string); // print to console if the int satisfies the conditions
			}
		}
        free (string);
    }
    zmq_close (requester);
    zmq_ctx_destroy (context);
    return 0;
}
