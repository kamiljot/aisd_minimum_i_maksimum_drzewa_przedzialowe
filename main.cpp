#include <iostream>
using namespace std;

struct node{
    int min;
    int max;
    int start;
    int end;
    node* parent;
    node* left;
    node* right;
};

int* Loader(int n){
    int input = 0;
    int* tab;
    tab = new int[n];

    for (int i = 0; i < n; i++){
        cin >> input;
        tab[i] = input;
    }
    return tab;
}


node* MakeRoot(int* tab, int n){
    node* root;
    root = new node;

    root->min = tab[0];
    root->max = tab[0];

    for (int i = 1; i < n; i++){
        if (tab[i] < root->min){
            root->min = tab[i];
        }
        if (tab[i] > root->max){
            root->max = tab[i];
        }
        root->start = 0;
        root->end = n - 1;
        root->parent = nullptr;
        root->left = nullptr;
        root->right = nullptr;
    }
    return root;
}

void PrintRoot(node* root){
    cout << root->min << " " << root->max << endl;
}

node* MakeIntervalTree(int* tab, int n){
    return MakeRoot(tab, n);
}


int main() {
    int n;
    int* tab;
    node* root;

    cin >> n;

    tab = Loader(n);

    root = MakeRoot(tab, n);

    PrintRoot(root);




    return 0;
}