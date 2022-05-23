package com.company.calculation_service;

import com.company.Main;

import java.util.HashMap;
import java.util.List;

public class BinarySearch {
    private static int binarySearch(String[] arr, String x) {
        int l = 0, r = arr.length - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;

            int res = x.compareTo(arr[m]);

            // Check if x is present at mid
            if (res == 0)

                return m;

            // If x greater, ignore left half
            if (res > 0)
                l = m + 1;

                // If x is smaller, ignore right half
            else
                r = m - 1;
        }

        return -1;
    }


    public static HashMap<String, Integer> getPossibleStrings(List<String> strings, String query) {
        HashMap<String, Integer> result = new HashMap<>();
        for (String s: strings) {
            if (s.startsWith(query))
                result.put(s, EditDistanceRecursive.calculate(query, Main.getUserInput()));
        }
        return result;
    }




}
