//
//  main.cpp
//  cimek
//
//  Created by sdaniel on 15/02/16.
//  Copyright © 2016 Daniel Spindelbauer. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream fileInput("ip.txt");
string ip[500];
int ipSize = sizeof(ip)/sizeof(ip[0]);



void printIP(){
    // Printing 'ip' array
    for (int c=0; c<ipSize; c++) {
        cout<<ip[c]<<endl;
    }
}

void t2(){
    int sum=0;
    for (int i=0; i<ipSize; i++) {
        if (ip[i]!="") {
            sum++;
        }
    }
    
    cout<<"2. feladat: "<<sum<<endl;
}

void t3(){
    int minPos=0;
    for (int i=0; i<ipSize; i++) {
        if (ip[i]<ip[minPos]) {
            minPos=i;
        }
    }
    cout<<"3. Feladat: "<<ip[minPos]<<" and "<<minPos<<endl;
}

void t4(){
    
}

void t5(){
    
}

void t6(){
    
}

void t7(){
    
}

// ========================================
// ========================================
// ========================================

int main() {
    
    // Get input from file
    int i=0;
    while(!fileInput.eof()) {
        getline(fileInput,ip[i]);
        i++;
    }

    // printIP();
    
    t2();
    t3();
    t4();
    t5();
    t6();
    t7();
    
    fileInput.close();
    return 0;
}