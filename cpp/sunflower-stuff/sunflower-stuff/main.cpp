//
//  main.cpp
//  sample
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
int * returnTopTwo(int arr[4], int top[2]);
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
    int topTwo[4];
    returnTopTwo(averages, topTwo);
    cout << "Highest indices: " << topTwo[0] << " " << topTwo[1] << endl;
    cout << "Highest values: " << topTwo[2] << " " << topTwo[3] << endl;
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
int* returnTopTwo(int arr[4], int top[4]) {
    int tempHighest = 2;
    int tempSecond = 1;
    // Reference for array top[4] :
    // top[0]: Index of highest average
    // top[1]: Index of second highest average
    // top[2]: Value of highest average
    // top[3]: Value of second highest average
    for (int i = 0; i < 4; i++) {
        if (arr[i] >= tempSecond) {
            tempSecond = arr[i];
            top[1] = i;
            top[3] = tempSecond;
        }
        if (arr[i] >= tempHighest) {
            tempSecond = tempHighest;
            top[1] = top[0];
            top[3] = tempHighest;
            tempHighest = arr[i];
            top[0] = i;
            top[2] = arr[i];
        }
    }
    return top;
}

