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