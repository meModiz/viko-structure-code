#include <iostream>
#include <cstdlib>

using namespace std;

// 1 uzd
void printMyName(string name, string reason) {
    cout<<"Mano vardas: " <<name<<endl;
    cout<<"Pasirinkau studijas, nes: "<<reason<<endl;
}

void collageName(string name) {
    cout<<"Mano kolegijos pavadinimas: "<<name<<endl;
}

void facultetName(string name) {
    cout<<"Mano fakulteto pavadinimas: "<<name<<endl;
}

void printRandomNumber() {
    cout<<rand()<<endl;
}

void twoDigitSum(int digit1, int digit2) {
    cout<<digit1+digit2<<endl;
}

void twoDigitDifference(int digit1, int digit2) {
    cout<<digit1-digit2<<endl;
}

void twoDigitMultip(int digit1, int digit2) {
    cout<<digit1*digit2<<endl;
}

void twoDigitDiv(int digit1, int digit2) {
    cout<<digit1/digit2<<endl;
}

void whoIsBigger(int digit1, int digit2) {
    if(digit1>digit2) {
        cout<<"Skaičius: "<<digit1<<" Didesnis!"<<endl;
    }
    else if(digit2>digit1) {
        cout<<"Skaičius: "<<digit2<<" Didesnis!"<<endl;
    }
    else {
        cout<<"Skaičiai yra lygus O.o"<<endl;
    }
}


int main() {
    // 1 uzd
    printMyName("Antanas", "Šiaip sau");
    printMyName("Petras", "Šiaip sau");
    // 2 uzd
    collageName("Vilniaus kolegija");
    facultetName("Elektronikos ir informatikos fakultetas");

    // 3 uzd
    for(int i = 0; i < 10; i++) {
        printRandomNumber();
    }

    // 4 uzd
    int digit1, digit2;
    cin>>digit1>>digit2;
    twoDigitSum(digit1,digit2);
    twoDigitDifference(digit1,digit2);
    twoDigitMultip(digit1,digit2);
    twoDigitDiv(digit1,digit2);
    //
    whoIsBigger(5,10);
    whoIsBigger(30,1);
    whoIsBigger(-10,-10);
    return 0;
}
