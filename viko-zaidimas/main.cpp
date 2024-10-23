#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

bool isBalse() {
    char b[6] = {'a', 'e', 'i', 'y', 'o', 'u'};
    cout << "Iveskite balse :" << endl;
    char a;
    cin >> a;
    for (int i = 0; i < 6; i++) {
        if (a == b[i]) {
            return true;
        }
    }
    return false;
}

int didDalyklis(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void StartGame() {
    srand(time(0));

    int randomNumber = rand() % 100 + 1;

    bool answered = false;
    while (answered == false) {
        int number;
        cout<<"Spekite skaiciu: "<<endl;
        cin>>number;
        if (number == randomNumber) {
            cout<<"Atspejote skaiciu! Skaicius buvo: "<<randomNumber<<endl;
            answered = true;
        }
        else if(number > randomNumber) {
            cout<<"Jusu skaicius didesnis uz random skaiciu"<<endl;
        }
        else {
            cout<<"Jusu skaicius mazesnis uz random skaiciu"<<endl;
        }
    }
}

void FizzBuzz(int n) {
    for(int i = 1;i <= n;i++) {
        if(i % 3 == 0 && i % 5 == 0) {
            cout<<"FizzBuzz"<<endl;
        }
        else if(i % 3 == 0) {
            cout<<"Fizz"<<endl;
        }
        else if(i % 5 == 0) {
            cout<<"Buzz"<<endl;
        }
    }
}
int main() {
    int n = 0;
    while (n != 5) { // Corrected condition to ensure loop runs
        cout << "1. Balses tikrinimas" << endl;
        cout << "2. Dvieju skaitmenu didziausias dalyklis" << endl;
        cout << "3. Random skaiciaus zaidimas" << endl;
        cout << "4." << endl;
        cout << "5. isejimas" << endl;
        cout << "Pasirinkite viena is siu funkciju:" << endl;
        cin >> n;

        switch (n) {
            case 5:
                cout << "Programa baigia darba." << endl;
            break;
            default:
                cout << "Pasirinkimas neteisingas, bandykite dar kartą." << endl;
        }
    }
    return 0;
}
