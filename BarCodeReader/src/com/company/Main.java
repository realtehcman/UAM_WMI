package com.company;

/*B - BLACK BAR
 * W - WHITE BAR*/


public class Main {

    public static void main(String[] args) {
        String inputSample = "w";
        initState(inputSample);

    }

    static void initState(String inputSample) {
        switch (inputSample) {
            case "w":
                System.out.println("_");
                secondState(inputSample);
                break;
            case "b":
                System.out.println("_");
                initState(inputSample);
        }
    }

    static void secondState(String inputSample) {
        switch (inputSample){
            case "w":
                System.out.println("_");
                secondState(inputSample);
            case"b":
                System.out.println("_");
                thirdState(inputSample);
        }
    }

    static void thirdState(String inputSample){}
}
