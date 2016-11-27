#include <stdio.h>
#include "estruturas.h"

extern int TRACE;
extern int YES;
extern int NO;

void printdt3();
extern void tolayer2(t_rtpkt); //tolayer2 está definida na main

/* students to write the following two routines, and maybe some others */
t_dt dt3;
t_rtpkt packet;

void rtinit3()
{

}


void rtupdate3(t_rtpkt *rcvdpkt)
{

}


void printdt3(t_dt *dtptr)
{
    printf("             via     \n");
    printf("   D3 |    0     2 \n");
    printf("  ----|-----------\n");
    printf("     0|  %3d   %3d\n", dtptr->costs[0][0], dtptr->costs[0][2]);
    printf("dest 1|  %3d   %3d\n", dtptr->costs[1][0], dtptr->costs[1][2]);
    printf("     2|  %3d   %3d\n", dtptr->costs[2][0], dtptr->costs[2][2]);
}





