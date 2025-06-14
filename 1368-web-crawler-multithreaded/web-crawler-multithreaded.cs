using System.Threading.Tasks;

class Solution {
    public IList<string> Crawl(string startUrl, HtmlParser htmlParser) {
        HashSet<string> visited = new HashSet<string> { startUrl };
        string host = (new Uri(startUrl)).Host;
        void Process(string url) {
            Task[] tasks = htmlParser.GetUrls(url).Where(x => (new Uri(x)).Host == host).Select(x =>
                Task.Factory.StartNew(() => {
                    string str = (string)x;
                    lock(visited) {
                        if(visited.Contains(str)) {
                            return;
                        }
                        visited.Add(str);
                    } 
                    Process(str);
                })).ToArray();
            Task.WaitAll(tasks);
        }
        Process(startUrl);
        return visited.ToList();
    }
}