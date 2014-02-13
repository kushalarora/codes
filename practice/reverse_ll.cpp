#include<iostream>

using namespace std;

/*
 *  1->2->3->4
 *
 *  1<-2<-3<-4
 */

struct Node {
    int data;
    Node* next;
};

void reverseLL(Node** headP) {
    if ((*headP) == NULL)
        return;

    Node* tmp = *headP;
    Node* tmp_n = (*headP)->next;
    Node* tmp_tmp;
    while(tmp_n != NULL) {
        tmp_tmp = tmp_n->next;
        tmp_n->next = tmp;
        tmp = tmp_n;
        tmp_n = tmp_tmp;
    }

    (*headP)->next = NULL;

    *headP = tmp;
}

void printList(Node* head) {
    Node* tmp = head;
    cout << "\n";
    while(tmp != NULL) {
        cout << tmp->data << "\t";
        tmp = tmp->next;
    }
}

int main() {
    int T, val;
    cin >> T;
    Node *head, *current;
    cin >> val;
    Node* node = new Node;
    node->data = val;
    node->next = NULL;
    head = node;
    current = node;
    T--;

    while(T--) {
        Node* node = new Node;
        cin >> val;
        node->data = val;
        node->next = NULL;
        current->next = node;
        current = node;
    }

    printList(head);

    reverseLL(&head);

    printList(head);
}
