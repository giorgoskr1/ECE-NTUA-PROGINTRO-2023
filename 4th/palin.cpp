#include <cstdio>  
#include "pzhelp"  
  
using namespace std;  
  
int main()  
{  
  char symboloseira[20], tmp, c = ' ';  
  int N, i, index = 0, low, mid, up, cnt = 0;  
  bool ok, er;  
  
  scanf("%d", &N);  
  scanf("%c", &tmp);  
  
  for(i = 0; i < N; i++)  
  {  
    ok = true;  
    index = 0;  
    scanf("%c", &c);  
    while(c!= '\n')  
    {  
      symboloseira[index] = c;  
      index++;  
      scanf("%c", &c);  
    }  
    if(index>20)  
    {  
      printf("%s\n", "error");  
      continue;  
    }  
    if(index==0)  
    {  
      printf("%s\n", "empty");  
      continue;  
    }  
    if(index%2==0)  
    {  
      mid = index/2 - 1;  
      low = mid;  
      up = mid + 1;  
    }  
    else  
    {  
      mid = index/2;  
      low = mid - 1;  
      up = mid + 1;  
    }  
    while(low >= 0 and up < index)  
    {  
      if(symboloseira[low] != symboloseira[up])  
      {  
        ok = false;  
        break;  
      }  
      low--;  
      up++;  
    }  
    if(not ok) printf("%s\n", "no");  
    else  
    {  
      printf("%s\n", "yes");  
      cnt++;  
    }  
  }  
  printf("%.3f\n", (float(cnt)/float(N)*100));  
}  
