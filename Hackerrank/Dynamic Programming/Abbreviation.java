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
     * Complete the 'abbreviation' function below.
     *
     * The function is expected to return a STRING.
     * The function accepts following parameters:
     *  1. STRING a
     *  2. STRING b
     */

    public static String abbreviation(String a, String b) {
        // Write your code here
        int N = a.length(), M = b.length(), i = 0, j = 0;
        if (M > N) return "NO";
        while (i < N && j < M) {
            char B = b.charAt(j);
            if (B == Character.toUpperCase(a.charAt(i))) {
                i++;
                j++;
            } else {
                if (abbreviation(a.substring(i + 1), b.substring(j)) == "YES") return "YES";
                while (i < N && Character.toUpperCase(a.charAt(i)) != B) {
                    if (Character.isUpperCase(a.charAt(i++))) return "NO";
                }
            }  
        }
        if (j == M) {
            while (i < N) {
                if (Character.isUpperCase(a.charAt(i++))) return "NO";
            }
            return "YES";
        }
        else return "NO";
    }

}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int q = Integer.parseInt(bufferedReader.readLine().trim());

        IntStream.range(0, q).forEach(qItr -> {
            try {
                String a = bufferedReader.readLine();

                String b = bufferedReader.readLine();

                String result = Result.abbreviation(a, b);

                bufferedWriter.write(result);
                bufferedWriter.newLine();
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        });

        bufferedReader.close();
        bufferedWriter.close();
    }
}
