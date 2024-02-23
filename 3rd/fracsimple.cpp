#include <cstdio>  
  
using namespace std;  
  
int find_mkd(int a, int b)  
{  
  if (a == 0)  
  {  
    return b;  
  }  
  return(find_mkd(b % a, a));  
}  
  
int main()  
{  
  int N, n1, n2, m1, m2, mkd = 0, i = 0, r1, r2;  
  char prajh, c;  
  
  scanf("%d", &N);  
  
  for(i = 0; i < N; i++)  
  {  
    scanf("%c", &c);  
    scanf("%c %d %d %d %d", &prajh, &n1, &n2, &m1, &m2);  
    if(prajh == '+')  
    {  
      r1 = n1*m2 + n2*m1;  
      r2 = m2*n2;  
    }  
    else if (prajh == '-')  
    {  
      r1 = n1*m2 - n2*m1;  
      r2 = m2*n2;  
    }  
    else if(prajh == '*')  
    {  
      r1 = n1*m1;  
      r2 = n2*m2;  
    }  
    else if(prajh == '/')  
    {  
      r1 = n1*m2;  
      r2 = n2*m1;  
    }  
  
    if(r1 < r2)  
    {  
      mkd = find_mkd(r1, r2);  
    }  
    else  
    {  
      mkd = find_mkd(r2, r1);  
    }  
  
    if(r1 == 0)  
    {  
      printf("%d %d\n", r1, r1 + 1);  
    }  
    else  
    {  
      printf("%d %d\n", r1/mkd, r2/mkd);  
    }  
  }  
}  
