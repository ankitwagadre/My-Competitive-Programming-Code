int Solution::wordBreak(string A, vector<string> &B) {
    int n = A.size();
    bool possible[n];
    memset(possible, false, sizeof(possible));

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
                    break;
                }
            }
        }
    }

    return possible[n-1];
}
