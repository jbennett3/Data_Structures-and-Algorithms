#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include<utility>
using namespace std;
vector<vector<string>> findAnagrams(const vector<string>& dict);

int main()
{
  vector<string> word_list = {"debitcard", "elvis", "silent", "badcredit", "lives", "freedom","listen", "levis"};
   vector<vector<string>> result = findAnagrams(word_list);
   for (auto anagrams: result) {
      for (auto words: anagrams)
         cout << words << " ";
         cout << endl;
    }
   return 0;
}

vector<vector<string>> findAnagrams(const vector<string>& dict)
{

// Your code here...
vector<vector<string>>anagram;//create vector that stores vector of vector strings
unordered_map<string,vector<string>>sln;// create hashtable
string variable;//temp variable

for(auto w:dict)//create loop that will go through each string and sort them
{//loop will use the sort variables as keys
    variable = w;
sort(w.begin(),w.end());
sln[w].push_back(variable);
}
for(auto vec:sln)//check if any of the strings  are anagrams
{
    anagram.emplace_back(vec.second);
}
return anagram;//return the angaram vector
}
