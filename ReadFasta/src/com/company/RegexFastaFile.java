package com.company;

import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;

public class RegexFastaFile {

    private static ArrayList<String> sequenceNames = new ArrayList<>();
    private static String line;

    public static void main(String[] args) throws FileNotFoundException {

        boolean first = true;

        try (Scanner sc = new Scanner(new File("J:\\Downloads\\dna_test.txt"))) {
            while (sc.hasNextLine()) {
                line = sc.nextLine().trim();
                if (line.charAt(0) == '>') {
                    if (first)
                        first = false;
                    else
                        System.out.println();

                    System.out.println(line.substring(1));
                } else {
                    String regex = "^[ACTG]+(?:\\\\n[ACTG]+)*$";

                    while ((line = sc.nextLine()) != null){
                        // if is the title line, count as a record
                        if (line.matches(regex))
                            line+=line;
                    }

                    sequenceNames.add(line);
                    System.out.println("The sequence name is");
                    System.out.println(sequenceNames.get(sequenceNames.size()-1));
                    System.out.println("Its length is " + sequenceNames.get(sequenceNames.size()-1).length());

                }
            }
        }
        System.out.println();
    }
}