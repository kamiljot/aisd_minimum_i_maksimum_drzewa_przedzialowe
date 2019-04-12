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

node* MakeChild(node* root, int* tab){
    root->left = new node;
    root->right = new node;

    root->left->parent = root;
    root->left->left = nullptr;
    root->left->right = nullptr;

    root->left->min = tab[root->start];
    root->left->max = tab[root->start];

    root->right->parent = root;
    root->right->left = nullptr;
    root->right->right = nullptr;

    root->right->min = tab[root->end];
    root->right->max = tab[root->end];

    if (root->end - root->start == 1 || root->end == root->start){
        root->left->start = root->start;
        root->left->end = root->start;
        root->right->start = root->end;
        root->right->end = root->end;
    } else { 
        if (root->start < root->end){
        
            for (int i = root->start; i < ((root->end - root->start) / 2); i++){
                if (tab[i] < root->left->min){
                    root->left->min = tab[i];
                }
                if (tab[i] > root->left->max){
                    root->left->max = tab[i];
                }
            }
            for (int i = ((root->end - root->start) / 2 + 1); i < root->end; i++){
                if (tab[i] < root->right->min){
                    root->right->min = tab[i];
                }
                if (tab[i] > root->right->max){
                    root->right->max = tab[i];
                }
            }

            root->left->start = root->start;
            cout << root->left->start << endl;
            root->left->end = ((root->end - root->start) / 2);
            cout << root->left->end << endl;
            root->right->start = ((root->end - root->start) / 2 + 1);
            cout << root->right->start << endl;
            root->right->end = root->end;
            cout << root->right->end << endl;

            MakeChild(root->left, tab);
            MakeChild(root->right, tab);
    
            }
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

    root = MakeChild(root, tab);


    PrintRoot(root);


    /* while (cin){
     * cin >> start >> end;
     * SearchMinMax(root, start, end);
     * }
     */


    return 0;
}
