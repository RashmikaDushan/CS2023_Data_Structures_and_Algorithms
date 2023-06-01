#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int minDistance(vector<int> distances,vector<bool> visited){
    int minDistance = INT_MAX;
    if(find(visited.begin(), visited.end(), false)== visited.end()){
        return -1;
    }
    int minDistanceIndex = 0;
    for(int i=0;i<distances.size();i++){
        if(distances[i]>0 && distances[i]<minDistance && !visited[i]) {
            minDistanceIndex=i;
            minDistance=distances[i];
        }
    }
    return minDistanceIndex;
}

vector<int> dijkstraSSSP(vector<vector<int>> adjcencyMatrix,int start){
    int n = adjcencyMatrix.size(); //Number of cities

    vector<int> distances(n,INT_MAX); //Distances to find the nearest city
    distances[start]=0;

    vector<bool> visited(n,false); //

    queue<int> forVisiting;
    forVisiting.push(start);

    while(!forVisiting.empty()){
        int currentCity = forVisiting.front();
        if(currentCity==-1) break;
        visited[currentCity]=true;
        forVisiting.pop();
        vector<int> distancesToNeighbours = adjcencyMatrix[currentCity];
        for(int i=0;i<n;i++){
            if(i!=currentCity && distances[i]>distancesToNeighbours[i]+distances[currentCity] && distancesToNeighbours[i]!=0){
                distances[i]=distancesToNeighbours[i]+distances[currentCity];
            }
        }
        int nearest = minDistance(distances,visited);
        forVisiting.push(nearest);
    }
    return distances;
}

int main() {
    vector<vector<int>> graph = {{0,10,0,0,15,5},
                                 {10,0,10,30,0,0},
                                 {0,10,0,12,5,0},
                                 {0,30,12,0,0,20},
                                 {15,0,5,0,0,0},
                                 {5,0,0,20,0,0}};

    for (int j = 0; j < 6; ++j) {
        vector<int> distances = dijkstraSSSP(graph,j);
        float total=0;
        for (int i = 0; i < distances.size(); ++i) {
            total+=distances[i];
        }
        float average = total/(distances.size()-1);
        cout<<"Average distance from city "<<j<<" other cities : "<<average<<endl;
    }

}
