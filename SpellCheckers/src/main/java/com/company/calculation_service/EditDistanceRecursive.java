package com.company.calculation_service;

import java.util.Arrays;

public class EditDistanceRecursive {

    public static int calculate(String x, String y) {
        if (x.isEmpty()) {
            return y.length();
        }

        if (y.isEmpty()) {
            return x.length();
        }

        int oneOne = calculate(x.substring(1), y.substring(1))
                + costOfSubstitution(x.charAt(0), y.charAt(0));
        int oneTwo = calculate(x, y.substring(1)) + 1;
        int twoOne = calculate(x.substring(1), y) + 1;

        return min(oneOne, oneTwo, twoOne);
    }

    public static int costOfSubstitution(char a, char b) {
        return a == b ? 0 : 1;
    }

    public static int min(int... numbers) {
        return Arrays.stream(numbers)
                .min().orElse(Integer.MAX_VALUE);
    }
}