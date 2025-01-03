#include <iostream>
using namespace std;

void printOutArray(int** array, int rows, int cols, int x1, int y1) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (array[i][j] == -1) {
                if(i == x1 && j == y1) {
                    cout << "[ _ ] ";
                }
                else {
                    cout << "[] ";
                }
            } else {
                cout << array[i][j] << " ";
            }
        }
        cout << endl;
    }
}

void SumRowsArray(int** array, int rows, int cols) {
    cout << "Eiluciu sumos:" << endl;
    int totalSum = 0;
    for (int i = 0; i < rows; i++) {
        int rowSum = 0;
        for (int j = 0; j < cols; j++) {
            rowSum += array[i][j];
        }
        cout << "Eilute nr. " << i+1 << ": " << rowSum << endl;
        totalSum += rowSum;
    }
    cout<<"Bendra eiluciu suma: "<<totalSum<<endl;
}

void SumColsArray(int** array, int rows, int cols) {
    cout<<"Stulpeliu sumos: "<<endl;
    int totalSum = 0;
    for (int j = 0; j < cols; j++) {
        int colSum = 0;
        for (int i = 0; i < rows; i++) {
            colSum += array[i][j];
        }
        cout << "Stulpelio nr. " << j+1 << ": " << colSum << endl;
        totalSum += colSum;
    }
    cout<<"Bendra stulpeliu suma: "<<totalSum<<endl;
}

void MaxArrayNumber(int **array, int rows, int cols) {
    int maxNumber = array[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (array[i][j] > maxNumber) {
                maxNumber = array[i][j];
            }
        }
    }
    cout<<"Didziausias skaicius yra: "<<maxNumber<<endl;
}

int main() {
    int rows, cols;
    cout<<"Iveskit eil ir stul sk: "<<endl;
    cin >> rows >> cols;

    // sukurimas dynamic array
    int** array = new int*[rows];
    for (int i = 0; i < rows; i++) {
        array[i] = new int[cols];
    }

    // -1 == nera priskirtos reiksmes
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            array[i][j] = -1;
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int temp;
            printOutArray(array, rows, cols, i, j);
            cout<<"Iveskite elemento reiksme: ";
            cin>>temp;
            array[i][j] = temp;
            cout<<endl;
        }
    }

    printOutArray(array, rows, cols, -1, -1);
    int choice = 1;
    while (choice != 5) {
        cout<<"1. Spauzdint lentele"<<endl;
        cout<<"2. Apskaiciuoti kiekvienos eil suma"<<endl;
        cout<<"3. Apskaiciuoti kiekvieno stul suma"<<endl;
        cout<<"4. Rasti didziausia reiksme lenteleje"<<endl;
        cout<<"5. Iseiti"<<endl;
        cout<<"pasirinkite opcija: "<<endl;
        cin>>choice;
        switch(choice) {
            case 1: {
                printOutArray(array, rows, cols, -1, -1);
                break;
            }
            case 2: {
                SumRowsArray(array, rows, cols);
                break;
            }
            case 3: {
                SumColsArray(array, rows, cols);
                break;
            }
            case 4: {
                MaxArrayNumber(array, rows, cols);
                break;
            }
        }
    }

    return 0;
}
