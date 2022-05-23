package com.company.entities;

import com.company.Main;
import com.company.calculation_service.BinarySearch;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import static java.util.Arrays.binarySearch;

//DECOUPLE INTO INNER CLASS!

public class DictionaryAlphaWords {
    private final List<String> dictionary = new ArrayList<>();
    private final HashMap<String, Integer> candidatesForRightWord;

    private int minDistance;


    {
        try (BufferedReader br = new BufferedReader(new FileReader("words_alpha.txt"))) {
            String word;
            while ((word = br.readLine()) != null) {
                dictionary.add(word);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public DictionaryAlphaWords() {
        candidatesForRightWord = BinarySearch.getPossibleStrings(dictionary, Main.getUserInput());
        minDistance = Integer.MAX_VALUE;
    }

    
    public String sendMsgToUser() {
        if (binarySearch(dictionary.toArray(new String[0]), Main.getUserInput()) == 0) {
            return "Spell Checker didn't find an error within the word";
        }


        for (Integer diff : this.candidatesForRightWord.values()) {
            if (diff < minDistance) {
                minDistance = diff;
            }
        }
        StringBuilder str = new StringBuilder("The possible words are ");


        for (Map.Entry<String, Integer> item  : this.candidatesForRightWord.entrySet()) {

            if (item.getValue() == minDistance) {
                str.append(item.getKey()).append(", ");
            }
        }
        return str.toString();
    }

    public List<String> getDictionary() {
        return dictionary;
    }

    public HashMap<String, Integer> getCandidatesForRightWord() {
        return candidatesForRightWord;
    }
}
