#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

int minDistance(int dist[], bool sptset[]){
    int min = INT_MAX, min_index;

    for(int v=0; v<5; v++){
        if(sptset[v] == false && dist[v] <= min){
            min = dist[v], min_index = v;
        } 
    }
    return min_index;
}

void printfunction(int dist[], int numNode){
    for(int i=0; i<numNode; i++){
        printf("The shorest path between v0 and v%d is %d\n",i,dist[i]);
    }
}

void ShortestPath(int graph[5][5], int length[5], int numNode){
    int dist[5];

    bool sptset[5];

    for(int i=0; i<5; i++){
        dist[i] = INT_MAX, sptset[i] = false;
    }
    dist[numNode] = 0;

    for(int count = 0; count<5-1; count++){
       int u = minDistance(dist, sptset);
       sptset[u] = true;
        for(int v=0; v<5; v++){
            if (!sptset[v] && graph[u][v]
                && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }
    printfunction(dist,numNode);
}   
int main(){
    int INF = 9999999;
    
    int graph[5][5] = {{INF, 10, 5, INF, INF},
                       {INF, INF, INF, 1, INF},
                       {INF, 3, INF, 9, 2,},
                       {INF, INF, INF, INF, 4},
                       {7, INF, INF, 6, INF}
                       };
    int length[5];
    ShortestPath(graph, length, 5);
    return 0;
}