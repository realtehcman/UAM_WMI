package com.company;

import java.util.Scanner;

public class Main {
    static boolean isGraphCyclic;
    static boolean oneTimeCheckCyclic = true;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numberOfArrays = sc.nextInt();

        //for arrays
        for (int a = 0; a < numberOfArrays; a++) {
            //initializing the elements in the array
            int numberOfNodes = sc.nextInt();
            numberOfNodes += 1;
            int[] nodes = new int[numberOfNodes];
            boolean[] occupiedRooms = new boolean[numberOfNodes];


            for (int i = 1; i < numberOfNodes; i++) {
                nodes[i] = sc.nextInt();
            }
            //for iterations; as many as elements in the array
            for (int x = 1; x < numberOfNodes; x++) {
                //for comparing first element
                for (int i = 1; i < numberOfNodes; i++) {
                    //for comparing other elements with the first element
                    for (int j = 1; j < numberOfNodes; j++) {
                        if (nodes[i] == j) {
                            occupiedRooms[i] = false;
                            occupiedRooms[nodes[i]] = true;
                            break;
                        }
                    }
                }

                //check if only last node is false (cyclic) based on the property
                //property:
                //IF IT'S A CYCLIC GRAPH, LAST AND FIRST BOOLEAN ARRAY ELEMENTS ARE FALSE,
                //EVERYTHING ELSE IS TRUE
                if (oneTimeCheckCyclic) {
                    isGraphCyclic = checkIfCyclic(numberOfNodes, occupiedRooms);
                    if (isGraphCyclic) {
                        break;
                    }
                }
                for (int y = 1; y < occupiedRooms.length; y++) {
                    if (!occupiedRooms[y]) {
                        nodes[y] = 0;
                    }
                }
            }
            if (!isGraphCyclic) {
                printResult(occupiedRooms);
            }
            isGraphCyclic = false;
            oneTimeCheckCyclic = true;

        }
    }

    private static boolean checkIfCyclic(int numberOfNodes, boolean[] occupiedRooms) {
        int c = 1;
        while (c < numberOfNodes) {
            if ((!occupiedRooms[c]) && (c != (numberOfNodes - 1))) {
                break;
            }
            if ((c == (numberOfNodes - 1)) && (!occupiedRooms[numberOfNodes - 1])) {
                isGraphCyclic = true;
                System.out.println(5);
                return true;
            }
            c++;
        }
        oneTimeCheckCyclic = false;
        return false;
    }

    private static void printResult(boolean[] occupiedRooms) {
        occupiedRooms[0] = false;
//        System.out.println("----");
        int i = 0;
        for (boolean room : occupiedRooms) {
            if (room) {
                i++;
            }
        }
        System.out.println(i);
    }
}

//if false travels back to 1st position, graph is cyclic