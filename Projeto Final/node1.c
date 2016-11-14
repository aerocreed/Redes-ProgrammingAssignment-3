#include <stdio.h>
#include "estruturas.h"

extern int TRACE;
extern int YES;
extern int NO;

extern void tolayer2(t_rtpkt); //tolayer2 está definida na main

int connectcosts1[4] = { 1,  0,  1, 999 };

/* students to write the following two routines, and maybe some others */
t_dt dt1;
t_rtpkt packet;

void printdt1(t_dt *);

void rtinit1()
{

}


void rtupdate1(t_rtpkt *rcvdpkt)
{

}


void printdt1(t_dt *dtptr)
{
    printf("             via   \n");
    printf("   D1 |    0     2 \n");
    printf("  ----|-----------\n");
    printf("     0|  %3d   %3d\n",dtptr->costs[0][0], dtptr->costs[0][2]);
    printf("dest 2|  %3d   %3d\n",dtptr->costs[2][0], dtptr->costs[2][2]);
    printf("     3|  %3d   %3d\n",dtptr->costs[3][0], dtptr->costs[3][2]);

}



void linkhandler1(int linkid, int newcost)
{
    /* called when cost from 1 to linkid changes from current value to newcost*/
    /* You can leave this routine empty if you're an undergrad. If you want */
    /* to use this routine, you'll need to change the value of the LINKCHANGE */
    /* constant definition in prog3.c from 0 to 1 */
}

