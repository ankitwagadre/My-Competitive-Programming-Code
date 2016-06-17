vector<string> Solution::wordBreak(string A, vector<string> &B) {

    int n = A.size();
    bool possible[n];
    memset(possible, false, sizeof(possible));

    vector<string> ans[n];
    for(int i = 0; i < n; i++)
    {
        for (int j = i; j >= 0; j--)
        {
            if (j == 0 || possible[j-1])
            {
                string word = A.substr(j, i - j +1);
                bool found = false;
                for (vector<string>::iterator it = B.begin(); it != B.end(); ++it)
                {
                    if (word == *it)
                    {
                        found = true;
                        break;
                    }
                }

                if (found)
                {
                    possible[i] = true;
                    if (j == 0)
                    {
                        ans[i].push_back(word);
                    }
                    else
                    {
                        for(vector<string>::iterator it = ans[j-1].begin(); it != ans[j-1].end(); ++it)
                        {
                            string c = (*it);
                            c = c.append(" ");
                            c = c.append(word);
                            ans[i].push_back(c);
                        }
                    }
                }
            }
        }
    }

    sort(ans[n-1].begin(), ans[n-1].end());

    return ans[n-1];


}
