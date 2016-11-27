#include <stdio.h>
#include "estruturas.h"

extern int TRACE;
extern int YES;
extern int NO;

/* students to write the following two routines, and maybe some others */
extern void tolayer2(t_rtpkt); //tolayer2 está definida na main

void printdt2(t_dt *dtptr);

t_dt dt2;
t_rtpkt packet;

void rtinit2()
{

}


void rtupdate2(t_rtpkt *rcvdpkt)
{

}


void printdt2(struct distance_table *dtptr)
{
    printf("                via     \n");
    printf("   D2 |    0     1    3 \n");
    printf("  ----|-----------------\n");
    printf("     0|  %3d   %3d   %3d\n",dtptr->costs[0][0], dtptr->costs[0][1],dtptr->costs[0][3]);
    printf("dest 1|  %3d   %3d   %3d\n",dtptr->costs[1][0], dtptr->costs[1][1],dtptr->costs[1][3]);
    printf("     3|  %3d   %3d   %3d\n",dtptr->costs[3][0], dtptr->costs[3][1],dtptr->costs[3][3]);
}






