#include <iostream>

struct node {
    int info;
    node* left, *right;
};

node* tree = NULL;

void Push(int value, node **t) {
    if((*t) == NULL) {
        (*t) = new node;
        (*t)->info = value;
        (*t)->left = (*t)->right = NULL;
        return;
    }

    if(value > (*t)->info) Push(value, &(*t)->right);
    else Push(value, &(*t)->left);
}

void PrintTree(node* t, int u) {
    if(t == NULL) return;
    else {
        PrintTree(t->left, ++u);
        for(int i = 0; i < u; ++i) std::cout << "\tl";
        std::cout << "\t" << t->info << std::endl;
        --u;
    }
    PrintTree(t->right, ++u);
}

int main() {
    int quantity = 0;
    int number = 0;

    std::cout << "\tEnter quantity of elements: ";
    std::cin >> quantity;

    for(int i = 0; i < quantity; ++i) {
        std::cout << "\tEnter the number: ";
        std::cin >> number;

        Push(number, &tree);
    }

    std::cout << "\tYour tree" << std::endl;
    PrintTree(tree, 0);

    return 0;
}
