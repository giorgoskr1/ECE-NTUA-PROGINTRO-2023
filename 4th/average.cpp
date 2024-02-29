#include <cstdio>  
  
using namespace std;  
  
float arr[100][100];  
  
float mo_line(int line, int M)  
{  
  int k;  
  float sum = 0;  
  for(k = 0; k < M; k++)  
  {  
    sum += arr[line][k];  
  }  
  return sum/float(M);  
}  
  
float mo_column(int column, int N)  
{  
  int h;  
  float sum = 0;  
  for(h = 0; h < N; h++)  
  {  
    sum += arr[h][column];  
  }  
  return sum/float(N);  
}  
  
int main()  
{  
  int N, M, i, j;  
  float tmp, suml = 0, sumc = 0;  
  char c;  
  
  scanf("%d %d", &N, &M);  
  
  float lines[N], columns[M];  
  for(i = 0; i < N; i++)  
  {  
    scanf("%c", &c);  
    for(j = 0; j < M; j++)  
    {  
      scanf("%f", &tmp);  
      arr[i][j] = tmp;  
    }  
  }  
  for(i = 0; i < N; i++)  
  {  
    lines[i] = mo_line(i, M);  
    suml += lines[i];  
  }  
  for(j = 0; j < M; j++)  
  {  
    columns[j] = mo_column(j, N);  
    sumc += columns[j];  
  }  
  printf("%.3f\n", suml / float(N));  
  printf("%.3f\n", sumc / float(M));  
  
}  
