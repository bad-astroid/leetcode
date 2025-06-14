/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *     public List<String> GetUrls(String url) {}
 * }
 */
using System.Threading.Tasks;
using System.Collections.Concurrent;
class Solution {
    ConcurrentDictionary<string, byte> visited;
    string rootHost;
    List<string> result;
    private void dfsAsync(string currentUrl, HtmlParser htmlParser) {
        if(!visited.TryAdd(currentUrl, 0)) {
            return;
        }
        result.Add(currentUrl);
        var tasks = new List<Task>();
        foreach(var nextUrl in htmlParser.GetUrls(currentUrl)) {
            if(rootHost != (new Uri(nextUrl).Host)) {
                continue;
            }
            tasks.Add(Task.Factory.StartNew(() => dfsAsync(nextUrl, htmlParser)));
        }
        Task.WaitAll(tasks.ToArray());
    }
    public IList<string> Crawl(string startUrl, HtmlParser htmlParser) {
        rootHost = (new Uri(startUrl)).Host;
        result = new List<string>();
        visited = new ConcurrentDictionary<string, byte>();
        dfsAsync(startUrl, htmlParser);
        return result;
    }
}