class Solution {
public:

    struct trieNode{
        int idx;
        trieNode* children[26];
    };

    trieNode* getNode(int i)
    {
        trieNode* temp = new trieNode();
        temp->idx = i;

        for(int j = 0; j < 26; j++)
        {
            temp->children[j] = NULL;
        }
        return temp;
    }

    void insertTrie(trieNode* root, int i, vector<string>& wordsContainer)
    {
        string word = wordsContainer[i];
        int n = word.length();

        for(int j = n-1; j >= 0; j--)
        {
            char ch = word[j];
            int ch_idx = ch - 'a';

            if(root->children[ch_idx] == NULL)
            {
                root->children[ch_idx] = getNode(i);
            }

            root = root->children[ch_idx];

            if(wordsContainer[root->idx].length() > n)
            {
                root->idx = i;
            }
        }
    }

    int searchTrie( trieNode* root, string &word)
    {
        int result_idx = root->idx;
        int n = word.length();

        for(int i = n-1; i>=0; i--)
        {
            int ch_idx = word[i] - 'a';

            root = root->children[ch_idx];
            if(root == NULL)
            {
                return result_idx;
            }

            result_idx = root->idx;
        }

        return result_idx;
    }

    void clearTrie(trieNode* root) {
        if (root == NULL) return;
        for (int i = 0; i < 26; i++) {
            if (root->children[i] != NULL) {
                clearTrie(root->children[i]);
            }
        }
        delete root;
    }

    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        int m = wordsContainer.size();
        int n = wordsQuery.size();

        vector<int> result(n);

        trieNode* root = getNode(0);

        for(int i = 0; i < m; i++)
        {
            int idx = root->idx;
            
            if(wordsContainer[idx].length() > wordsContainer[i].length())
            {
                root->idx = i;
            }
            insertTrie(root, i, wordsContainer);
        }
       
       for(int i = 0; i < n; i++)
       {
            result[i] = searchTrie(root, wordsQuery[i]);
       }

       clearTrie(root);

       return result;
    }
};