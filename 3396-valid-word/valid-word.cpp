class Solution 
{
public:
    bool isValid(string word) 
    {
        if (word.length() < 3) return false;

        bool hasVowel = false, hasConsonant = false;

        for (int i = 0; i < word.length(); i++)
        {
            char ch = word[i];
            if (!isalnum(ch)) return false;

            if (isalpha(ch)) 
            {
                char c = tolower(ch);
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                {
                    hasVowel = true;
                }    
                else
                {
                    hasConsonant = true;
                }
            }
        }
        return hasVowel && hasConsonant;
    }
};