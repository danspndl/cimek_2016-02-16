//
//  main.cpp
//  cimek
//
//  Created by sdaniel on 15/02/16.
//  Copyright © 2016 Daniel Spindelbauer. All rights reserved.
//


// 1. Olvassa be az ip.txt állományban talált adatokat, s annak felhasználásával oldja meg a következő feladatokat!
// 2. Határozza meg és írja a képernyőre, hogy hány adatsor van az állományban!
// 3. Írja a képernyőre az állományban található legalacsonyabb IP-címet! A megoldásában felhasználhatja, hogy a betűk ASCII-kódjai a számok ASCII-kódjai után találhatók a kódtáblában.
// 4. Határozza meg, hogy az állományban hány darab IP-cím van az egyes fajtákból! Az eredményt jelenítse meg a képernyőn a mintának megfelelően!
// 5. Gyűjtse ki a sok.txt állományba azokat az IP-címeket, melyek legalább 18 nullát tartalmaznak! A fájlban minden sor elején szerepeljen az eredeti állományból a cím sorszáma! Ezt kövesse egy szóközzel elválasztva a cím az ip.txt állományban szereplő alakjával!
// 6. Kérjen be a felhasználótól egy sorszámot! Az állományban a megadott sorszámon található IP-címet rövidítse a csoportokon belüli bevezető nullák elhagyásával! Az állományban található alakot és a rövidített változatot írja a képernyőre egymás alá!
// 7. Az előző feladatban használt IP-címet rövidítse tovább az egymást követő nullás csoportok rövidítésére vonatkozó szabályoknak megfelelően! Az eredményt jelenítse meg a képernyőn! Amennyiben nem rövidíthető, írja ki: „Nem rövidíthető tovább.”!



#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

ifstream fileInput("ip.txt");
string ip[500];
int ipSize = sizeof(ip)/sizeof(ip[0]);

string slicedIp[8]; // Initiating array for the parts of the string     // First appears in t6()


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
    ipSize=sum;
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

    // 2001:0db8*; dokumentacios
    // 2001:0e*; globalis
    // fc*, fd*; helyi

    int dokumentacios=0, globalis=0, helyi=0;
    string dokumentaciosCond="2001:0db8";
    string globalisCond="2001:0e";
    string helyiCond1="fc";
    string helyiCond2="fd";

    string temp="";


    // dokumentacios
    for (int c=0; c<ipSize; c++) {
        // Iterate through 'ip' array and check the temp value with the condition
        temp=ip[c].substr(0,9);
        // cout<<"temp "<<temp<<endl;
        if(temp==dokumentaciosCond){
            dokumentacios++;
        }
    }


    // globalis
    for (int c=0; c<ipSize; c++) {
        // Iterate through 'ip' array and check the temp value with the condition
        temp=ip[c].substr(0,7);
        // cout<<"temp "<<temp<<endl;
        if(temp==globalisCond){
            globalis++;
        }
    }

    // helyi
    for (int c=0; c<ipSize; c++) {
        // Iterate through 'ip' array and check the temp value with the condition
        temp=ip[c].substr(0,2);
        // cout<<"temp "<<temp<<endl;
        if(temp==helyiCond1 || temp==helyiCond2){
            helyi++;
        }
    }


    cout<<"4. feladat:"<<endl;
    cout<<"Dokumentacios cim: "<<dokumentacios<<" darab"<<endl;
    cout<<"Globalis egyedi cim: "<<globalis<<" darab"<<endl;
    cout<<"Helyi egyedi cim: "<<helyi<<" darab"<<endl;
}

void t5(){
    ofstream fileOutput("sok.txt");
    // Iterate through 'ip' array
    for (int c=0; c<ipSize; c++) {
        int zeros=0; // Initiating 'zero' counter
        string loopTemp=ip[c]; // Get array's current element
        string charTemp=""; // Initiating var for a char

        // Iterate through string
        // A string is 39 characters long
        for (int i=0;i<39;i++){
            charTemp=loopTemp[i]; // charTemp equals to a char
            if(charTemp=="0"){
                zeros++; // Counting zeros in a item
            }
        } // End iterate through string
        
        // If there are more than 18 zeros in the string, print it
        if(zeros>=18){
            fileOutput<<c<<" "<<ip[c];
        }
    } // End iterate through 'ip' array

    cout<<"5. feladat... Kesz."<<endl;
    fileOutput.close();
}

void t6(){
    int inputValue=0;
    
    cout<<"6. feladat"<<endl;
    cout<<"Enter a number: ";
    // cin>>inputValue;                     // DEBUG
    inputValue=9;   // Debug
    
    
    // ====================
    // Work on this condition
    // ====================
//    if (inputValue>0) {
//        inputValue-=1;  // Reduce inputValue by one to get the programming sequence number
//    }
    
    string workingValue=ip[inputValue]; // Assigning the input vlaue tot the 'workingValue' string
//    workingValue="2001:0db8:03cd:0000:0000:ef45:0006:0123";   // Debug
    string tempValue="";
    
    // Get positions of colons in the string
    long int colonPos[7];   // Why does it need long int?
    for (int i=0; i<7; i++) {
        // It finds the first colon and moves onto the next one.
        if (i!=0) {
            colonPos[i]=workingValue.find(":",colonPos[i-1]+1);
        }else{
            colonPos[i]=workingValue.find(":");
        }
    }
    
    // Slice up the string into small strings
    int colonCount=0;    // colon counter
    
    slicedIp[0]=workingValue.substr(0,4);   // I don't know what this is...
    for (int i=1; i<8; i++) {   // Going through the whole string
        slicedIp[i]=workingValue.substr(colonPos[colonCount]+1,4);   // Slicing up the string at the colons
        colonCount++;    // Increasing colon counter
    }
    
    // Iterating through the whole array and checking checking zeros and removing them from the beginning
    for (int i=0; i<8; i++) {
        string tempString=slicedIp[i];  // Initiating the string that it works with
        char tempChar[4]={tempString[0],tempString[1],tempString[2],tempString[3]}; // Making an array from the string's characters
        char cond='0';  // This is the condition aka zero #notetoself: ' means character, " means string
        
        // Checking the zeros
        if (tempChar[0]==cond && tempChar[1]!=cond) {   // Only the first is zero
            slicedIp[i]=slicedIp[i].substr(1,3);
        } else if(tempChar[0]==cond && tempChar[1]==cond && tempChar[2]!=cond){    // First and second is a zero
            slicedIp[i]=slicedIp[i].substr(2,2);
        } else if(tempChar[0]==cond && tempChar[1]==cond && tempChar[2]==cond && tempChar[3]!=cond){  // Only the last one is not a zero
            slicedIp[i]=slicedIp[i].substr(3,1);
        } else if(tempString=="0000"){  // Whole string 0
            slicedIp[i]="0";
        }
    }
    
    
    // Print original
    cout<<workingValue<<endl;
    
    // Print result
    for (int i=0; i<8; i++) {
        if(i!=7){
            cout<<slicedIp[i]<<":";
        } else{
            cout<<slicedIp[i]<<endl;
        }
    }
    
}

void t7(){
    // slicedIp[8] array is available
    string resultString="";
    
    cout<<"Start..."<<endl;
    for (int i=0; i<8; i++) {
        cout<<slicedIp[i]<<":";
    }
    cout<<"End..."<<endl;
    
    
    for (int i=0; i<8; i++) {   // Iterate through 'slicedIp' array
        if (((slicedIp[i]=="0") && (slicedIp[i+1]=="0")) || ((slicedIp[i]=="0") && (slicedIp[i-1]=="0"))) { // If there are 2 zeros next to eachother
            resultString+=":";
        } else if(slicedIp[i]=="0" && slicedIp[i+1]=="0" && slicedIp[i+2]=="0"){    // If there are 3 zeros next to eachother
            resultString+=":";
        }else if(slicedIp[i]!="0" && slicedIp[i+1]=="0" && slicedIp[i+2]=="0"){   // Don't print colon after a string that wasn't zero
            resultString+=slicedIp[i];
        }else if(i==7){ // Last element, don't print colon, just the string
            resultString+=slicedIp[i];
        }else { // When there's no zero next to the element
            resultString+=slicedIp[i];
            resultString+=":";
        }
    }
    
    cout<<"7. feladat"<<endl;
    cout<<resultString<<endl;
    // Print result
//    for (int i=0; i<8; i++) {
//        if(i!=7){
//            cout<<slicedIp[i]<<":";
//        } else{
//            cout<<slicedIp[i]<<endl;
//        }
//    }
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

    // printIP();   // t1
    t2();
    cout<<endl;
    t3();
    cout<<endl;
    t4();
    cout<<endl;
    t5();
    cout<<endl;
    t6();
    cout<<endl;
    t7();

    fileInput.close();
    return 0;
}
