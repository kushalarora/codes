#include "node.hpp"
#include "edge.hpp"
#include<time.h>
#include<stdlib.h>

Node::Node(int val, string lbl) {
    value = val;
    label = lbl;
    edge_list = NULL;
    adj_index = -1;
}

Node::Node(int val) {
    value = val;
    label = "";
    edge_list = NULL;
    adj_index = -1;
}
Node::Node(string lbl) {
    value = -1;
    label = lbl;
    edge_list = NULL;
    adj_index = -1;
}

Node::Node() {
    value = -1;
    label = "";
    edge_list = NULL;
    adj_index = -1;
}

// copy constructor
Node::Node(Node* node) {
    value = node->getValue();
    label = node->getLabel();
    edge_list = NULL;
    adj_index = node->getAdjecencyIndex();
}

// nodes are equal if either they are same or have same label.
bool Node::operator==(Node* node2) {
    if (this == node2)  // if pointer matches, return true
        return true;
    if (this->label.length() > 0 && node2->label.length() > 0)  // if label is defined match that.
        return this->label == node2->label;
    return false;
};

// prints (val label) for each node.
void Node::printNode() {
    cout << "( ";
    if (this->getLabel().length() > 0)
        cout << getLabel() << " ";
    if (getValue() > -1)
         cout << getValue() << " ";
     cout << ")";
}


string Node::createRandomLabels(int nVertices) {
    // length of random labels depending upon the size of input.
    // Using longer ranges(i.e. for 10 nodes the possible combinations are 26 * 26)
    // This way name collision is less likely.
    int len = nVertices < 10 ? 2 : nVertices < 100 ? 4 : nVertices < 1000 ? 5 : 8;

    // generate random len size words
    char sbuilder[len];
    for (int i = 0; i < len; i++) {
        sbuilder[i] = 'a' + rand() % 26;
    }

    // covert to string and return;
    string str = string(sbuilder, len);
    return str;
}

void Node::populateNode(bool labelled, bool valued, int seed) {
    // create random labels and values if graph with the node is
    // labelled and valued.
    if (labelled)
        this->setLabel(createRandomLabels(seed));

    if (valued)
        this->setValue(rand() % seed + 1);
}
Node::~Node() {
    // remove all edges too while deleting the node.
    Edge* edge = getEdgeList();
    Edge* tmp;
    while(edge != NULL) {
        tmp = edge->getNext();
        delete edge;
        edge = NULL;
        edge = tmp;
    }
}

ostream& operator <<(ostream& os, const Node& node) {
    // on cout << node, print label.
    os << node.label;
}
