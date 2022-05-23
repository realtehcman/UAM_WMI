package com.company;

/*
* Gear rotation detector
Instructions
TLDR

There are two distance meters near a gear.
Design and implement an algorithm for detecting if the gear is rotating.

Some assumptions (simplification)

You will never miss an edge.
The sensors always return just two states (low or high). They don't malfunction.
Your algorithm always returns the rotation of the gear (clockwise or counter clockwise)
*  or indicates that the gear is not rotating. (Your algorithm is always able to make that decision).
To be submitted

*/
public class Main {


    public static void main(String[] args) {
//        debbugingLeftSensor();
//        debbugingRightSensor();
        GearRotationParser data = new GearRotationParser();
        data.getFinalSumUp().forEach(System.out::println);
    }


    private static void debbugingRightSensor() {
        RightSensor rightSensor = new RightSensor(2);
        System.out.println(rightSensor.getArraySensorData().size());

        for (int i = 0; i < rightSensor.getArraySensorData().size(); i++) {
            System.out.println(i + 1 + " iteration of the outer array");
            for (int i2 = 0; i2 < 9; i2++) {
                int temp = rightSensor.getArraySensorData().get(i).get(i2);
                System.out.println(i + 1 + " outer array with digit: " + temp);
            }
        }

    }


    private static void debbugingLeftSensor() {
        LeftSensor leftSensor = new LeftSensor(2);
        System.out.println(leftSensor.getArraySensorData().size());

        for (int i = 0; i < leftSensor.getArraySensorData().size(); i++) {
            System.out.println(i + 1 + " iteration of the outer array");
            for (int i2 = 0; i2 < 9; i2++) {
                int temp = leftSensor.getArraySensorData().get(i).get(i2);
                System.out.println(i + 1 + " outer array with digit: " + temp);
            }
        }
    }

    private static void debuggingNestedLoops() {
        for (int i1 = 0; i1 < 20; i1++) {
            System.out.println("outer loop " + i1);
            for (int i2 = 0; i2 < 4; i2++)
                System.out.println("innner loop " + i2);
        }

    }
}
