#include <iostream>

using namespace std;

int main()
{
    // 1;2 užduotis
    int a,b,c,d; // studento pazymiai
    int s_vidurkis = 0; // studento vidurkis
    cin>>a>>b>>c>>d;
    s_vidurkis = (a+b+c+d)/4;
    if(s_vidurkis >= 5) {
        cout<<"Vidurkis teigiamas";
    }
    else if(s_vidurkis <= 5) {
        cout<<"Vidurkis neigiamas";
    }


    // 3 užduotis
    /*
    int egzamino_pazymys; // egzamino pazymys
    cin>>egzamino_pazymys;
    if(egzamino_pazymys > 10)
        cout<<"Neįmanona";
    else if(egzamino_pazymys == 10)
        cout<<"Puiku";
    else if(egzamino_pazymys == 9 )
        cout<<"Labai gerai";
    else if(egzamino_pazymys >= 7)
        cout<<"gerai";
    else if(egzamino_pazymys >= 5)
        cout<<"patenkinamai";
    else if(egzamino_pazymys < 5)
        cout<<"egzaminas neišlaikytas";
    */

    // 4 užduotis
    /*int egzamino_pazymys;
    cin>>egzamino_pazymys;

    switch(egzamino_pazymys) {
        case 10:
            cout<<"Puiku";
            break;
        case 9:
            cout<<"Labai gerai";
            break;
        case 7:
        case 8:
            cout<<"gerai";
            break;
        case 6:
        case 5:
            cout<<"patenkinamai";
            break;
        case 4:
        case 3:
        case 2:
        case 1:
            cout<<"egzaminas neišlaikytas";
            break;
        default:
            cout<<"Klaida";
            break;
    }*/

    // 5 užduotis
    /*int total = 0;
    for(int i = 1; i<=20; i++) {
        if(!(i%2==0)) {
            total += 1;
        }
    }
    cout << total;*/

    // 6 uzduotis
    double indelis = 1000;
    for(int i = 0; i<10; i++) {
        indelis = 105*indelis/100;
    }
    cout<<indelis;

    /*  7 uzduotis
    for(int i = 1; i<=20; i++) {
        if(i % 4 == 0)
            cout<<i<<endl;
    }*/





    return 0;
}
