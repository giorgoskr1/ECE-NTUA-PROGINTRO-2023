#include <iostream>  
#include <cstdio>  
  
using namespace std;  
  
struct node  
{  
    int info;  
    node *next;  
};  
  
class list  
{  
    public:  
        list();  
        bool empty();  
        int size();  
        void add(int k, int x);  
        int get(int k);  
        void remove(int k);  
  
        node *head;  
};  
  
list::list()  
{  
    head = nullptr;  
}  
bool list::empty()  
{  
    return head == nullptr;  
}  
int list::size()  
{  
    int cnt = 0;  
    if(head == nullptr) return 0;  
    else  
    {  
        node *p = new node;  
        p = head->next;  
        cnt++;  
        while(p->next != nullptr)  
        {  
            cnt++;  
            p = p->next;  
        }  
        return cnt;  
    }  
}  
void list::add(int k, int x)  
{  
    int i;  
    node *q = new node;  
    q->info = x;  
    q->next = nullptr;  
  
    if(head == nullptr)  
    {  
        node *n = new node;  
        n->info = 0;  
        n->next = nullptr;  
        head = n;  
        head->next = q;  
    }  
    else if(k == 1)  
    {  
        q->next = head->next;  
        head->next = q;  
    }  
    else  
    {  
        // first node  
        node *p = new node;  
        p = head->next;  
        for(i = 2; i < k; i++)  
        {  
            p = p->next;  
        }  
        q->next = p->next;  
        p-> next = q;  
    }  
}  
int list::get(int k)  
{  
    int i;  
    node *p = new node;  
    p = head -> next;  
    for(i = 1; i < k; i++)  
    {  
        p = p->next;  
    }  
    return p->info;  
}  
void list::remove(int k)  
{  
    int i;  
    node *p = new node;  
    p = head;  
    for(i = 1; i < k; i++)  
    {  
        p = p->next;  
    }  
    node *q = new node;  
    q = p->next;  
    p->next = q->next;  
}  
  
int main()  
{  
    int N, K, M, x, i, l, g;  
    list mylist;  
  
    scanf("%d", &N);  
    for(i = 0; i < N; i++)  
    {  
        scanf("%d %d", &K, &x);  
        mylist.add(K, x);  
    }  
    scanf("%d", &M);  
    for(i = 0; i < M; i++)  
    {  
        scanf("%d", &K);  
        mylist.remove(K);  
    }  
  
    scanf("%d", &K);  
    g = mylist.get(K);  
    l = mylist.size();  
    printf("%d %d\n", l, g);  
}  
