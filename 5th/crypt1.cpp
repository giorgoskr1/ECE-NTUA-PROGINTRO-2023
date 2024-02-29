#include <iostream>  
#include <cstdio>  
#include <map>  
#include <string>  
  
using namespace std;  
  
int main()  
{  
    map<char, char> encryption;  
    char c, en;  
    int cnt1 = 65, cnt2 = 97, prev = 0;  
    bool arr[26] = {false};  
  
    scanf("%c", &c);  
    while(c != '\n')  
    {  
        if(int(c) < 97 or int(c) > 122)  
        {  
            printf("%s\n", "error");  
            return 0;  
        }  
        if(arr[int(c) - 97] == true)  
        {  
            printf("%s\n", "error");  
            return 0;  
        }  
        arr[int(c) - 97] = true;  
        encryption[char(cnt1)] = char(toupper(c));  
        encryption[char(cnt2)] = c;  
        cnt1++;  
        cnt2++;  
        scanf("%c", &c);  
    }  
    if(cnt1 != 91 and cnt2 != 123)  
    {  
        printf("%s\n", "error");  
        return 0;  
    }  
    c = getchar();  
    while(c != EOF)  
    {  
        if(int(c) < 65 or int(c) > 122 or (int(c) > 90 and int(c) < 97))  
        {  
            printf("%c", c);  
        }  
        else  
        {  
            en = encryption[c];  
            printf("%c", en);  
        }  
        prev = int(c);  
        c = getchar();  
    }  
}  
