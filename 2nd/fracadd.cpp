#include <cstdio>  
  
using namespace std;  
  
int main()  
{  
  int n1, n2, m1, m2, i=0, ekp = 0, r1, r2, maximum;  
  scanf("%d %d", &n1, &n2);  
  scanf("%d %d", &m1, &m2);  
  
  if(n2<m2)  
  {  
    maximum = m2;  
  }  
  else if(n2>m2)  
  {  
    maximum = n2;  
  }  
  else  
  {  
    ekp = n2;  
  }  
  if(ekp == 0)  
  {  
    for(i = maximum; i <= n2*m2; i = i+maximum)  
    {  
      if(i%n2 == 0 and i%m2 == 0)  
      {  
        ekp = i;  
        break;  
      }  
    }  
  }  
  i = ekp;  
  r2 = ekp;  
  r1 = (i/n2)*n1 + (i/m2)*m1;  
  printf("%d %d", r1, r2);   
}  
