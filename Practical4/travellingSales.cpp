#include <bits/stdc++.h>
using namespace std;
#define V 4
#define MAX 1000000
int tsp(int graph[][V], int s)  //function to find minimum distance travelled
{ 
    vector<int> vertex;  //vector to store vertices that is which cities we travelled
    for (int i = 0; i < V; i++)
        if (i != s)
            vertex.push_back(i);
    int min_cost = MAX;  // to store minimum distance
    while(next_permutation(vertex.begin(), vertex.end()))
     {
        int current_cost = 0; //to store cost of the current two cities distance 
        int j = s;
        for (int i = 0; i < vertex.size(); i++) {
            current_cost += graph[j][vertex[i]];  //finding the distance between the cities
            j = vertex[i];
        }
        current_cost += graph[j][s];
        min_cost = min(min_cost, current_cost); //finding the minimum distance 
        return min_cost;  //return the distance 
	}
}
int main()
{
    int graph[][V] = { { 0, 10, 15, 20 },{ 10, 0, 35, 25 },{ 15, 35, 0, 30 },{ 20, 25, 30, 0 } };                      
    int s = 0;
    cout << tsp(graph, s) << endl;
    return 0;
}
