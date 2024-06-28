using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Collections;
using System.ComponentModel;
using System.Diagnostics.CodeAnalysis;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.Serialization;
using System.Text.RegularExpressions;
using System.Text;
using System;

class Result
{

    /*
     * Complete the 'reverseShuffleMerge' function below.
     *
     * The function is expected to return a STRING.
     * The function accepts STRING s as parameter.
     */

    public static string reverseShuffleMerge(string s)
    {
        int n = s.Length;
        int alphabetCount = 26;
        char[] rs = s.Reverse().ToArray();
        int[] frequency = new int[alphabetCount];

        foreach (char c in rs)
        {
            frequency[c - 'a']++;
        }

        int[] needed = new int[alphabetCount];
        int[] used = new int[alphabetCount];

        for (int i = 0; i < alphabetCount; ++i)
        {
            needed[i] = frequency[i] / 2;
        }

        List<char> result = new List<char>();

        foreach (char c in rs)
        {
            int index = c - 'a';

            if (used[index] < needed[index])
            {
                while (result.Count > 0 && c < result.Last() &&
                       used[result.Last() - 'a'] + frequency[result.Last() - 'a']
                       > needed[result.Last() - 'a'])
                {
                    used[result.Last() - 'a']--;
                    result.RemoveAt(result.Count - 1);
                }

                result.Add(c);
                used[index]++;
            }

            frequency[index]--;
        }

        return new string(result.ToArray());
    }

}

class Solution
{
    public static void Main(string[] args)
    {
        TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

        string s = Console.ReadLine();

        string result = Result.reverseShuffleMerge(s);

        textWriter.WriteLine(result);

        textWriter.Flush();
        textWriter.Close();
    }
}
