#include <stdio.h>
#include "estruturas.h"

extern int TRACE;
extern int YES;
extern int NO;

/* students to write the following two routines, and maybe some others */
extern void tolayer2(t_rtpkt); //tolayer2 est� definida na main

void printdt2(t_dt *dtptr);

t_dt dt2;
t_rtpkt pkt2;

void rtinit2()
{
    //----- Inicializa��o das estruturas
    int i, j;
    pkt2 = (struct rtpkt *)malloc( sizeof(struct rtpkt) );
    pkt2->sourceid = 1; //id do n�

    //printf("NODE0: initialization event at t=%f\n", clocktime );

    //Custos dos vizinhos conhecidos do n� 1
    dt2.costs[2][0] = 3;
    dt2.costs[2][1] = 1;
    dt2.costs[2][2] = 0;
    dt2.costs[2][3] = 2;

    //Dist�ncias entre os n�s que n�o s�o o n� 1
    for (i=1; i<4; i++)
    {
        for (j=0; j<4; j++)
        {
            dt2.costs[i][j]=999; //Para facilitar, no exerc�cio foi pedido para considerar infinito como sendo 999
        }
    }

    // preenche a estrutura a ser enviada, pela fun��o tolayer2(), para os vizinhos diretamente conectados ao n� 0(1, 2 e 3, respectivamente),
    // contendo o custo dos caminhos de custo m�nimo para todos os outros n�s de rede
    for(i=0; i<4; i++){
        pkt2->mincost[i] = dt2.costs[i][i];
    }

    //----- Exibi��o

    printf("----- Tabela de distancias inicializada: -----\n");
    printdt2(&dt2); /* exibe o conte�do da tabela de dist�ncias ap�s a inicializa��o */

    pkt2->sourceid = 0; //id do n�

    //Envia para os n�s conectados ao n� 2(0, 1 e 2)
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






