package com.company;

import java.util.ArrayList;

/*Final result of the gear state

 * * */

//ERROR IN THIS CLASS!
public class GearRotationParser {
    private LeftSensor leftSensor;
    private RightSensor rightSensor;

    public ArrayList<String> getFinalSumUp() {
        return finalSumUp;
    }

    private static int FREQUENCY_OF_READING = 9;

    private ArrayList<Integer> leftSensorSumUp;
    private ArrayList<Integer> rightSensorSumUp;

    private ArrayList<String> finalSumUp;

    public GearRotationParser() {
        calculatingPerFrequency(9);
    }

    private void calculatingPerFrequency(int FREQUENCY_OF_READING) {
        leftSensor = new LeftSensor(FREQUENCY_OF_READING);
        rightSensor = new RightSensor(FREQUENCY_OF_READING);

        for (int i = 0; i < rightSensor.getArraySensorData().size(); i++) {
            int zeros = 0;
            int ones = 0;
            for (int i2 = 0; i2 < FREQUENCY_OF_READING; i2++) {
                int temp = rightSensor.getArraySensorData().get(i).get(i2);
                switch (temp) {
                    case 0:
                        zeros++;
                        break;
                    case 1:
                        ones++;
                        break;
                }
            }
            if (ones > zeros)
            rightSensorSumUp.add(i, 1);
            if (ones < zeros){
                rightSensorSumUp.add(i, 0);
            }
        }

        for (int i = 0; i < leftSensor.getArraySensorData().size(); i++) {
            int zeros = 0;
            int ones = 0;
            for (int i2 = 0; i2 < FREQUENCY_OF_READING; i2++) {
                int temp = leftSensor.getArraySensorData().get(i).get(i2);
                switch (temp) {
                    case 0:
                        zeros++;
                        break;
                    case 1:
                        ones++;
                        break;
                }
            }
            if (ones > zeros)
                leftSensorSumUp.add(i, 1);
            if (ones < zeros){
                leftSensorSumUp.add(i, 0);
            }
        }

        int floorSize = Math.min(leftSensorSumUp.size(), rightSensorSumUp.size());

        for (int i = 0; i < floorSize; i++){
            int left = leftSensorSumUp.get(i);
            int right = rightSensorSumUp.get(i);
            comparingDataFromtwoSensors(left, right, i);
        }

    }

    private void comparingDataFromtwoSensors(int left, int right, int indexPosition){

        if (left > right){
            this.finalSumUp.add(indexPosition, "<-");
        }
        if (left < right){
            this.finalSumUp.add(indexPosition, "->");
        }

    }

}
