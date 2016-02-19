#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Hun");
    fstream be("ip.txt");
    fstream ki("sok.txt");
    string ip[500];
    int i=0;
    int minhely = 0;
    while(!be.eof())
    {
        getline(be,ip[i]);
        i++;
    }
    int hossz = i-1;
    //--
    cout<<"2. feladat:"<<endl;
    cout<<"Az állományban "<<hossz<<" darab adatsor van."<<endl<<endl;
    //--
    cout<<"3. feladat:"<<endl;
    for(i=0; i<hossz; i++)
    {
        if(ip[i] < ip[minhely])
        {
            minhely = i;
        }
    }
    cout<<"A legalacsonyabb tárolt IP cím: "<<endl<<ip[minhely]<<endl<<endl;
    //--
    cout<<"4. feladat:"<<endl;
    int dok=0,glob=0,helyi=0;
    for(i=0; i<hossz; i++)
    {
        if(ip[i].substr(0,9) == "2001:0db8") dok++;
        if(ip[i].substr(0,7) == "2001:0e") glob++;
        if(ip[i].substr(0,2) == "fc" || ip[i].substr(0,2) == "fd") helyi++;
    }
    cout<<"Dokumentációs cím: "<<dok<< " darab"<<endl;
    cout<<"Globális egyedi cím: "<<glob<< " darab"<<endl;
    cout<<"Helyi egyedi cím: "<<helyi<< " darab"<<endl<<endl;
    //--
    int nullak = 0;
    for(i=0; i<hossz; i++)
    {
        for(int j=0;j<50; j++)
        {
            if(ip[i][j] == '0') nullak ++;
        }
        if(nullak >= 18)
        {
            ki<<i+1<<" "<<ip[i]<<endl;;
        }
        nullak = 0;
    }
    //--
    int sorsz;
    cout<<"6. feladat:"<<endl;
    cout<<"Kérek egy sorszámot:";
    cin>>sorsz;
    sorsz--;
    cout<<endl;
    cout<<ip[sorsz]<<endl;
    string ipbont[8][hossz];
    for(i=0; i<hossz; i++)
    {
        ipbont[0][i] = ip[i].substr(0,4);
        ipbont[1][i] = ip[i].substr(5,4);
        ipbont[2][i] = ip[i].substr(10,4);
        ipbont[3][i] = ip[i].substr(15,4);
        ipbont[4][i] = ip[i].substr(20,4);
        ipbont[5][i] = ip[i].substr(25,4);
        ipbont[6][i] = ip[i].substr(30,4);
        ipbont[7][i] = ip[i].substr(35,4);
        for(int j=0; j<8; j++)
        {
            if(ipbont[j][i] == "0000")
                ipbont[j][i] = '0';
        }
    }
    cout<<ipbont[0][sorsz]<<":"<<ipbont[1][sorsz]<<":"<<ipbont[2][sorsz]<<":"<<ipbont[3][sorsz]<<":"<<ipbont[4][sorsz]<<":"<<ipbont[5][sorsz]<<":"<<ipbont[6][sorsz]<<":"<<ipbont[7][sorsz]<<endl<<endl;
    //--
    cout<<"7. feladat:"<<endl;
    string kiir = " ";
    for(i = 0; i< 8; i++)
    {
        if(ipbont[i][sorsz] == "0")
            kiir += ipbont[i][sorsz];
        if(ipbont[i][sorsz] == "0" && ipbont[i][sorsz] == "0")
            kiir+="::";

    }
    cout<<kiir;
    ki.close();
    be.close();
    system("PAUSE");
    return 0;
}
