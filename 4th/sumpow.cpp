#include <cstdio>  
#include <cmath>  
  
using namespace std;  
  
int main()  
{  
  int N, num, sum, p[10], a, b, c, d, e, f, g, h, i;  
  
  scanf("%d", &N);  
  
  for(i=0;i<=9;i++)  
  {  
    p[i] = pow(i,N);  
  }  
  for(a=0;a<=9;a++)  
  {  
    for(b=0;b<=9;b++)  
    {  
      for(c=0;c<=9;c++)  
      {  
        for(d=0;d<=9;d++)  
        {  
          for(e=0;e<=9;e++)  
          {  
            for(f=0;f<=9;f++)  
            {  
              for(g=0;g<=9;g++)  
              {  
                for(h=0;h<=9;h++)  
                {  
                  num = a*10000000 + b*1000000 + c*100000 + d*10000 + e*1000 + f*100 + g*10 +h;  
                  sum = p[a] + p[b] + p[c] + p[d] + p[e] + p[f] + p[g] + p[h];  
                  if(num==sum) printf("%d\n", num);  
                }  
              }  
            }  
          }  
        }  
      }  
    }  
  }  
}  
