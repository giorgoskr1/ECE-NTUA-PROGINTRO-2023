#include <cstdio>  
  
using namespace std;  
  
int main()  
{  
  int N, M, i, j, minline, minimum, maximum, tmp;  
  char c;  
  scanf("%d %d", &N, &M);  
  
  int arr[N][M], min[N], max[M];  
  for(j = 0; j < M; j++) max[j] = -1;  
  
  for(i = 0; i < N; i++)  
  {  
    scanf("%c", &c);  
    minline = -1;  
    for(j = 0; j < M; j++)  
    {  
      scanf("%d", &tmp);  
      arr[i][j] = tmp;  
      if(minline==-1)  
      {  
        minline=arr[i][j];  
        min[i] = minline;  
      }  
      else if(minline >  arr[i][j])  
      {  
        minline = arr[i][j];  
        min[i] = minline;  
      }  
  
      if(arr[i][j] > max[j])  
      {  
        max[j] = arr[i][j];  
      }  
    }  
  }  
  minimum = 1000000;  
  for(j = 0; j < M; j++)  
   {  
     if(max[j] < minimum) minimum = max[j];  
   }  
   maximum = min[0];  
    for(i = 1; i < N; i++)  
    {  
      if(min[i] > maximum) maximum = min[i];  
    }  
    printf("%d\n", minimum);  
    printf("%d\n", maximum);  
}  
