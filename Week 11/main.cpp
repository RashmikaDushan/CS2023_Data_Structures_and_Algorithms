#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = INT_MAX;

struct Node {
    int vertex;
    int distance;

    Node(int v, int d) : vertex(v), distance(d) {}

    bool operator<(const Node& other) const {
        return distance > other.distance;  // Min-heap based on distance
    }
};

int minVertex(vector<int>& distances, vector<bool>& visited) {
    int minDist = INF;
    int vertex = -1;
    for (int i = 0; i < distances.size(); i++) {
        if (!visited[i] && distances[i] < minDist) {
            vertex = i;
            minDist = distances[i];
        }
    }
    return vertex;
}

void findMinDist(vector<vector<int>>& cityNetwork, int src) {
    int noCities = cityNetwork.size();

    vector<int> parents(noCities);
    vector<int> distances(noCities, INF);
    vector<bool> visited(noCities, false);

    parents[src] = -1;
    distances[src] = 0;

    priority_queue<Node> pq;
    pq.push(Node(src, 0));

    while (!pq.empty()) {
        int currentCity = pq.top().vertex;
        pq.pop();

        if (visited[currentCity])
            continue;

        visited[currentCity] = true;

        for (int neighbour = 0; neighbour < noCities; neighbour++) {
            int edgeDist = cityNetwork[currentCity][neighbour];
            if (edgeDist && !visited[neighbour] && edgeDist < distances[neighbour]) {
                distances[neighbour] = edgeDist;
                parents[neighbour] = currentCity;
                pq.push(Node(neighbour, edgeDist));
            }
        }
    }

    cout << "Edge\t" << "Weight\t" << endl;
    for (int city = 0; city < noCities; city++) {
        if (city == src)
            continue;
        cout << city << " - " << parents[city] << '\t' << cityNetwork[city][parents[city]] << endl;
    }
    cout << endl;
}

int main() {
    vector<vector<int>> cities {
            {0, 3, 0, 0, 0, 1},
            {3, 0, 2, 1, 10, 0},
            {0, 2, 0, 3, 0, 5},
            {0, 1, 3, 0, 5, 0},
            {0, 10, 0, 5, 0, 4},
            {1, 0, 5, 0, 4, 0}
    };

    findMinDist(cities, 1);

    return 0;
}
