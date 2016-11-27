#include <stdio.h>
#include "estruturas.h"

extern int TRACE;
extern int YES;
extern int NO;

void printdt3();
extern void tolayer2(t_rtpkt); //tolayer2 est� definida na main

/* students to write the following two routines, and maybe some others */
t_dt dt3;
t_rtpkt * pkt3;

void rtinit3()
{
    //----- Inicializa��o das estruturas
    int i, j;
    pkt3 = (struct rtpkt *)malloc( sizeof(struct rtpkt) );
    pkt3->sourceid = 1; //id do n�

    //printf("NODE0: initialization event at t=%f\n", clocktime );

    //Custos dos vizinhos conhecidos do n� 3
    dt3.costs[3][0] = 7;
    dt3.costs[3][1] = 999;
    dt3.costs[3][2] = 2;
    dt3.costs[3][3] = 0;

    //Dist�ncias entre os n�s que n�o s�o o n� 3
    for (i=1; i<4; i++)
    {
        for (j=0; j<4; j++)
        {
            dt3.costs[i][j]=999; //Para facilitar, no exerc�cio foi pedido para considerar infinito como sendo 999
        }
    }

    // preenche a estrutura a ser enviada, pela fun��o tolayer2(), para os vizinhos diretamente conectados ao n� 0(1, 2 e 3, respectivamente),
    // contendo o custo dos caminhos de custo m�nimo para todos os outros n�s de rede
    for(i=0; i<4; i++){
        pkt3->mincost[i] = dt3.costs[i][i];
    }

    //----- Exibi��o

    printf("----- Tabela de distancias inicializada: -----\n");
    printdt3(&dt3); /* exibe o conte�do da tabela de dist�ncias ap�s a inicializa��o */

    pkt3->sourceid = 0; //id do n�

    //Envia para os n�s conectados ao n� 3(0 e 2)
    pkt3->destid = 0;
    tolayer2(*pkt3);
    pkt3->destid = 2;
    tolayer2(*pkt3);
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





