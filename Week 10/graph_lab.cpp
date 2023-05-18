#include <iostream>
#include<list>
using namespace std;

struct Node{
    // A node will 2 entities
    //1. data type int called label
    //2. an int type list called neighbours
    int label;
    list<int> neighbours;
};

struct Graph{
    //graph will have an array of type "node" with length specified by n
    int n=8;
    Node * nodes = new Node[n];

    void intializenodes(){
        //iterate through the nodes and assign labels
        for(int i=0;i<n;i++){
            nodes[i].label=i+1;
        }
    }

    void addedge(int u, int v){
        //select node u and push v into u's neighbour
        auto element_loc = find(nodes[u-1].neighbours.begin(), nodes[u-1].neighbours.end(), v);
        if (element_loc == nodes[u-1].neighbours.end()) {
            nodes[u-1].neighbours.push_back(v);
        }
        //select node v and push u into v's neighbour
        element_loc = find(nodes[v-1].neighbours.begin(), nodes[v-1].neighbours.end(), u);
        if (element_loc == nodes[v-1].neighbours.end()) {
            nodes[v-1].neighbours.push_back(u);
        }
    }

    void print(){
        //lets iterate through each node and print its neighbours
        for(int i=0;i<n;i++){
            cout<<"Edges of "<<i+1<<" : ";
            for (auto edge : nodes[i].neighbours) {
                cout<<edge<<" ";
            }
            cout<<endl;
        }
    }
};

int main() {
    Graph * g = new Graph;
    g->intializenodes();
    //add edges for the graphs here.
    g->addedge(1,2);
    g->addedge(1,3);
    g->addedge(1,4);
    g->addedge(1,5);
    g->addedge(2,1);
    g->addedge(2,6);
    g->addedge(2,3);
    g->addedge(3,1);
    g->addedge(3,2);
    g->addedge(4,1);
    g->addedge(4,6);
    g->addedge(4,7);
    g->addedge(4,8);
    g->addedge(5,1);
    g->addedge(5,6);
    g->addedge(5,7);
    g->addedge(5,8);
    g->addedge(6,2);
    g->addedge(6,4);
    g->addedge(6,5);
    g->addedge(7,4);
    g->addedge(7,5);
    g->addedge(8,4);
    g->addedge(8,5);
    //print the graph adjaceny list
    g->print();
}
