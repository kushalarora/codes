#include "bst_inl.h"

template<class T, class Y>
void BinarySearchTree<T,Y> :: insertNode(T key, Y val) {
    insertNode(new Node<T,Y>(key, val));
}

template<class T, class Y>
void BinarySearchTree<T,Y> :: insertNode(node_ptr newNode) {
    if (newNode == NULL) {
        debug("New Node is empty");
        assert(true);
    }
    int index = 0;
    int val = newNode->getValue();
    if (isEmpty()) {
        root = newNode;
        debug2("Inserting as root- Node ",val);
    } else {
        node_ptr parent = NULL;
        node_ptr temp = root;
        while(temp != NULL) {
            parent = temp;
            if (val < temp->getValue()) {
                // inc no of node of the left as inserting a child to left.
                temp->incLeftSize();

                temp = temp->getLChild();
            } else {
                temp = temp->getRChild();
            }
        }
        if (val < parent->getValue())
            parent->setLChild(newNode);
        else
            parent->setRChild(newNode);
        debug3(val,(val < parent->getValue() ? "left" : "right"), parent->getValue());
    }
}

template<class T, class Y>
typename BinarySearchTree<T,Y>::node_ptr BinarySearchTree<T,Y> :: searchNode (T val) {
    return searchNodeRoutine(val, false);
}

template<class T, class Y>
typename BinarySearchTree<T,Y>::node_ptr BinarySearchTree<T,Y> :: searchNodeRoutine (T val, bool isDeleteOp) {
    node_ptr temp = root;
    while (temp != NULL) {
        if (temp->getValue() == val)
            return temp;
        else if (val < temp->getValue()) {
            if (isDeleteOp)
                // reduce leftsize i.e. No of elements present left to the node
                temp->decLeftSize();

            temp = temp->getLChild();
        } else {
            temp = temp->getRChild();
        }
    }
    return NULL;
}

template<class T, class Y>
typename BinarySearchTree<T,Y>::node_ptr BinarySearchTree<T,Y> :: successor(T val) {
    return successorRoutine(searchNode(val));
}

template<class T, class Y>
typename BinarySearchTree<T,Y>::node_ptr BinarySearchTree<T,Y> :: successorRoutine(node_ptr node) {
    if (node == NULL)
        return NULL;
    node_ptr successor;
    if (node->getRChild() == NULL) {
        node_ptr temp = root;
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

template<class T, class Y>
typename BinarySearchTree<T,Y>::node_ptr BinarySearchTree<T,Y> :: predecessor(T val) {
    return predecessorRoutine(searchNode(val));
}

template<class T, class Y>
typename BinarySearchTree<T,Y>::node_ptr BinarySearchTree<T,Y> :: predecessorRoutine(node_ptr node) {
    if (node == NULL) {
        return NULL;
    }
    node_ptr predecessor;
    if (node->getLChild() == NULL) {
        node_ptr temp = root;
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

template<class T, class Y>
void BinarySearchTree<T,Y> :: deleteNode(T val) {
    return deleteNodeRoutine(searchNodeRoutine(val, true));
}

template<class T, class Y>
void BinarySearchTree<T,Y> :: deleteNodeRoutine(node_ptr node) {
    if (node == NULL)
        return;

    node_ptr lChild = node->getLChild();
    node_ptr rChild = node->getRChild();

    // no offspring -> just delete the node
    if (lChild == NULL && rChild == NULL) {
        node_ptr temp = root;
        node_ptr parent;
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
            node = lChild;
            node->setLChild(lChild->getLChild());
            node->setRChild(lChild->getRChild());
            delete lChild;
        } else if (rChild != NULL) {
            node = rChild;
            node->setLChild(rChild->getLChild());
            node->setRChild(rChild->getRChild());
            delete rChild;
        }
    }

    // if both offspring present, find successor and replace it with the node.
    if (!(lChild == NULL) && !(rChild == NULL)) {
        node_ptr successor = successorRoutine(node);
        node = successor;
        deleteNodeRoutine(successor);
    }
}

template<class T, class Y>
void BinarySearchTree<T,Y> :: preOrder() {
    preOrderRoutine(root);
}

template<class T, class Y>
void BinarySearchTree<T,Y> :: postOrder() {
    postOrderRoutine(root);
}

template<class T, class Y>
void BinarySearchTree<T,Y> :: inOrder() {
    inOrderRoutine(root);
}

template<class T, class Y>
void BinarySearchTree<T,Y> :: preOrderRoutine(node_ptr parent) {
    if (parent == NULL)
        return;
    cout << parent->getValue() << " " << parent->getLeftSize()<<"\t";
    preOrderRoutine(parent->getLChild());
    preOrderRoutine(parent->getRChild());
}

template<class T, class Y>
void BinarySearchTree<T,Y> :: postOrderRoutine(node_ptr parent) {
    if (parent == NULL)
        return;
    postOrderRoutine(parent->getLChild());
    postOrderRoutine(parent->getRChild());
    cout << parent->getValue() << " " << parent->getLeftSize()<<"\t";
}

template<class T, class Y>
void BinarySearchTree<T,Y> :: inOrderRoutine(node_ptr parent) {
    if (parent == NULL)
        return;
    inOrderRoutine(parent->getLChild());
    cout << parent->getValue() << " " << parent->getLeftSize()<<"\t";
    inOrderRoutine(parent->getRChild());
}

template<class T, class Y>
typename BinarySearchTree<T,Y>::node_ptr BinarySearchTree<T,Y> :: getNodeByIndex(int index) {
   node_ptr temp = root;
   while(temp != NULL) {
       if (temp->getLeftSize() == index) {
           return temp;
       } else if (index > temp->getLeftSize()) {
           // item not present in first leftSize nodes,
           // look in right subtree with index relative to
           // first element in that tree.
           index -= (temp->getLeftSize() + 1);

           temp = temp->getRChild();
       } else {
           temp = temp->getLChild();
       }
   }
}
