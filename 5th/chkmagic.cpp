#include <iostream>  
#include <cstdio>  
  
using namespace std;  
  
int main()  
{  
  int N, i, j, tmp, seires, seira, diagwnios1 = 0, diagwnios2 = 0, place;  
  
  scanf("%d", &N);  
  
  bool numbers[150*150] = {false}, end = false;  
  int columns[150] = {0}, table[150][150];  
  
  for(i = 0; i < N; i++)  
  {  
    for(j = 0; j < N; j++)  
    {  
      scanf("%d", &tmp);  
      table[i][j] = tmp;  
    }  
  }  
  
  for(i=0; i < N; i++)  
  {  
    seira = 0;  
    for(j=0; j < N; j++)  
    {  
      tmp = table[i][j];  
      if(tmp >= N*N or numbers[tmp])  
      {  
        end = true;  
        break;  
      }  
      numbers[tmp] = true;  
      columns[j] += tmp;  
      seira += tmp;  
      place = N*i + j;  
      if(i==j) diagwnios1 += tmp;  
      if(i+j == N-1) diagwnios2 += tmp;  
  
      if(seires != 0 and (columns[j] > seires or diagwnios1 > seires or diagwnios2 > seires))  
      {  
        end = true;  
        break;  
      }  
    }  
    if(seires==0) seires = seira;  
    else if(seira != seires or end)  
    {  
      end = true;  
      break;  
    }  
  }  
  
  if(diagwnios1 != seires or diagwnios2 != seires) end = true;  
  
  if(not end)  
  {  
    for(i = 0; i < N; i++)  
    {  
      if(columns[i] != seires)  
      {  
        end = true;  
        break;  
      }  
    }  
  }  
  
  if(end==false) printf("%s\n", "yes");  
  else if(end == true) printf("%s\n", "no");  
}  
