//Program Number:13
//Name:BTV Sumanth
//Register Number: IMT2020072
//Date: 25/02/22
//Description: This will dedtect if data is available in 10sec or not.


#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

       int
       main(void)
       {
           fd_set rfds;
           struct timeval tv;
           int retval;

           /* Watch stdin (fd 0) to see when it has input. */

           FD_ZERO(&rfds);
           FD_SET(0, &rfds);

           /* Wait up to ten seconds. */

           tv.tv_sec = 10;
           tv.tv_usec = 0;

           retval = select(1, &rfds, NULL, NULL, &tv);
           /* Don't rely on the value of tv now! */

           if (retval == -1)
               perror("select()");
           else if (retval)
               printf("Data is available in 10 sec.\n");
               /* FD_ISSET(0, &rfds) will be true. */
           else
               printf("No data within ten seconds.\n");

           exit(EXIT_SUCCESS);
       }