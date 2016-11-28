#include <stdio.h>
#include "estruturas.h"

extern int TRACE;
extern int YES;
extern int NO;

void printdt3();
extern void tolayer2(t_rtpkt); //tolayer2 está definida na main

/* students to write the following two routines, and maybe some others */
t_dt dt3;
t_rtpkt * pkt3;

void rtinit3()
{
    //----- Inicialização das estruturas
    int i, j;
    pkt3 = (struct rtpkt *)malloc( sizeof(struct rtpkt) );
    pkt3->sourceid = 1; //id do nó

    //Distâncias entre os nós que não são o nó 3
    for (i=0; i<4; i++)
    {
        for (j=0; j<4; j++)
        {
            dt3.costs[i][j]=999; //Para facilitar, no exercício foi pedido para considerar infinito como sendo 999
        }
    }
    
    //Custos dos vizinhos conhecidos do nó 3
    dt3.costs[3][0] = 7;
    dt3.costs[3][1] = 999;
    dt3.costs[3][2] = 2;
    dt3.costs[3][3] = 0;    

    // preenche a estrutura a ser enviada, pela função tolayer2(), para os vizinhos diretamente conectados ao nó 0(1, 2 e 3, respectivamente),
    // contendo o custo dos caminhos de custo mínimo para todos os outros nós de rede
    for(i=0; i<4; i++){
        pkt3->mincost[i] = dt3.costs[i][i];
    }

    //----- Exibição

    printf("----- Tabela de distancias inicializada: -----\n");
    printdt3(&dt3); /* exibe o conteúdo da tabela de distâncias após a inicialização */

    pkt3->sourceid = 0; //id do nó

    //Envia para os nós conectados ao nó 3(0 e 2)
    pkt3->destid = 0;
    tolayer2(*pkt3);
    pkt3->destid = 2;
    tolayer2(*pkt3);
}


void rtupdate3(t_rtpkt *rcvdpkt)
{
    //j eh o pacote que enviou mensagem para o no X
    int j = rcvdpkt->sourceid;
    
    char distanciaAtualizada = 0;
    
    //atualiza as distancias conhecidas de todos os vizinhos de X
    for(int i = 0; i < 4; ++i) {
        
        //atualiza o que o no 3 sabe sobre a distancia (j --> i)
        if(rcvdpkt->mincost[i] < dt3.costs[j][i])
            dt3.costs[j][i] = rcvdpkt->mincost[i];
        
        //se a distancia (X --> i) ja conhecida
        //eh maior que a distancia (X --> j) + (distancia j --> i) ....
        //... encontramos um menor caminho =D
        if(pkt3->mincost[i] > dt3.costs[3][j] + rcvdpkt->mincost[i]) {
            pkt3->mincost[i] = dt3.costs[3][j] + rcvdpkt->mincost[i]; //NOVO MENOR CAMINHO ATRAVES DE X --> j --> i
            distanciaAtualizada = 1;
        }
    }
    
    //distancia atualizada ... reenvia a matriz de X para todos os nos (para que eles tbm atualizem)
    if(distanciaAtualizada == 1){
        tolayer2(*pkt3);
    }
    
    printdt3(&dt3);
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
