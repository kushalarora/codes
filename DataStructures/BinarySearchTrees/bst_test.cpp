#include "bst_inl.h"
#include "bst.cpp"
int main() {
    BinarySearchTree<int, int> bst;
    enum {QUIT, INSERT, SEARCH, INORDER, PREORDER, POSTORDER, SUCCESSOR, PREDECESSOR, DELETE, GETBYINDEX};
    int option = -1;
    int el;
    while (option != QUIT) {
        cout << "What you want to do now?"<<"\n";
        cout <<"0. QUIT 1. INSERT 2.SEARCH 3. INORDER 4. PREORDER 5.POSRORDER 6.SUCCESSOR 7.PREDECESSOR 8.DELETE 9.GETBYINDEX\n";
        cin >> option;
        switch (option) {
            case INSERT:    // 1
                {
                    int T;
                    cout << "Number of item to insert" << "\n";
                    cin >> T;
                    while (T-- > 0) {
                        cin >> el;
                        bst.insertNode(el, el);
                    }
                    break;
                }
            case SEARCH: // 2
                {
                    cout << "Value you want to search?" << "\n";
                    cin >> el;
                    Node<int,int>* node = bst.searchNode(el);
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
                    Node<int,int>* node = bst.successor(el);
                    cout << "Successor to node " << el << " is " << node->getValue() << "\n";
                    break;
                }
            case PREDECESSOR: // 7
                {
                    cout << "Whose predecessor are you looking for?"<<"\n";
                    cin >> el;
                    Node<int,int>* node = bst.predecessor(el);
                    cout << "Predecessor to node " << el << " is " << node->getValue() << "\n";
                    break;
                }
            case DELETE: // 8
                cout << "Which element you want to delete?"<<"\n";
                cin >> el;
                bst.deleteNode(el);
                break;
            case GETBYINDEX: // 9
                {
                    cout << "Enter Index of the item you are looking for?"<<"\n";
                    cin >> el;
                    Node<int,int>* node = bst.getNodeByIndex(el);
                    cout << "Item found is " <<node->getValue() << "\n";
                    break;
                }
            case QUIT: // 0
                cout<<"GoodBye!";
                return 0;
        }
    }
    return 0;
}
