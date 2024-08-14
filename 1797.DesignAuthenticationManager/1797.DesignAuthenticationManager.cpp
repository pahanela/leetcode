class AuthenticationManager {
public:
    AuthenticationManager(int timeToLive) {
        this->ttl = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        pair <string, int> token (tokenId, currentTime + this->ttl);
        this->tokens.push_back(token);
    }
    
    void renew(string tokenId, int currentTime) {
        for (auto & [first, second] : this->tokens) {
            if (first == tokenId && second > currentTime) {
                second = currentTime + this->ttl;
                break;
            }
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        int count = 0;
        for (const auto & [first, second] : this->tokens) {
            if (second > currentTime)
                count++;
        }
        return count;
    }

private:
    int ttl;
    vector<pair<string, int>> tokens;
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */

