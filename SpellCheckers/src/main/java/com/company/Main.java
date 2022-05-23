package com.company;

import com.company.entities.DictionaryAlphaWords;

import java.util.Scanner;

/*
* Task
* word x consists an error, word 2 should be chosen from the dictionary based on the minimum distance
* */
public class Main {
    private static String userInput;

    public static void main(String[] args) {
        System.out.println("Please enter a word:");
        Scanner sc = new Scanner(System.in);
        userInput = sc.nextLine().toLowerCase();

        DictionaryAlphaWords dict = new DictionaryAlphaWords();

        System.out.println(dict.sendMsgToUser());

    }

    public static String getUserInput() {
        return userInput;
    }
}
