#include <stdio.h>
#include <stdlib.h>
#include "estruturas.h"

extern int TRACE;
extern int YES;
extern int NO;

/* students to write the following two routines, and maybe some others */
extern void tolayer2(t_rtpkt); //tolayer2 está definida na main

struct distance_table dt0;
struct rtpkt * pkt0;

void printdt0(struct distance_table *);

void rtinit0()
{
    //----- Inicialização das estruturas
    int i, j;
    pkt0 = (struct rtpkt *)malloc( sizeof(struct rtpkt) );
    pkt0->sourceid = 0; //id do nó
    
    //Distâncias entre os nós que não são o nó 0
    for (i=1; i<4; i++)
    {   
        for (j=0; j<4; j++)
        { 
            dt0.costs[i][j]=999; //Para facilitar, no exercício foi pedido para considerar infinito como sendo 999
        }
    } 
    
   //Custos dos vizinhos conhecidos do nó 0
    dt0.costs[0][0] = 0; 
    dt0.costs[0][1] = 1; 
    dt0.costs[0][2] = 3; 
    dt0.costs[0][3] = 7;    

    // preenche a estrutura a ser enviada, pela função tolayer2(), para os vizinhos diretamente conectados ao nó 0(1, 2 e 3, respectivamente),
    // contendo o custo dos caminhos de custo mínimo para todos os outros nós de rede    
    for(i=0; i<4; i++){
        pkt0->mincost[i] = dt0.costs[i][i];
    }    
    
    //----- Exibição

    printf("----- Tabela de distancias inicializada: -----\n");
    printdt0(&dt0); /* exibe o conteúdo da tabela de distâncias após a inicialização */

    pkt0->sourceid = 0; //id do nó

    //Envia para os nós conectados ao nó 0(1, 2 e 3)
    pkt0->destid = 1;
    tolayer2(*pkt0);
    pkt0->destid = 2;
    tolayer2(*pkt0);
    pkt0->destid = 3;
    tolayer2(*pkt0);    
}


void rtupdate0(struct rtpkt *rcvdpkt)
{

}


void printdt0(struct distance_table *dtptr)
{
    printf("                via     \n");
    printf("   D0 |    1     2    3 \n");
    printf("  ----|-----------------\n");
    printf("     1|  %3d   %3d   %3d\n",dtptr->costs[1][1], dtptr->costs[1][2],dtptr->costs[1][3]);
    printf("dest 2|  %3d   %3d   %3d\n",dtptr->costs[2][1], dtptr->costs[2][2],dtptr->costs[2][3]);
    printf("     3|  %3d   %3d   %3d\n",dtptr->costs[3][1], dtptr->costs[3][2],dtptr->costs[3][3]);
}

void linkhandler0(int linkid, int newcost)
{
    /* called when cost from 0 to linkid changes from current value to newcost*/
    /* You can leave this routine empty if you're an undergrad. If you want */
    /* to use this routine, you'll need to change the value of the LINKCHANGE */
    /* constant definition in prog3.c from 0 to 1 */
}
