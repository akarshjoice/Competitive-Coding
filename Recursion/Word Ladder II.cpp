// Question:
/*
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].

 

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
Explanation: There are 2 shortest transformation sequences:
"hit" -> "hot" -> "dot" -> "dog" -> "cog"
"hit" -> "hot" -> "lot" -> "log" -> "cog"
Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: []
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
 

Constraints:

1 <= beginWord.length <= 5
endWord.length == beginWord.length
1 <= wordList.length <= 1000
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the words in wordList are unique.
*/

//Code:
#include <iostream>
#include <vector>

using namespace std;
int findMatch(string a, string b) {
  int count =0;
  for(int i=0;i<a.size();i++) {
    if(a[i] != b[i]) {
      count++;
    }
  }
  if(count == 1) {
    return 1;
  }
  return 0;
}
int min(int a, int b) {
  return (a<b)?a:b;
}

vector<vector<string>> res;
int minval2 = 1000;
int findLadders(string start, string end, vector<string> wordlist, vector<string> currlist) {
	if(currlist.size() > minval2) {
    return 0;
  }

  if(start == end) {
    res.push_back(currlist);
    minval2 = min(minval2, currlist.size());
    return 0;
  }

	for(int i=0;i<wordlist.size();i++) {
    if(findMatch(start,wordlist[i]) == 1) {
      vector<string> tmp1 = wordlist;
      vector<string> tmp2 = currlist;
      tmp1.erase(tmp1.begin()+i,tmp1.begin()+i+1);
      tmp2.push_back(wordlist[i]);
      findLadders(wordlist[i], end, tmp1, tmp2);
    }
  }
  return 0;
}




int main() {
  int minval = 1000;
  string beginWord = "hit", endWord = "cog";
  vector<string> wordList{"hot","dot","dog","lot","log","cog"};
  vector<string> currlist;
  currlist.push_back(beginWord);
  findLadders(beginWord, endWord, wordList, currlist);
  for(int i=0;i<res.size();i++) {
    minval = min(minval,res[i].size());
  }
  for(int i=0;i<res.size();i++) {
    if(res[i].size() == minval) {
      for(int j=0;j<res[i].size();j++) {
        cout<<res[i][j]<<"->";
      }
      cout<<endl;
    }
  }
  return 0;
}
