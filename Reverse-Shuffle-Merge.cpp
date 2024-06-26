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
    int alphabetCount = 26;
    std::string rs(s.rbegin(), s.rend());
    std::vector<int> frequency (alphabetCount, 0);

    for (char c : rs)
    {
        frequency [c - 'a']++;
    }

    std::vector<int> needed(alphabetCount, 0);
    std::vector<int> used(alphabetCount, 0);

    for (int i = 0; i < alphabetCount; ++i)
    {
        needed[i] = frequency [i] / 2;
    }

    std::string result;

    for (char c : rs)
    {
        int index = c - 'a';

        if (used[index] < needed[index])
        {
            while (!result.empty() && c < result.back() &&
                   used[result.back() - 'a'] + frequency[result.back() - 'a']
                   > needed[result.back() - 'a'])
            {
                used[result.back() - 'a']--;
                result.pop_back();
            }

            result.push_back(c);
            used[index]++;
        }

        frequency[index]--;
    }

    return result;
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
