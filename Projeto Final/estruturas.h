#ifndef NODE_H
#define NODE_H

#ifdef  __cplusplus
extern "C" {
#endif

#define INFINITO 999 //O exercício pede para considerar 999 como sendo infinito

typedef struct rtpkt {
    int sourceid;       /* id of sending router sending this pkt */
    int destid;         /* id of router to which pkt being sent
                         (must be an immediate neighbor) */
    int mincost[4];    /* min cost to node 0 ... 3 */
}t_rtpkt;

typedef struct distance_table
{
    int costs[4][4];
}t_dt;

#ifdef  __cplusplus
}
#endif

#endif  /* NODE_H */
