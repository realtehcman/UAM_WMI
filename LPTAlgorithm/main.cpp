/*LPT algorithm; Maksym Dmyterko*/

#include <iterator>
#include <iostream>

using namespace std;

void printArray(int arr[], int size);

void rvereseArray(int arr[], int start, int end);

int main() {
    printf("Assumptions:\n");
    printf("1. There're 2 machines\n"
           "2. A user may define up to 200 jobs\n"
           "3. A user input amount of jobs is divisible by 2\n\n");

    int jobNumber = 0;
    cout << "Dear professor Gawiejnowic,\nPlease enter the number of jobs\n";
    cin >> jobNumber;
    int *savedJobs = new int[jobNumber];
    int i = 0;

    int jobNumberIncreased = 1;
    while (i < jobNumber) {
        cout << "Please enter the process time for job #" << jobNumberIncreased << "\n";
        int tempProcessTime = 0;
        cin >> tempProcessTime;

        savedJobs[i] = tempProcessTime;
        ++i;
        ++jobNumberIncreased;
    }
    printf("Your input for J_1, J_2, J_n... respectively:\n");

    printArray(savedJobs, jobNumber);
    rvereseArray(savedJobs, 0, jobNumber - 1);

    int sumOfProcessTimes = 0;
    int sumOfProcessTimes2 = 0;

    int machine1[100];
    std::fill_n(machine1, 100, 0);
    int machineSize1 = 0;

    int machine2[100];
    std::fill_n(machine2, 100, 0);
    int machineSize2 = 0;

    int tracking1stMachine = 0;
    int tracking2ndMachine = 0;

    bool firstTimeMach1 = true;
    bool firstTimeMach2 = true;
    for (int j = 0; j < jobNumber; j++) {
        if (machine1[tracking1stMachine] < machine2[tracking2ndMachine] ||
            machine1[tracking1stMachine] == machine2[tracking2ndMachine]) {
            sumOfProcessTimes += savedJobs[j];
            tracking1stMachine++;
            if (firstTimeMach1) {
                firstTimeMach1 = false;
                tracking1stMachine--;
            }
            machine1[tracking1stMachine] = sumOfProcessTimes;
            machineSize1++;
        } else {
            sumOfProcessTimes2 += savedJobs[j];
            tracking2ndMachine++;
            if (firstTimeMach2) {
                firstTimeMach2 = false;
                tracking2ndMachine--;
            }
            machine2[tracking2ndMachine] = sumOfProcessTimes2;
            machineSize2++;
        }
    }
    printf("-----------------------------RESULTS------------------------------------\n");
    printf("Machine output shows when a certain job finishes (LPT algorithm applied):\n");
    printf("Machine_1 = ");
    printArray(machine1, ceil(jobNumber / 2));
    printf("\nMachine_2 = ");
    printArray(machine2, ceil(jobNumber / 2));

}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void rvereseArray(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}