using namespace std;
#include<iostream>

class Node {
    Node* lchild;
    Node* rchild;
    int value;
    public:
        Node(int val) {
            lchild = NULL;
            rchild = NULL;
            value = val;
        }
        int getValue() {
            return value;
        }
        Node* getLChild() {
            return lchild;
        }
        Node* getRChild() {
            return rchild;
        }
        void setRChild(Node* right) {
            rchild = right;
        }
        void setLChild(Node* left) {
            lchild = left;
        }

        void setValue(int val) {
            value = val;
        }
};
class BinarySearchTree {
    Node* root;
    void inOrderRoutine(Node* parent);
    void preOrderRoutine(Node* parent);
    void postOrderRoutine(Node* parent);
    Node* successorRoutine(Node* root);
    Node* predecessorRoutine(Node* parent);
    void deleteNodeRoutine(Node* node);
    public:
        BinarySearchTree() {
            root = NULL;
        }
        bool isEmpty() {return root == NULL;};
        void insertNode(int val);
        void deleteNode(int val);
        Node* searchNode(int val);
        void preOrder();
        void postOrder();
        void inOrder();
        Node* successor(int val);
        Node* predecessor(int val);
};


void BinarySearchTree :: insertNode(int val) {
    Node *newNode= new Node(val);
    if (isEmpty()) {
        root = newNode;
        cout << "Inserting New Node " << val << " as root" << "\n";
    } else {
        Node* parent = NULL;
        Node* temp = root;
        while(temp != NULL) {
            parent = temp;
            if (val < temp->getValue())
                temp = temp->getLChild();
            else
                temp = temp->getRChild();
        }
        if (val < parent->getValue())
            parent->setLChild(newNode);
        else
            parent->setRChild(newNode);
        cout << "Inserting New Node " << val << " as a "
             << (val < parent->getValue() ? "left" : "right")
             << " child of " << parent->getValue() << "\n";
    }
}

Node* BinarySearchTree :: searchNode (int val) {
    Node* temp = root;
    while (temp != NULL) {
        if (temp->getValue() == val)
            return temp;
        else if (val < temp->getValue())
            temp = temp->getLChild();
        else
            temp = temp->getRChild();
    }
    return NULL;
}

Node* BinarySearchTree :: successor(int val) {
    return successorRoutine(searchNode(val));
}
Node* BinarySearchTree :: successorRoutine(Node* node) {
    if (node == NULL)
        return NULL;
    Node* successor;
    if (node->getRChild() == NULL) {
        Node* temp = root;
        while (temp != NULL) {
            if (temp->getValue() == node->getValue()) {
                break;
            } else if (node->getValue() < temp->getValue()) {
                successor = temp;
                temp = temp->getLChild();
            } else {
                temp = temp->getRChild();
            }
        }
    } else {
        // Leftmost child of right node is successor.
        successor = node->getRChild();
        while (successor->getLChild() != NULL)
            successor = successor->getLChild();
    }
    return successor;
}

Node* BinarySearchTree :: predecessor(int val) {
    return predecessorRoutine(searchNode(val));
}

Node* BinarySearchTree :: predecessorRoutine(Node* node) {
    if (node == NULL) {
        return NULL;
    }
    Node* predecessor;
    if (node->getLChild() == NULL) {
        Node* temp = root;
        while (temp != NULL) {
            if (temp == node) {
                break;
            } else if (node->getValue() < temp->getValue()) {
                temp = temp->getLChild();
            } else {
                predecessor = temp;
                temp = temp->getRChild();
            }

        }
    } else {
        // rightmost child of left node is predecessor
        predecessor = node->getLChild();
        while (predecessor->getRChild() != NULL)
            predecessor = predecessor->getRChild();
    }
    return predecessor;
}
void BinarySearchTree :: deleteNode(int val) {
    return deleteNodeRoutine(searchNode(val));
}
void BinarySearchTree :: deleteNodeRoutine(Node* node) {
    if (node == NULL)
        return;
    Node* lChild = node->getLChild();
    Node* rChild = node->getRChild();

    // no offspring -> just delete the node
    if (lChild == NULL && rChild == NULL) {
        Node* temp = root;
        Node* parent;
        while (temp != NULL) {
            if (node == temp) {
                break;
            } else {
                parent = temp;
                if (node->getValue() < temp->getValue())
                    temp = temp->getLChild();
                else
                    temp = temp->getRChild();
            }
        }
        if (parent->getLChild() == node)
            parent->setLChild(NULL);
        else if (parent->getRChild() == node)
            parent->setRChild(NULL);
        delete node;
    }

    // one offspring -> copy that as node and delete offspring.
    if ((lChild == NULL || rChild == NULL) &&
            !(lChild == NULL && rChild == NULL)) {
        if (lChild != NULL) {
            node->setValue(lChild->getValue());
            node->setLChild(lChild->getLChild());
            node->setRChild(lChild->getRChild());
            delete lChild;
        } else if (rChild != NULL) {
            node->setValue(rChild->getValue());
            node->setLChild(rChild->getLChild());
            node->setRChild(rChild->getRChild());
            delete rChild;
        }
    }

    // if both offspring present, find successor and replace it with the node.
    if (!(lChild == NULL) && !(rChild == NULL)) {
        Node* successor = successorRoutine(node);
        node->setValue(successor->getValue());
        deleteNodeRoutine(successor);
    }
}

void BinarySearchTree :: preOrder() {
    preOrderRoutine(root);
}

void BinarySearchTree :: postOrder() {
    postOrderRoutine(root);
}

void BinarySearchTree :: inOrder() {
    inOrderRoutine(root);
}
void BinarySearchTree :: preOrderRoutine(Node* parent) {
    if (parent == NULL)
        return;
    cout << " " << parent->getValue() <<" ";
    preOrderRoutine(parent->getLChild());
    preOrderRoutine(parent->getRChild());
}
void BinarySearchTree :: postOrderRoutine(Node* parent) {
    if (parent == NULL)
        return;
    postOrderRoutine(parent->getLChild());
    postOrderRoutine(parent->getRChild());
    cout << " " << parent->getValue() <<" ";
}
void BinarySearchTree :: inOrderRoutine(Node* parent) {
    if (parent == NULL)
        return;
    inOrderRoutine(parent->getLChild());
    cout << " " << parent->getValue() <<" ";
    inOrderRoutine(parent->getRChild());
}

int main() {
    BinarySearchTree bst;
    enum {QUIT, INSERT, SEARCH, INORDER, PREORDER, POSTORDER, SUCCESSOR, PREDECESSOR, DELETE};
    int option = -1;
    int el;
    while (option != QUIT) {
        cout << "What you want to do now?"<<"\n";
        cin >> option;
        switch (option) {
            case INSERT:    // 1
                {
                    int T;
                    cout << "Number of item to insert" << "\n";
                    cin >> T;
                    while (T-- > 0) {
                        cin >> el;
                        bst.insertNode(el);
                    }
                    break;
                }
            case SEARCH: // 2
                {
                    cout << "Value you want to search?" << "\n";
                    cin >> el;
                    Node* node = bst.searchNode(el);
                    cout << "Searched node is " << node->getValue() << "\n";
                    break;
                }
            case INORDER: // 3
                cout << "Doing inorder traversal"<<"\n";
                bst.inOrder();
                cout << "\n";
                break;
            case PREORDER: // 4
                cout << "Doing preorder traversal"<<"\n";
                bst.inOrder();
                bst.preOrder();
                cout << "\n";
                break;
            case POSTORDER: // 5
                cout << "Doing postorder traversal"<<"\n";
                bst.postOrder();
                cout << "\n";
                break;
            case SUCCESSOR: // 6
                {
                    cout << "Whose successor are you looking for?"<<"\n";
                    cin >> el;
                    Node* node = bst.successor(el);
                    cout << "Successor to node " << el << " is " << node->getValue() << "\n";
                    break;
                }
            case PREDECESSOR: // 7
                {
                    cout << "Whose predecessor are you looking for?"<<"\n";
                    cin >> el;
                    Node* node = bst.predecessor(el);
                    cout << "Predecessor to node " << el << " is " << node->getValue() << "\n";
                    break;
                }
            case DELETE: // 8
                cout << "Which element you want to delete?"<<"\n";
                cin >> el;
                bst.deleteNode(el);
                break;
            case QUIT: // 0
                cout<<"GoodBye!";
                return 0;
        }
    }
    return 0;
}
