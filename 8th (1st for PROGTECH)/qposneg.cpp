#include <iostream>  
#include <cstdio>  
  
  
using namespace std;  
  
struct node  
{  
    int info;  
    node *next;  
};  
  
class queue  
{  
    public:  
        queue();  
        bool empty();  
        void enqueue(int x);  
        int dequeue();  
        int peek();  
  
        node *front, *rear;  
};  
  
queue::queue()  
{  
    front = nullptr;  
    rear = nullptr;  
}  
bool queue::empty()  
{  
    return front == nullptr;  
}  
void queue::enqueue(int x)  
{  
    node *p = new node;  
    p->info = x;  
    p->next = nullptr;  
    if(front == nullptr)  
    {  
        front = p;  
    }  
    else  
    {  
        rear->next = p;  
    }  
    rear = p;  
}  
int queue::dequeue()  
{  
    node *p = front;  
    int result = front->info;  
    if(front == rear)  
    {  
        rear = nullptr;  
    }  
    front = front->next;  
    delete p;  
    return result;  
}  
int queue::peek()  
{  
    if(front != nullptr)  
    {  
        return front->info;  
    }  
}  
  
int main()  
{  
    int n, cnt1 = 0, cnt2 = 0;  
    queue q1;  
    queue q2;  
    char c = ' ';  
  
    scanf("%d", &n);  
  
    while(c != '\n')  
    {  
        c = getchar();  
        if(n > 0)  
        {  
            q1.enqueue(n);  
            cnt1++;  
        }  
        else  
        {  
            q2.enqueue(n);  
            cnt2++;  
        }  
        scanf("%d", &n);  
  
    }  
    if(cnt1 != cnt2)  
    {  
        printf("%s\n", "no");  
        return 0;  
    }  
    for(int i = 0; i < cnt1; i++)  
    {  
        if(q1.peek() == (-1) * q2.peek())  
        {  
            q1.dequeue();  
            q2.dequeue();  
        }  
        else  
        {  
            printf("%s\n", "no");  
            return 0;  
        }  
    }  
    printf("%s\n", "yes");  
}  
