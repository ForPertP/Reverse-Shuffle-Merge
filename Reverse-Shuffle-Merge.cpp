#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'reverseShuffleMerge' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string reverseShuffleMerge(string s)
{
    int n = s.size();

    vector<char> sarr(s.rbegin(), s.rend());
    int alpha_size = 26;
    vector<int> freq(alpha_size, 0);

    for (int i = 0; i < n; ++i)
    {
        freq[sarr[i] - 'a']++;
    }

    vector<int> did_use(alpha_size, 0);
    vector<int> can_use(freq.begin(), freq.end());
    vector<char> A;

    for (int i = 0; i < n; i++)
    {
        if (did_use[sarr[i] - 'a'] < freq[sarr[i] - 'a'] / 2)
        {
            while (A.size() > 0 && sarr[i] < A.back() &&
                did_use[A.back() - 'a'] + can_use[A.back() - 'a'] - 1 >= freq[A.back() - 'a'] / 2)
            {
                did_use[A.back() - 'a']--;
                A.pop_back();
            }

            A.push_back(sarr[i]);
            did_use[sarr[i] - 'a']++;
            can_use[sarr[i] - 'a']--;
        }
        else
        {
            can_use[sarr[i] - 'a']--;
        }
    }

    return string(A.begin(), A.end());
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = reverseShuffleMerge(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

