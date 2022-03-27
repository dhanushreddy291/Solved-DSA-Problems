import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		int NumberofTestCases, length;
        Scanner sc = new Scanner(System.in);
        NumberofTestCases = sc.nextInt();

        while (NumberofTestCases-- > 0) {
            String Str;
            length = sc.nextInt();
            int one = 0, zero = 0;
            Str = sc.next();
            for (int i = 0; i < length; i++) {
                if (Str.charAt(i) == '0') zero++;
                else one++;
            }
            if (Math.abs(zero - one) < 2) System.out.println(length);
            else System.out.println((2 * Math.min(zero, one) + 1));
        }
	}
}