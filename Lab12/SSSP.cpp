#include <iostream>
using namespace std;
#include <limits.h>
#include <vector>
  
#define V 6

  
int minimumtime(int time[], bool sptSet[])
{
  
    int min = INT_MAX, min_index;
  
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && time[v] <= min)
            min = time[v], min_index = v;
  
    return min_index;
}
  
void print(int time[], vector<float>& avgTime)
{   
    float avg_time = 0;
    cout << "Vertex \t time to reach from Source" << endl;
    for (int i = 0; i < V; i++){
        cout << i <<"\t"<< time[i] << endl;
        avg_time += time[i];
    }
    avgTime.push_back(avg_time/5);
}
  
void dijkstra(int graph[V][V], int source, vector<float>& avgTime)
{
    int time[V];
  
    bool sptSet[V]; 

    for (int i = 0; i < V; i++)
        time[i] = INT_MAX, sptSet[i] = false;

    time[source] = 0;
  
    for (int count = 0; count < V - 1; count++) {
        int u = minimumtime(time, sptSet);
  
        sptSet[u] = true;
  
        for (int v = 0; v < V; v++)
  
            if (!sptSet[v] && graph[u][v]
                && time[u] != INT_MAX
                && time[u] + graph[u][v] < time[v])
                time[v] = time[u] + graph[u][v];
    }
  
    print(time, avgTime);

}
  
int main()
{
    int graph[V][V] = { { 0, 10, 0, 0, 15, 5 },
                        { 10, 0, 10, 30, 0, 0 },
                        { 0, 10, 0, 12, 5, 0 },
                        { 0, 30, 12, 0, 0, 20 },
                        { 15, 0, 5, 0, 0, 0 },
                        { 5, 0, 0, 20, 0,0 } };

    vector<float> avgTime;
  

    dijkstra(graph, 0, avgTime);
    dijkstra(graph, 1, avgTime);
    dijkstra(graph, 2, avgTime);
    dijkstra(graph, 3, avgTime);
    dijkstra(graph, 4, avgTime);
    dijkstra(graph, 5, avgTime);

    cout<<"Vertex \t Average Time"<<endl;

    for (int i =0; i<6; i++){
        cout<<i<<'\t'<<avgTime[i]<<endl;
    }
  
    return 0;
}
  
