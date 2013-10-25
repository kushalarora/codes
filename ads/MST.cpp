#include "MST.hpp"
#include<climits>

int MinimumSpanningTree::PRIMS(Graph<NodeMST> *G, NodeMST* source) {
    // init minQueue
    mQ->init(G);

    // start from source vertex
    NodeMST* currVertex = source;
    currVertex->setDistance(0);
    int total_dist = 0;


    while(!currVertex->isInTree()) {
        // add min vertex to tree
        currVertex->addToTree();
        total_dist += currVertex->getDistance();
        Edge* tmp = currVertex->getEdgeList();
        // set distance for all neighbours as edge weight between those two nodes
        while(tmp != NULL) {
            assert(tmp->getCurrentNode() == currVertex);
            NodeMST* other = (NodeMST*)tmp->getOtherNode();
            int weight = tmp->getWeight();

            // if a vertex which is not in a tree is found be at lesser distance that initially expected
            // reduce the distance.
            // Initially all are at infinite(INT_MAX) distance.
            if ((other->getDistance() > weight) &&
                (!other->isInTree())) {
                    mQ->decreaseKey(other, weight);
                    other->setParent(currVertex);
                }
            tmp = tmp->getNext();
        }
        // get vertex which is at minimum distance wrt to minimum spanning tree.
        currVertex = mQ->getMinWeightNode();
    }
    return total_dist;
}


void MinimumSpanningTree::printMSTEdges(Graph<NodeMST>* G) {
    // print all edges for mst.
    // format is (node)---weight--(node)
    NodeMST* parent;
    for (int i = 0; i < G->getNVertices(); i++) {
        NodeMST* node = G->getNodeByIndex(i);
        assert(node->isInTree());
        parent = node->getParent();
        if (parent == NULL)
            continue;
        Edge* tmp = parent->getEdgeList();
        while(tmp != NULL) {
            assert(tmp->getCurrentNode() == parent);
            if (tmp->getOtherNode() == node) {
                //parent->printNode();
                //tmp->printEdge();
                //node->printNode();
                cout << parent->getValue() <<" "<< node->getValue();
                cout << endl;
                break;
            }
            tmp = tmp->getNext();
        }
    }
}
void SimpleMinQueueWrapper::decreaseKey(NodeMST* node, int weight) {
    // in simple scheme for decreaseKey you just have to change distance.
    if (weight < node->getDistance())
        node->setDistance(weight);
}
NodeMST* SimpleMinQueueWrapper::getMinWeightNode() {
    int distance = INT_MAX;
    NodeMST* smallest_node;
    // traverse whole node list and find node with minimum distance
    // return that node
    for (int i = 0; i < g->getNVertices(); i++) {
        NodeMST* node = g->getNodeByIndex(i);
        if ((!node->isInTree()) &&
                distance > node->getDistance()) {
            distance = node->getDistance();
            smallest_node = node;
        }
    }
    return smallest_node;
}

void FHeapQueueWrapper::init(Graph<NodeMST>* G) {
    // insert all nodes in heap with priority as INT_MAX;
    for (int i = 0; i < G->getNVertices(); i++) {
        heap.insertNode(G->getNodeByIndex(i), INT_MAX);
    }
}

void FHeapQueueWrapper::insertNode(NodeMST* node) {
    heap.insertNode(node, INT_MAX);
}

void FHeapQueueWrapper::decreaseKey(NodeMST* node, int weight) {
    // decrease priority of node
    // set distance in node
    if (node->getDistance() > weight){
        node->setDistance(weight);
        heap.decreaseKey(node, weight);
    }
}

NodeMST* FHeapQueueWrapper::getMinWeightNode() {
    return heap.extractMin();
}

