package cse2010.homework4;

/*
 * CSE2010 Homework #4
 * Problem 1: Palindrome
 *
 * Complete the code below.
 *
 */

public class Palindrome {

    public static boolean isPalindrome(String target) {

        return isPalindrome(target, 0, target.length() - 1);
    }

    private static boolean isPalindrome(String as, int start, int end) {

        // your code goes here ...

        return false;
    }

    private static boolean isAlpha(final char ch) {
        if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
            return true;
        else
            return false;
    }

    private static int toLower(char c) {
        if ((c >= 'A') && (c <= 'Z'))
            return c + ('a' - 'A');
        return c;
    }

}
