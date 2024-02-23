#include <cstdio>  
#include <stdlib.h>  
  
using namespace std;  
  
int find_mkd(int a, int b)  
{  
  if(a==0)  
  {  
    return b;  
  }  
  return(find_mkd(b%a, a));  
}  
  
int main()  
{  
  int N, n1, n2, m1, m2, mkd = 0, i = 0, r1, r2, t1, t2, tmp;  
  char prajh, c;  
  bool negative;  
  
  scanf("%d", &N);  
  
  for(i = 0; i < N; i++)  
  {  
    scanf("%c", &c);  
    scanf("%c %d %d %d %d", &prajh, &n1, &n2, &m1, &m2);  
    negative = false;  
  
    // elegxos paronomastwn  
    if(n2 == 0 or m2 == 0)  
    {  
      printf("%s\n", "error");  
      continue;  
    }  
  
    //prajeis  
    if(prajh == '+')  
    {  
      r1 = n1*m2 + n2*m1;  
      r2 = n2*m2;  
    }  
    else if(prajh == '-')  
    {  
      r1 = n1*m2 - n2*m1;  
      r2 = n2*m2;  
    }  
    else if(prajh == '*')  
    {  
      r1 = n1*m1;  
      r2 = n2*m2;  
    }  
    else if(prajh == '/')  
    {  
      if(m1 == 0)  
      {  
        printf("%s\n", "error");  
        continue;  
      }  
      r1 = n1*m2;  
      r2 = n2*m1;  
    }  
  
    //elegxos proshmou  
    if((r1 < 0 and r2 > 0) or (r1 > 0 and r2 <0))  
    {  
      negative = true;  
    }  
  
    //mkd  
    if(abs(r1) < abs(r2))  
    {  
      mkd = find_mkd(abs(r1), abs(r2));  
    }  
    else  
    {  
      mkd = find_mkd(abs(r2), abs(r1));  
    }  
  
    t1 = abs(r1)/abs(mkd);  
    t2 = abs(r2)/abs(mkd);  
  
    //periptwseis  
    if(t1 == 0 and negative)  
    {  
      printf("%c", '-');  
      printf("%d %d %d\n", 0, 0, 1);  
    }  
    else if(t1 == 0 and not negative)  
    {  
      printf("%d %d %d\n", 0, 0, 1);  
    }  
    else  
    {  
      if(negative and t1/t2 == 0)  
      {    
         printf("-%d %d %d\n", t1/t2, t1%t2, t2);  
      }  
      else if(negative and t1/t2 != 0)  
      {  
        printf("%d %d %d\n", -t1/t2, t1%t2, t2);  
      }  
      else  
      {  
        printf("%d %d %d\n", t1/t2, t1%t2, t2);  
      }  
    }  
  }  
}  
