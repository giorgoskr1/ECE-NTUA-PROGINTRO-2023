#include <iostream>  
#include <cstdio>  
#include <string>  
#include <list>  
  
using namespace std;  
  
int main()  
{  
  list<string> line;  
  char c;  
  string tmp_str;  
  bool first = true;  
  
  c = getchar();  
  while(true)  
  {  
    if(c == '\n' or c == EOF)  
    {  
      //tmp_str.push_back(' ');  
      line.push_front(tmp_str);  
      for(auto it = line.begin(); it != line.end(); it++)  
      {  
        if(it == line.begin() and not tmp_str.empty() and not first) cout << *it << ' ';  
        else cout << *it;  
      }  
      if(c == EOF)  
      {  
        return 0;  
      }  
      cout << '\n';  
      line.clear();  
      tmp_str.clear();  
      first = true;  
    }  
    else if(c == ' ' and not tmp_str.empty())  
    {  
      if(not first) tmp_str.push_back(c);  
      line.push_front(tmp_str);  
      tmp_str.clear();  
      first = false;  
    }  
    else if(c != ' ')  
    {  
      tmp_str.push_back(c);  
    }  
  
    c = getchar();  
  }  
}  
