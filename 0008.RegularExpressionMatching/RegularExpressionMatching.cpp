class Solution {
public:
    bool isMatch(string s, string p) {        
        return dfs(0, 0, s, p);
    }
    
    bool dfs (int i, int j, string s, string p) {
        
        if (cache.count(make_pair(i, j)))
            return cache[make_pair(i, j)];
        
        if (i >= s.length() && j >= p.length())
            return true;
        
        if (j >= p.length())
            return false;
        
        bool match = (i < s.length()) && (s.compare(i, 1, p, j, 1) == 0 || p.compare(j, 1, ".") == 0);
        
        if ((j + 1) < p.length() && p.compare(j + 1, 1, "*") == 0) {
            cache[make_pair(i , j)] = dfs(i, j + 2, s, p) ||       // don't use *
                (match && dfs(i + 1, j, s, p)); // use *
            return cache[make_pair(i , j)];
        }
            
                
        if (match)
            cache[make_pair(i , j)] = dfs(i + 1, j + 1, s, p);
            return cache[make_pair(i , j)];
                
        return false;
    }
    
    std::map<std::pair<int, int>, bool> cache;

};

