#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;
class Solution {
   public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        string alph = "qwertyuiopasdfghjklzxcvbnm";
        map<string, bool> wordMap;
        for (int i = 0; i < wordList.size(); i++) {
            wordMap[wordList[i]] = true;
        }

        if (wordMap.find(endWord) == wordMap.end()) {
            return 0;
        }
		int minDepth = 0;
        int depth = 1;
        if (beginWord == endWord) {
            return depth;
        }
        map<string, int> visitedWords;
        queue<string> wordQueue;
        visitedWords[endWord] = depth;
        wordQueue.push(endWord);
        while (depth <= wordList.size() + 1) {
			if(wordQueue.size () == 0) {
				break;
			}
            string currWord = wordQueue.front();
            wordQueue.pop();
            depth = visitedWords[currWord] + 1;
            for (int i = 0; i < currWord.length(); i++) {
                for (int j = 0; j < 26; j++) {
                    string lower = currWord.substr(0, i);
                    string upper =
                        i < currWord.length() - 1
                            ? currWord.substr(i + 1, currWord.length() - i - 1)
                            : "";
                    string newWord = lower + alph.substr(j, 1) + upper;
                    if (newWord == beginWord) {
                        return depth;
                    }
                    if (wordMap.find(newWord) != wordMap.end()) {
                        if (visitedWords.find(newWord) == visitedWords.end()) {
                            visitedWords[newWord] = depth;
                            wordQueue.emplace(newWord);
                        }
                    }
                }
            }
        }
        return minDepth;
    }
};

// int main() {
//     Solution sol;
//     vector<string> l = {"hot", "dog"};
//     cout << sol.ladderLength("hot", "dog", l) << endl;
// }