#include <cstdio>  
#include <iostream>  
#include <string.h>  
  
using namespace std;  
  
int main ()  
{  
  int words = 0, l = 0, ratio = 0, j = 0, i = 0, r = 0, spaces = 0, mspaces = 0, extra = 0;  
  char line[61], word[21];  
  
  
  scanf ("%s", word);  
  while (word[i] != '\0')  
  {  
    line[i] = word[i];  
    i++;  
  }  
  words = 1;  
  
  while (scanf ("%s", word) != EOF)  
  {  
    l = strlen (word);  
    if (i + l < 60)  
    {  
      line[i] = ' ';  
      i++;  
      words++;  
      j = 0;  
      while (word[j] != '\0')  
      {  
        line[i] = word[j];  
        i++;  
        j++;  
      }  
    }  
    else {  
      extra = 60 - i;  
      spaces = words - 1;  
      ratio = extra / spaces;  
      mspaces = extra % spaces;  
      extra -= mspaces;  
      for (j = 0; j < i; j++)  
      {  
        r = ratio;  
        if (line[j] == ' ')  
        {  
          do  
          {  
            cout << ' ';  
          }while(r-- > 0);  
        if (mspaces >= words - 1) cout << ' ';  
        words--;  
        }  
        else cout << line[j];  
      }  
      cout << '\n';  
  
      i = 0;  
      j = 0;  
      words = 1;  
      ratio   = 1;  
  
  
  
      while (word[j] != '\0')  
      {  
        line[i] = word[j];  
        i++;  
        j++;  
      }  
  
    }  
  
  }  
  
  for (j = 0; j < i; j++)  
  {  
    cout << line[j];  
  }  
  
  cout << '\n';  
}  
