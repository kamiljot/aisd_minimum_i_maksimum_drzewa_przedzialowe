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
    }
    root->start = 0;
    cout << root->end << endl;
    root->end = m - 1;
    cout << root->end << endl;
    root->parent = nullptr;
    root->left = nullptr;
    root->right = nullptr;

    return root;
}

node* MakeChild(node* root, int* tab, int start, int end){
    root->left = new node;
    root->right = new node;

    root->left->parent = root;
    root->left->left = nullptr;
    root->left->right = nullptr;

    root->left->min = tab[start];
    root->left->max = tab[start];

    root->right->parent = root;
    root->right->left = nullptr;
    root->right->right = nullptr;

    root->right->min = tab[end];
    root->right->max = tab[end];

    if (end - start == 1 || end == start){
        root->left->start = start;
        root->left->end = start;
        root->right->start = end;
        root->right->end = end;
    } else {
        for (int i = start; i < ((end - start) / 2); i++){
            if (tab[i] < root->left->min){
                root->left->min = tab[i];
            }
            if (tab[i] > root->left->max){
                root->left->max = tab[i];
            }
        }
        for (int i = ((end - start) / 2 + 1); i < end; i++){
            if (tab[i] < root->right->min){
                root->right->min = tab[i];
            }
            if (tab[i] > root->right->max){
                root->right->max = tab[i];
            }
        }

        root->left->start = start;
        root->left->end = ((end - start) / 2);
        root->right->start = ((end - start) / 2 + 1);
        cout << root->right->start << endl;
        root->right->end = end;
        MakeChild(root->left, tab, root->left->start, root->left->end);
        MakeChild(root->right, tab, root->right->start, root->right->end);
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



int main() {
    int n, m;
    int* tab;
    node* root;

    cin >> n;
    m = CalcM(n);
    tab = Loader(n, m);
    PrintTab(tab, m);

    root = MakeRoot(tab, m);

    root = MakeChild(root, tab, root->start, root->end);


    PrintRoot(root);


    /* while (cin){
     * cin >> start >> end;
     * SearchMinMax(root, start, end);
     * }
     */


    return 0;
}