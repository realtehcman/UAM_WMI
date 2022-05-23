package com.company;

import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;

public class ReadFastaFile {

    private static ArrayList<String> sequenceNames = new ArrayList<>();
    private static int amountOfDnas = 0;

    public static void main(String[] args) throws FileNotFoundException {

        boolean first = true;

        try (Scanner sc = new Scanner(new File("J:\\Downloads\\dna_test.txt"))) {
            while (sc.hasNextLine()) {
                String line = sc.nextLine().trim();
                if (line.charAt(0) == '>') {
                    if (first)
                        first = false;
                    else
                        System.out.println();

                    System.out.println(line.substring(1));
                } else {
                    sequenceNames.add(line);
                    System.out.println("The sequence name is");
                    System.out.println(sequenceNames.get(amountOfDnas));
                    System.out.println("Its length is " + sequenceNames.get(amountOfDnas).length());

                    amountOfDnas++;
                }
            }
        }
        System.out.println();
    }
}