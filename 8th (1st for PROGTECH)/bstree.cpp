#include <iostream>  
#include <cstdio>  
#include <algorithm>  
  
using namespace std;  
  
struct node  
{  
    int info;  
    node *right, *left;  
};  
class bstree  
{  
    public:  
        bstree();  
        int height(node *r);  
        void insert(int x, node *r);  
        int search(int x, node *r, int cnt);  
        int min();  
        int max();  
        void inorder(node *r);  
        void preorder(node *r);  
        void postorder(node *r);  
  
        node *root;  
};  
  
bstree::bstree()  
{  
    node *n = new node;  
    n->info = 0;  
    n->right = nullptr;  
    n->left = nullptr;  
    root = n;  
}  
int bstree::height(node *r)  
{  
    int ltree, rtree;  
    if(r == nullptr) return 0;  
    else  
    {  
        ltree = height(r->left);  
        rtree = height(r->right);  
        return std::max(ltree, rtree) + 1;  
    }  
}  
void bstree::insert(int x, node *r)  
{  
    int value;  
    node *q = new node;  
    q->info = x;  
    q->right = nullptr;  
    q->left = nullptr;  
  
    if(root->info == 0) root->info = x;  
    else  
    {  
        value = r->info;  
  
        if(value > x)  
        {  
            if(r->left == nullptr) r->left = q;  
            else insert(x, r->left);  
        }  
        else if(value < x)  
        {  
            if(r->right == nullptr) r->right = q;  
            else insert(x, r->right);  
        }  
    }  
}  
int bstree::search(int x, node *r, int cnt)  
{  
    int value = r->info;  
  
    if(value == x) return cnt;  
    else if(value > x)  
    {  
        if(r->left == nullptr) return 0;  
        else  
        {  
            cnt++;  
            search(x, r->left, cnt);  
        }  
    }  
    else  
    {  
        if(r->right == nullptr) return 0;  
        else  
        {  
            cnt++;  
            search(x, r->right, cnt);  
        }  
    }  
}  
int bstree::min()  
{  
    node *p = new node;  
    p = root;  
  
    while(p->left != nullptr)  
    {  
        p = p->left;  
    }  
    return p->info;  
}  
int bstree::max()  
{  
    node *p = new node;  
    p = root;  
  
    while(p->right != nullptr)  
    {  
        p = p->right;  
    }  
    return p->info;  
}  
void bstree::preorder(node *r)  
{  
    if(r != nullptr)  
    {  
        printf("%d ", r->info);  
        preorder(r->left);  
        preorder(r->right);  
    }  
}  
void bstree::inorder(node *r)  
{  
    if(r != nullptr)  
    {  
        inorder(r->left);  
        printf("%d ", r->info);  
        inorder(r->right);  
    }  
}  
void bstree::postorder(node *r)  
{  
    if(r != nullptr)  
    {  
        postorder(r->left);  
        postorder(r->right);  
        printf("%d ", r->info);  
    }  
}  
  
int main()  
{  
    int N, M, num, i;  
    int h, minimum, maximum, s;  
    bstree mytree;  
  
    scanf("%d", &N);  
    for(i = 0; i < N; i++)  
    {  
        scanf("%d", &num);  
        mytree.insert(num, mytree.root);  
    }  
    h = mytree.height(mytree.root);  
    printf("%d\n", h);  
    minimum = mytree.min();  
    maximum = mytree.max();  
    printf("%d %d\n", minimum, maximum);  
    scanf("%d", &M);  
    for(i = 0; i < M; i++)  
    {  
        scanf("%d", &num);  
        s = mytree.search(num, mytree.root, 1);  
        if(i < M - 1) printf("%d ", s);  
        else printf("%d\n", s);  
    }  
    mytree.inorder(mytree.root);  
    printf("%s\n", "end");  
    mytree.preorder(mytree.root);  
    printf("%s\n", "end");  
    mytree.postorder(mytree.root);  
    printf("%s\n", "end");  
}  
