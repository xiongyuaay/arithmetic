#include <iostream>
#include <string>
#include <vector>
#include <regex>
using namespace std;

bool check(string title, vector<string> &matchs, bool &s, bool &e)
{
    string start = title.substr(0, matchs[0].length());
    if (start != matchs[0] && s)
    {
        return false;
    }
    string end = title.substr(title.length() - matchs[matchs.size()-1].length());
    if (end != matchs[matchs.size()-1] && e)
    {
        return false;
    }
    if (s && e)
    {
        title = title.substr(matchs[0].length(), title.length() - matchs[matchs.size()-1].length());
    }
    else if (s)
    {
        title = title.substr(matchs[0].length());
    }
    else if (e)
    {
        title = title.substr(0, title.length() - matchs[matchs.size()-1].length());
    }
    
    

    int num = e ? matchs.size() - 1:matchs.size();
    for (int i = 1; i < num; i++)
    {
        int it = title.find(matchs[i]);
        if (it == string::npos)
        {
            return false;
        }
        title = title.substr(it + matchs[i].length());
        
    }
    return true;
    
}

std::string solution(int n, std::string template_,
                     std::vector<std::string> titles) {
  // Please write your code here
  regex pattern("\\{([^{}]*)\\}");
  smatch match;
  string remaining = template_;
  vector<string> matchs;
  bool s = true;
  bool e = true;

  int prev_pos = 0;

  while (regex_search(remaining, match, pattern))
  {
    size_t match_start = match.position();
    size_t match_end = match_start + match.length();

    matchs.push_back(remaining.substr(0, match_start));
    remaining = remaining.substr(match_end);
  }
  if (!remaining.empty())
  {
    matchs.push_back(remaining);
  }
  else
  {
    e = false;
  }
  if (matchs[0] == "")
  {
    s = false;
  }
  
  

  string res = "";
  for (int i = 0; i < n; i++)
  {
    if (check(titles[i], matchs, s, e))
    {
        res = res + "True,";
    }
    else
    {
        res = res + "False,";
    }
  }
  
  res.erase(res.end() - 1);
  
  

  return res;
}

int main() {
  //  You can add more test cases here
  std::vector<std::string> testTitles1 = {"adcdcefdfeffe", "adcdcefdfeff",
                                          "dcdcefdfeffe", "adcdcfe"};
  std::vector<std::string> testTitles2 = {
      "CLSomGhcQNvFuzENTAMLCqxBdj", "CLSomNvFuXTASzENTAMLCqxBdj",
      "CLSomFuXTASzExBdj",          "CLSoQNvFuMLCqxBdj",
      "SovFuXTASzENTAMLCq",         "mGhcQNvFuXTASzENTAMLCqx"};
  std::vector<std::string> testTitles3 = {"abcdefg", "abefg", "efg"};

  std::cout << (solution(5, "{abc}xyz{def}", {"xyzdef","abcdef","abxyzdef","xyz","abxyz"}) ==
                "True,False,False,True")
            << std::endl;

  std::cout << (solution(4, "ad{xyz}cdc{y}f{x}e", testTitles1) ==
                "True,False,False,True")
            << std::endl;
  std::cout << (solution(6, "{xxx}h{cQ}N{vF}u{XTA}S{NTA}MLCq{yyy}",
                         testTitles2) == "False,False,False,False,False,True")
            << std::endl;
  std::cout << (solution(3, "a{bdc}efg", testTitles3) == "True,True,False")
            << std::endl;

  return 0;
}