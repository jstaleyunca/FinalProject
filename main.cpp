/* 
 * File:   main.cpp
 * Author: John
 *
 * Created on April 20, 2015, 5:06 PM
 */

#include <cstdlib>
#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;

/*
 * Project Euler problem 44
 */

// returns pentagonal number of provided number
double pentagonalNumber(double i) {
    return (i*((3.0*i)-1))/2.0;
}

// determines if provided number is pentagonal or not
bool isPentagonal(double i) {
    // formula for determining if pentagonal number
    // fmod used for modulo operations with doubles
    if(fmod(((sqrt((24.0*i)+1.0)+1.0)/6.0),1.0) == 0.0) {
        return true;
    } else {
        return false;
    }
}

int main(int argc, char** argv) {
    // for each pentagonal number
    for(double i = 2.0; i < 2500; i++) { 
        // and each number below that one
        for(double j = i - 1.0; j >= 1.0; j--) { 
            // find the sum
            double x = pentagonalNumber(i) + pentagonalNumber(j); 
            // find the difference
            double y = pentagonalNumber(i) - pentagonalNumber(j); 
            // if there is a value in which both the sum and difference are also pentagonal
            if(isPentagonal(x) == true && isPentagonal(y) == true) { 
                double d = abs(y);
                // display it
                cout << d << endl; 
                break;
            }
        }
    }
}