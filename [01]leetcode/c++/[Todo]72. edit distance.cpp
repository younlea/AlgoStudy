class Solution {
public:
    int minDistance(string word1, string word2) {
        int ret = 0;
        string firstWord = word1;
        string secondWord = word2;
        //check length and charactor's count
        
        int firstWordHash[26] = {0,};
        int secondWordHash[26] = {0,};
        
        for(int i = 0; i < word1.size(); i++)
            firstWordHash[word1[i]-'a']++;
        for(int i = 0; i < word2.size(); i++)
            secondWordHash[word2[i]-'a']++;
        
        
        return ret;
        //make same length
            // add or remove using charactor' count
        //replace charactor
        
    }
};