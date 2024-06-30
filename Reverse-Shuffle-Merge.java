import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

class Result {

    /*
     * Complete the 'reverseShuffleMerge' function below.
     *
     * The function is expected to return a STRING.
     * The function accepts STRING s as parameter.
     */

    public static String reverseShuffleMerge(String s) {
        int n = s.length();
        int alphabetCount = 26;
        char[] rs = new StringBuilder(s).reverse().toString().toCharArray();
        int[] frequency = new int[alphabetCount];

        for (char c : rs) {
            frequency[c - 'a']++;
        }

        int[] needed = new int[alphabetCount];
        int[] used = new int[alphabetCount];

        for (int i = 0; i < alphabetCount; ++i) {
            needed[i] = frequency[i] / 2;
        }

        StringBuilder result = new StringBuilder();

        for (char c : rs) {
            int index = c - 'a';

            if (used[index] < needed[index]) {
                while (result.length() > 0 && c < result.charAt(result.length() - 1) &&
                       used[result.charAt(result.length() - 1) - 'a'] + frequency[result.charAt(result.length() - 1) - 'a']
                       > needed[result.charAt(result.length() - 1) - 'a']) {
                    used[result.charAt(result.length() - 1) - 'a']--;
                    result.deleteCharAt(result.length() - 1);
                }

                result.append(c);
                used[index]++;
            }

            frequency[index]--;
        }

        return result.toString();
    }

}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String s = bufferedReader.readLine();

        String result = Result.reverseShuffleMerge(s);

        bufferedWriter.write(result);
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
