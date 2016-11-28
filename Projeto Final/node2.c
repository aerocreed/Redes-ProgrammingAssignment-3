#include <stdio.h>
#include "estruturas.h"

extern int TRACE;
extern int YES;
extern int NO;

/* students to write the following two routines, and maybe some others */
extern void tolayer2(t_rtpkt); //tolayer2 está definida na main

void printdt2(t_dt *dtptr);

t_dt dt2;
t_rtpkt * pkt2;

void rtinit2()
{
    //----- Inicialização das estruturas
    int i, j;
    pkt2 = (struct rtpkt *)malloc( sizeof(struct rtpkt) );
    pkt2->sourceid = 1; //id do nó

    //Distâncias entre os nós que não são o nó 1
    for (i=0; i<4; i++)
    {
        for (j=0; j<4; j++)
        {
            dt2.costs[i][j]=999; //Para facilitar, no exercício foi pedido para considerar infinito como sendo 999
        }
    }
    
    //Custos dos vizinhos conhecidos do nó 1
    dt2.costs[2][0] = 3;
    dt2.costs[2][1] = 1;
    dt2.costs[2][2] = 0;
    dt2.costs[2][3] = 2;    

    // preenche a estrutura a ser enviada, pela função tolayer2(), para os vizinhos diretamente conectados ao nó 0(1, 2 e 3, respectivamente),
    // contendo o custo dos caminhos de custo mínimo para todos os outros nós de rede
    for(i=0; i<4; i++){
        pkt2->mincost[i] = dt2.costs[i][i];
    }

    //----- Exibição

    printf("----- Tabela de distancias inicializada: -----\n");
    printdt2(&dt2); /* exibe o conteúdo da tabela de distâncias após a inicialização */

    pkt2->sourceid = 0; //id do nó

    //Envia para os nós conectados ao nó 2(0, 1 e 2)
    pkt2->destid = 0;
    tolayer2(*pkt2);
    pkt2->destid = 1;
    tolayer2(*pkt2);
    pkt2->destid = 2;
    tolayer2(*pkt2);
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






