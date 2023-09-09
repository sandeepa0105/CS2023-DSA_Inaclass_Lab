#include <iostream>
#include <list>
using namespace std;

struct Node {
    int label;              // Node label
    list<int> neighbors;    // List of neighbors
};

struct Graph {
    int n = 5;
    Node* nodes = new Node[n];

    void intializenodes() {
        for (int i = 0; i < n; i++) {
            nodes[i].label = i;
        }
    }

    void addedge(int u, int v) {
        // Add v to u's neighbors
        nodes[u].neighbors.push_back(v);

        // Add u to v's neighbors
        nodes[v].neighbors.push_back(u);
    }

    void print() {
        for (int i = 0; i < n; i++) {
            cout << "Node " << nodes[i].label << " is connected to: ";
            for (int neighbor : nodes[i].neighbors) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph* g = new Graph;
    g->intializenodes();

    // Add edges for the graph
    g->addedge(1, 2);
    g->addedge(1, 3);
    g->addedge(1, 5);
    g->addedge(1, 4);
    g->addedge(2, 3);
    g->addedge(2, 6);
    g->addedge(4, 6);
    g->addedge(4, 7);
    g->addedge(4, 8);
    g->addedge(5, 6);
    g->addedge(5, 7);
    g->addedge(5, 8);
    

    // Print the graph adjacency list
    g->print();

    delete g;
    return 0;
}
