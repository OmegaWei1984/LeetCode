#include <string>
#include <vector>
#include <set>

using namespace std;

class Solution
{
public:
    const vector<string> morse = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

    int uniqueMorseRepresentations(vector<string> &words)
    {
        set<string> morseWords; 
        for (string word : words) {
            string morseWord = "";
            for (char letter : word) {
                morseWord.append(morse[letter - 'a']);
            }
            morseWords.insert(morseWord);
        }
        return morseWords.size();
    }
};

int main(void)
{
    vector<string> words = {"gin", "zen", "gig", "msg"};
    Solution solution;
    int ans = solution.uniqueMorseRepresentations(words);
    return 0;
}