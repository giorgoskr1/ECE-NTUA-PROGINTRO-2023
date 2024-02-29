#include <cstdio>  
#include <iostream>  
#include <map>  
  
using namespace std;  
  
int main()  
{  
    int i, j, num, N, cnt = 0, min = 0, max = 0;  
    char c;  
    map<int, bool> m;  
    bool yes = true;  
  
    scanf("%d", &N);  
  
    for(i = 0; i < N; i++)  
    {  
        scanf("%d", &num);  
        m[num] = false;  
    }  
    scanf("%c", &c);  
  
    for(j = 0; j < N; j++)  
    {  
        scanf("%d", &num);  
        if(m.count(num))  
        {  
            m[num] = true;  
            cnt++;  
        }  
        else  
        {  
            yes = false;  
            if (min == 0) min = num;  
            else if (num < min) min = num;  
            if (max == 0) max = num;  
            else if(max < num) max = num;  
        }  
    }  
    for(auto it = m.begin(); it != m.end(); it++)  
    {  
        if(not it->second)  
        {  
            yes = false;  
            if (min == 0) min = it->first;  
            else if (it->first < min) min = it->first;  
            if (max == 0) max = it->first;  
            else if(max < it->first) max = it->first;  
        }  
    }  
    if(yes)  
    {  
        printf("%s\n", "yes");  
    }  
    else  
    {  
        printf("%s %d %d\n", "no", min, max);  
    }  
  
}  
