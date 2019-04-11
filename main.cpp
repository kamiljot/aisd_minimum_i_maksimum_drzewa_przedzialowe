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

int CalcM(int n){
    int m = 1;
    while (m < n){
        m *= 2;
    }
    return m;
}

int* Loader(int n, int m){
    int input = 0;
    int i;
    int* tab;
    tab = new int[m];

    for (i = 0; i < n; i++){
        cin >> input;
        tab[i] = input;
    }
    for (i; i < m; i++){
        tab[i] = 5;
    }
    return tab;
}


node* MakeRoot(int* tab, int m){
    node* root;
    root = new node;

    root->min = tab[0];
    root->max = tab[0];

    for (int i = 1; i < m; i++){
        if (tab[i] < root->min){
            root->min = tab[i];
        }
        if (tab[i] > root->max){
            root->max = tab[i];
        }
        root->start = 0;
        root->end = m - 1;
        root->parent = nullptr;
        root->left = nullptr;
        root->right = nullptr;
    }
    return root;
}

void PrintTab(int* tab, int m){
    for (int i = 0; i < m; i++){
        cout << tab[i] << " ";
    }
    cout << endl;
}


void PrintRoot(node* root){
    cout << root->min << " " << root->max << endl;
}

node* MakeIntervalTree(int* tab, int m, node* root){


}


int main() {
    int n, m;
    int* tab;
    node* root;

    cin >> n;
    m = CalcM(n);
    tab = Loader(n, m);
    PrintTab(tab, m);


    root = MakeRoot(tab, m);

    PrintRoot(root);


    /* while (cin){
     * cin >> start >> end;
     * SearchMinMax(root, start, end);
     * }
     */


    return 0;
}