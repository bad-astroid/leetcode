/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */

class Solution {
public:
    unordered_map<string, bool> visited;
    string findHostName(string url) {
        string ret = "";
        for(int i = 7; i < url.size(); ++i) {
            if(url[i] == '/') break;
            ret += url[i];
        }
        return ret;
    }
    void dfs(string url, string hostName, vector<string>& ret, HtmlParser& htmlParser) {
        if(visited[url]) return;
        if(findHostName(url) != hostName) return;
        visited[url] = true;
        ret.push_back(url);
        for(auto nextUrl : htmlParser.getUrls(url)) {
            dfs(nextUrl, hostName, ret, htmlParser);
        }
    }
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        vector<string> ret;
        // cout << findHostName(startUrl) << endl;
        dfs(startUrl, findHostName(startUrl), ret, htmlParser);
        return ret;
    }
};