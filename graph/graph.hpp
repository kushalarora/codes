/*
 * GRAPH ALOGRITHMS
 *
 * 1. Types of Graphs
 *      Undirected vs Directed
 *      Weighted vs Unweighted
 *          The difference is particularly apperant in shortest path problem.
 *          For Unweighted graph its BFS. For Weighted Graph we need Djzxtra and Bellman Ford.
 *      Simple vs Non Simple
 *          Self Loop and multiedges present - Non Simple
 *      Sparse vs Dense
 *          Typically is edges are linear to vertices, its sparse.
 *          If quadratic its dense.
 *      Cyclic vs Acyclic
 *          Acyclic doesn't contain any cycles.
 *          Example Trees(Connected Acyclic Undirected Graphs{Hoping you use doubly linked structure})
 *          Directed Acyclic Graph, example scheduling problem.
 *          Topological Sorting orders the vertices of *DAG* according to constraints.
 *          Topological Sorting is first step in any DAG problem.
 *      Embedded vs Topological
 *          Graph embedded in space where each vertices is assigned a geometric position.
 *          Topological graph are where geometry of the graph is important.
 *
 * 2. Representation of a Graph
 *      1. Adjacency Matrix
 *          M[i, j] =   1 if (i,j) has an edge else 0
 *          Faster queries like "is (i,j) in G, faster updates, deletion
 *          Excessive space for sparse graph. Used only for dense graph.
 *
 *      2. Adjacency List
 *          Used all the time as most real life graphs are sparse.
 *          Linked representation of graph.
 *          An array of nodes containing all vertices.
 *          Each array node is a linked list containing all edges directed outward/inwards of the graph.
 *          Generally outward is used.
 *          Each node contains
 *              i.   Label
 *              ii.  Weight
 *              iii. Value
 *              iv.  Pointer to next edge node.
 *
 *          Apart from this the main structure contains some journaling info like
 *              i.   Array of degree of each node.
 *              ii.  No. of vertices.
 *              iii. No. of edges
 *              iv.  boolean directed.
 */

#include<iostream>
#include<string>
#include<stdlib.h>     // for rand()
#include<time.h>
#include<assert.h>

using namespace std;

#ifndef __GRAPH__
#define __GRAPH__
const int MAXV = 100000;

// forward declaration to resolve circular dependency.

template<class T>
class Edge {
    T* node1;
    T* node2;
    bool is_directed;
    float weight;
    Edge<T>* next;
    const static float DEFAULT_WEIGHT = 0.0f;
    public:
        Edge(T* n1, T* n2);
        Edge(T* n1, T* n2, bool is_directed, float weight);
        Edge(T* n1, T* n2, bool is_directed);
        Edge(T* n1, T* n2, float weight);
        Edge<T>* getNext() {return next;}
        void setNext(Edge<T>* next) {this->next = next;}
        T* getCurrentNode() {return node1;}
        T* getOtherNode() { return node2;}
        bool isDirected() {return is_directed;}
        float getWeight() {return weight;}
        bool operator ==(Edge<T>* edge2);
        void printEdge();
};

template<class T>
class Graph {
    public:
        Graph();
        ~Graph();
        Graph(bool directed, bool weighted, bool labelled, bool valued);
        T* insertNode(T* node);
        void createEdge(T* V1, T* V2);
        void createEdge(T* V1, T* V2, float weight);
        inline bool isWeighted() {return weighted;}
        inline bool isDirected() {return directed;}
        inline bool isLabelled() {return labelled;}
        inline bool isValued() {return valued;}
        void printGraph();
        void createRandomGraph(int nVertices);
        void createRandomGraph(int nVertices, float density);
        int getNVertices() {return nVertices;}
        int getNEdge() {return nEdges;}
        T* getNodeByIndex(int i);
    private:
        int nVertices;
        int nEdges;
        bool directed;
        bool weighted;
        bool labelled;
        bool valued;
        int degree[MAXV];
        T* edgeNode[MAXV];
};

template<class T>
Edge<T>::Edge(T* n1, T* n2, bool is_directed, float weight) {
    node1 = n1;
    node2 = n2;
    this->is_directed = is_directed;
    this->weight = weight;
    this->next = NULL;
}

template<class T>
void Edge<T>::printEdge() {
    cout << (isDirected() ? "--" : "<--");
    if (getWeight() != DEFAULT_WEIGHT)
        cout << getWeight();
    cout << "-->";
}

template<class T>
Edge<T>::Edge(T* n1, T* n2) {
    Edge<T>(n1, n2, false, DEFAULT_WEIGHT);
}

template<class T>
Edge<T>::Edge(T* n1, T* n2, bool is_directed) {
    Edge<T>(n1, n2, is_directed, DEFAULT_WEIGHT);
}

template<class T>
Edge<T>::Edge(T* n1, T* n2, float weight) {
    Edge<T>(n1, n2, false, weight);
}

template<class T>
bool Edge<T>::operator ==(Edge<T>* edge2) {
    if (edge2 == NULL)
        return false;

    if (this->getCurrentNode() == edge2->getCurrentNode() &&
            this->getOtherNode() == edge2->getOtherNode() &&
                (this->getWeight() == edge2->getWeight()))
            return true;
    return false;
}


template<class T>
Graph<T>::Graph(bool dirctd, bool wghtd, bool lbled, bool valed) {
    nVertices = 0;
    nEdges = 0;
    for (int i = 0; i < MAXV; i++) {
        degree[i] = 0;
        edgeNode[i] = NULL;
    }
    directed = dirctd;
    weighted = wghtd;
    labelled = lbled;
    valued = valed;
}
template<class T>
Graph<T>::Graph() {
    Graph(false, false, false, false);
}


template<class T>
T* Graph<T>::insertNode(T* node) {
    int i;
    for (i = 0; i < nVertices; i++) {
        if (edgeNode[i] == node)
            // node already present
            return node;
    }
    edgeNode[i] = node;
    nVertices += 1;
    degree[i] = 0;
    node->setAdjecencyIndex(i);
    return node;
}


template<class T>
void Graph<T>::createEdge(T *V1, T *V2, float weight) {
    T* nodeArr[2] = {V1, V2};
    Edge<T>* newEdge;
    Edge<T>* temp;
    int i = 0, idx = 0;
    // ensure that both nodes were inserted into graph.
    assert(V1->getAdjecencyIndex() != -1);
    assert(V2->getAdjecencyIndex() != -1);

    for (i = 0; i < (isDirected() ? 1: 2); i++, degree[idx]++, idx = 1 - idx) {
        T* currNode = nodeArr[idx];
        T* othrNode = nodeArr[1 - idx];
        newEdge = new Edge<T>(currNode, othrNode, isDirected(), weight);

        // inserting edge to v2 in v1
        temp = currNode->getEdgeList();
        Edge<T>* prevEdge = temp;
        while(temp != NULL) {
            // if V2 already present do nothing.
            if (temp->getOtherNode() == nodeArr[1 - idx])
                return;
            prevEdge = temp;
            temp = temp->getNext();
        }
        if (prevEdge != NULL)
            prevEdge->setNext(newEdge);
        else
            currNode->setEdgeList(newEdge);
    }
    nEdges++;
}

template<class T>
void Graph<T>::createEdge(T *V1, T* V2) {
    createEdge(V1, V2, 0);
}

template<class T>
void Graph<T>::printGraph() {
    for (int i = 0; i < nVertices; i++) {
        T* node = edgeNode[i];
        node->printNode();
        Edge<T>* tmp = node->getEdgeList();
        while (tmp != NULL) {
            assert(tmp->getCurrentNode() == node);
            tmp->printEdge();
            (tmp->getOtherNode())->printNode();
            tmp = tmp->getNext();
        }
        cout<<"\n"<<"\n";
    }
}


template<class T>
void Graph<T>::createRandomGraph(int nVertices, float density) {
    srand(time(NULL));
    if (nVertices < 1)
        return;
    for (int i = 0; i < nVertices; i++) {
        insertNode((new T())->populateNode(isLabelled(),
                                    isValued(),
                                    nVertices));
    }
    int nEdges = nVertices * (density > 0.0 ? density * nVertices : (rand() % nVertices));
    cout<<"\nMaking "<<nEdges<<" Edges\n";
    for (long i = 0; i < nEdges; i++) {
        int idx1 = rand() % nVertices;
        int idx2 = rand() % nVertices;

        // ensures that there are no self loops
        while (idx1 == idx2)
            idx2 = rand() % nVertices;
        createEdge(edgeNode[idx1], edgeNode[idx2], (isWeighted() ? rand() % 100 : 0.0));
        //printNode(edgeNode[idx1]);printEdge(edgeNode[idx2]);printNode(edgeNode[idx2]);
    }

}

template<class T>
void Graph<T>::createRandomGraph(int nVertices) {
    createRandomGraph(nVertices, 0.0);
}

template<class T>
T* Graph<T>::getNodeByIndex(int i) {
    if (i < 0 || i >= nVertices)
        return NULL;
    return edgeNode[i];
}


template<class T>
Graph<T>::~Graph() {
    for (int i = 0; i < nVertices; i++) {
        T* tmp = edgeNode[i];
        Edge<T>* tmp2 = tmp->getEdgeList();
        Edge<T> *tmp3;
        while(tmp2 != NULL) {
            tmp3 = tmp2->getNext();
            delete tmp2;
            tmp2 = tmp3;
        }
        delete tmp;
    }
}
#endif
