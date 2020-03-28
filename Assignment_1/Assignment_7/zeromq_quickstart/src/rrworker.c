//  Hello World worker
//  Connects REP socket to tcp://localhost:5560
//  Expects "Hello" from client, replies with "World"

#include "zhelpers.h"
#include <unistd.h>

int main (void) 
{
    void *context = zmq_ctx_new ();

    //  Socket to talk to clients
    void *responder = zmq_socket (context, ZMQ_REP);
    zmq_connect (responder, "tcp://localhost:5560");

    while (1) {
        //  Wait for next request from client
        char *string = s_recv (responder);
        printf ("Received request: [%s]\n", string);
        int x = 0;
		x = atoi(string); // convert string which should be a number to int
		free (string);

		
		x = x*x; // square it
		printf("Number squared is %d\n", x);
		char buffer[10];
		snprintf(buffer, 10, "%d", x); // convert the squared int to string so it could be sent to the client
        //  Do some 'work'
        sleep (1);
		if (x >= 1111111111) { // if the square is above that value, sent Error instead
			s_send (responder, "Error");
		} else {
			//  Send reply back to client
			s_send (responder, buffer); // send the square back to the client
		}
    }
    //  We never get here, but clean up anyhow
    zmq_close (responder);
    zmq_ctx_destroy (context);
    return 0;
}
