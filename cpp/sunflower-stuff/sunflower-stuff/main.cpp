//
//  main.cpp
//  sunflower-stuff
//
//  Created by emi on 18/11/17.
//  Copyright © 2017 emi. All rights reserved.
//
#include <cstdlib>
#include <ctime>
#include "../coffee.hpp"
#include <iostream>

using std::cout ;
using std::endl ;
using std::array ;

void generate();
int getAverage(int arr[10]);
int returnHighest(int arr[4]);
int * returnTopThree(int arr[4], int top[6]);
int sensors[4][10];
int averages[4];
int main(int argc, const char * argv[]) {
    
    srand((unsigned)time(0));
    generate();
    for (int i = 0; i < 4; i++) {
        int ave;
        ave = getAverage(sensors[i]);
        averages[i] = ave;
        cout << averages[i] << endl ;
    }
    int topThree[6];
    returnTopThree(averages, topThree);
    // Print the top two (definitely adjacent)
    cout << "Highest indices: " << topThree[0] << " " << topThree[1] << endl;
    cout << "Highest values: " << topThree[3] << " " << topThree[4] << endl;
    // Testing class, not relevant
    Coffee FlatWhite(10);
    FlatWhite.getBeans();
    FlatWhite.printBeans();
    return 0;
}

void generate() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 10; j++) {
            sensors[i][j] = (rand() % 255) + 1;
            cout << "sensors[" << i << "][" << j << "]: ";
            cout << sensors[i][j] << endl;
        }
    }
}
int getAverage(int arr[10]) {
    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += arr[i];
    }
    return sum / 10;
}
int returnHighest(int arr[4]) {
    int tempHighest = 0;
    for (int i = 0; i < 4; i++) {
        if (arr[i] > tempHighest) {
            tempHighest = i;
        }
    }
    return tempHighest;
}
int* returnTopThree(int arr[4], int top[6]) {
    int tempHighest = 3;
    int tempSecond = 2;
    int tempThird = 1;
    // Reference for array top[6] :
    // top[0]: Index of highest average
    // top[1]: Index of second highest average
    // top[2]: Index of third highest average
    // top[3]: Value of highest average
    // top[4]: Value of second highest average
    // top[5]: Value of third highest average
    
    for (int i = 0; i < 4; i++) {
        if (arr[i] >= tempThird) {
            tempThird = arr[i];
            top[2] = i;
            top[5] = arr[i];
        }
        if (arr[i] >= tempSecond) {
            tempThird = tempSecond;
            top[2] = top[1];
            top[5] = tempThird;
            tempSecond = arr[i];
            top[1] = i;
            top[4] = arr[i];
        }
        if (arr[i] >= tempHighest) {
            tempSecond = tempHighest;
            top[1] = top[0];
            top[4] = tempSecond;
            tempHighest = arr[i];
            top[0] = i;
            top[3] = arr[i];
        }
    }
    // Check if top two readings are from adjacent sensors
    // If not adjacent, take the third highest
    if ((top[0] == 0 && top[1] == 2 ) || (top[0] == 1 && top[1] == 3) || (top[0] == 2 && top[1] == 0) || (top[0] == 3 && top[1] == 1)) {
        top[1] = top[2];
    }
    return top;
}

