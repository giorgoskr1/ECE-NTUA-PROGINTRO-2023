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
        int searchMF(int x);  
  
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
int list::searchMF(int x)  
{  
    int cnt = 0;  
    bool ok = false;  
    node *p = new node;  
    p = head;  
    while(p->next != nullptr)  
    {  
        p = p->next;  
        cnt++;  
        if(p->info == x)  
        {  
            ok = true;  
            break;  
        }  
    }  
    if(not ok) return 0;  
    remove(cnt);  
    add(1, x);  
    return cnt;  
}  
  
int main()  
{  
    int N, K, M, x, i, sum = 0, s = 0;  
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
        scanf("%d", &x);  
        s = mylist.searchMF(x);  
        sum += s;  
    }  
    printf("%d\n", sum);  
}  
