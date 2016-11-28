#include <stdio.h>
#include "estruturas.h"

extern int TRACE;
extern int YES;
extern int NO;

extern void tolayer2(t_rtpkt); //tolayer2 está definida na main

int connectcosts1[4] = { 1,  0,  1, 999 };

/* students to write the following two routines, and maybe some others */
t_dt dt1;
t_rtpkt * pkt1;

void printdt1(t_dt *);

void rtinit1()
{
    //----- Inicialização das estruturas
    int i, j;
    pkt1 = (struct rtpkt *)malloc( sizeof(struct rtpkt) );
    pkt1->sourceid = 1; //id do nó

    //Distâncias entre os nós que não são o nó 1
    for (i=0; i<4; i++)
    {
        for (j=0; j<4; j++)
        {
            dt1.costs[i][j]=999; //Para facilitar, no exercício foi pedido para considerar infinito como sendo 999
        }
    }

    //Custos dos vizinhos conhecidos do nó 1
    dt1.costs[1][0] = 1;
    dt1.costs[1][1] = 0;
    dt1.costs[1][2] = 1;
    dt1.costs[1][3] = 999;
    
    // preenche a estrutura a ser enviada, pela função tolayer2(), para os vizinhos diretamente conectados ao nó 0(1, 2 e 3, respectivamente),
    // contendo o custo dos caminhos de custo mínimo para todos os outros nós de rede
    for(i=0; i<4; i++){
        pkt1->mincost[i] = dt1.costs[i][i];
    }

    //----- Exibição

    printf("----- Tabela de distancias inicializada: -----\n");
    printdt1(&dt1); /* exibe o conteúdo da tabela de distâncias após a inicialização */

    pkt1->sourceid = 0; //id do nó

    //Envia para os nós conectados ao nó 1(1 e 2)
    pkt1->destid = 1;
    tolayer2(*pkt1);
    pkt1->destid = 2;
    tolayer2(*pkt1);
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

