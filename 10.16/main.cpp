#include <iostream>

using namespace std;

int main() {
    /*int n[6];
    for (int i = 0; i < 5; i++) {
        cin>>n[i];
    }
    int totalArraySum = 0;
    int bigArrayNum = n[0];
    int smallArrayNum = n[0];
    for (int i = 0; i < 5; i++) {
        if (n[i] > bigArrayNum) {
            bigArrayNum = n[i];
        }
        if (n[i] < smallArrayNum) {
            smallArrayNum = n[i];
        }
        totalArraySum += n[i];
    }
    cout<<totalArraySum<<endl;
    cout<<bigArrayNum<<endl;
    cout<<smallArrayNum<<endl;*/

    int stud[41];
    int repeatablePoints[11] = {0};
    // { 0, 0 , 0 , 0, 0, 0, 0, 0, 0 }
    for(int i =0; i < 40; i++) {
        cin >> stud[i];
    }
    for(int i = 1; i <= 10; i++) {
        for(int j = 0; j < 40; j++) {
            if(stud[j] == i) {
                repeatablePoints[i]++;
            }
        }
    }

    for(int i = 1; i <= 10; i++) {
        cout<<i<<": "<<repeatablePoints[i]<<"balsai."<<endl;
    }

    return 0;
}
