package com.company;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;


//int represents binary data
public class RightSensor {
    private final int FREQUENCY_OF_READING; //limits the input to 10 digits (0 based) (reads 9 char at once)
    private final ArrayList<ArrayList<Integer>> arrayLeftSensorData;

    public RightSensor(int FREQUENCY_OF_READING) {
        this.FREQUENCY_OF_READING = FREQUENCY_OF_READING;
        arrayLeftSensorData = new ArrayList<>();
        readingWritingFromFile();
    }

    private void readingWritingFromFile() {
//        BOI, COMPLEX LOGIC IS OUT HERE
        try {
            BufferedReader in = new BufferedReader(new FileReader("rightSensor.txt"));

            String tempLine = in.readLine();
            int amountOfDigits = tempLine.length();


            int globalVarForAllDigits = 0;
            boolean after1stFrequency = false;
            for (int i = 0; i < (amountOfDigits / FREQUENCY_OF_READING); i++) {
                ArrayList<Integer> tempArrayList = new ArrayList<>();

                while (globalVarForAllDigits < amountOfDigits) {
                    if (globalVarForAllDigits % FREQUENCY_OF_READING == 0 && globalVarForAllDigits != 0) { //because 0 % 9 = 0
                        arrayLeftSensorData.add(tempArrayList);
                        globalVarForAllDigits++;
                        after1stFrequency = true;
                        break;
                    }
                    if (after1stFrequency) { //otherwise, it will skip a digit
                        globalVarForAllDigits--;
                        after1stFrequency = false;
                    }
                    int tempDigit = Character.getNumericValue(tempLine.charAt(globalVarForAllDigits));
                    tempArrayList.add(tempDigit);
                    globalVarForAllDigits++;
                }

            }
        } catch (FileNotFoundException fileNotFoundException) {
            System.out.println("couldn't find the file");

        } catch (IOException e) {
            e.printStackTrace();
        }

    }


    public ArrayList<ArrayList<Integer>> getArraySensorData() {
        return arrayLeftSensorData;
    }
}

/*

    public int getLeftSensorBinaryData() {
        return leftSensorBinaryData;
    }
 */


/*
    private int readsFile() {
        try {
            BufferedReader in = new BufferedReader(new FileReader("leftSensor.txt"));
            return Integer.parseInt(in.readLine());
        } catch (IOException e) {
            e.printStackTrace();
        }
        return 0;
    }*/