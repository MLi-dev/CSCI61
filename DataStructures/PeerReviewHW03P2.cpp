#include <iostream>
using namespace std;

class node {
public:
    node* leftChild;
    node* rightChild;
    char expression;
};

char* binaryTree(node** n1,char* c) {
    if(c == 0)
        return NULL;
    while(true) {
        char* tmp = NULL;
        if(*n1 == NULL) {
            node* newNode = (node*) malloc(sizeof(node));
            newNode -> leftChild = NULL;
            newNode -> rightChild = NULL;
            newNode -> expression = *c;
            *n1 = newNode;
        }
        else {
            if((*c >= '0' && *c <= '9') || (*c >= 'A' && *c <= 'Z') || (*c >= 'a' && *c <= 'z')) {
                return c;
            }
            tmp = binaryTree(&(*n1) -> leftChild, (c + 1));
            tmp = binaryTree(&(*n1) -> rightChild, (tmp + 1));
            return tmp;
        }
    }
}

void toInfix(node *n1) {
    if(n1 == NULL) {
        return;
    }
    else {
        toInfix(n1 -> leftChild);
        cout << (n1 -> expression);
        toInfix(n1 -> rightChild);
    }
}

void toPostfix(node* n1) {
    if(n1 == NULL){
        return;
    }
    else {
        toPostfix(n1 -> leftChild);
        toPostfix(n1 -> rightChild);
        cout << (n1 -> expression);
    }
}

void conversion(char p[]) {
    node* tmp = NULL;
    binaryTree(&tmp, p);
    cout << "To infix: ";
    toInfix(tmp);
    cout << endl;
    cout << "To postfix: ";
    toPostfix(tmp);
}

int main() {
    char p[10];
    cout << "Please type the prefix: ";
    cin >> p;
    conversion(p);
    cout << endl;
    return 0;
}
// -/+8203*32