class Solution {
public:
    string inverse(string word) {
        swap(word[0], word[1]);
        return word;
    }
    int longestPalindrome(vector<string>& words) {
        map<string, int> fr, visited;
        for (auto word : words) {
            fr[word]++;
        }
        int ret = 0;
        bool thereIsMiddle = false;
        for (auto word : words) {
            if(visited[word]) continue;

            visited[word] = 1;
            visited[inverse(word)] = 1;

            if (word[0] == word[1]){
                if (fr[word]&1) {
                    ret += 2 * (fr[word] - 1);
                    if(!thereIsMiddle) {
                        ret += 2;
                        thereIsMiddle = true;
                    }
                    continue;
                }
                ret += 2 * fr[word];
                continue;
            }
            ret += 4 * min(fr[word], fr[inverse(word)]);
        }

        return ret;
    }
};