    #include <iostream>
    #include <fstream>
#include <iomanip> // For std::setw
    using namespace std;

    struct item {
        string itemLabel;
        double itemPrice;
    };

    struct orderItem {
        string itemLabel;
        double itemPrice;
        int count = 0;
    };

    void getData(item restaurantItems[], int &MenuSize, orderItem orderedItems[]) {
        restaurantItems[0] = {"Kiausiniene", 1.45};
        restaurantItems[1] = {"Kiaulienos sonine su keptu kiausiniu", 2.45};
        restaurantItems[2] = {"Keksiukas su vysnia", 0.99};
        restaurantItems[3] = {"Prancuziskas skrebutis", 1.99};
        restaurantItems[4] = {"Vaisiu salotos", 2.49};
        restaurantItems[5] = {"Pusryciu dribsniai", 0.69};
        restaurantItems[6] = {"Kava", 0.50};
        restaurantItems[7] = {"Arbata", 0.75};

        orderedItems[0] = {"Kiausiniene", 1.45, 0};
        orderedItems[1] = {"Kiaulienos sonine su keptu kiausiniu", 2.45, 0};
        orderedItems[2] = {"Keksiukas su vysnia", 0.99, 0};
        orderedItems[3] = {"Prancuziskas skrebutis", 1.99, 0};
        orderedItems[4] = {"Vaisiu salotos", 2.49, 0};
        orderedItems[5] = {"Pusryciu dribsniai", 0.69, 0};
        orderedItems[6] = {"Kava", 0.50, 0};
        orderedItems[7] = {"Arbata", 0.75, 0};
        MenuSize = 8;
    }

    void showData(item restaurantItems[], int MenuSize) {
        for (int i = 0; i < MenuSize; i++) {
            cout <<"nr. "<<i<<" "<<left<<setw(40)<<restaurantItems[i].itemLabel <<" "<<left<<setw(10)<< restaurantItems[i].itemPrice << " eur" <<endl;
        }
    }

    void makeReceipt(orderItem orderedItems[], int MenuSize) {
        ofstream fout("cekis.txt");
        double totalSum = 0.0;
        for(int i = 0; i < MenuSize; i++) {
            if(orderedItems[i].count > 0) {
                fout <<"nr. "<<i<<" "<<left<<setw(40)<<orderedItems[i].itemLabel <<setw(10)<<" "<< orderedItems[i].itemPrice <<" eur. | Kiekis: "<<orderedItems[i].count<<" x"<< " | Suma uz patiekala: "<<orderedItems[i].count*orderedItems[i].itemPrice<<endl;
                totalSum += orderedItems[i].count*orderedItems[i].itemPrice;
            }
        }
        fout<<"Mokesciai: "<<fixed<<setprecision(2)<<21*totalSum/100<<" eur."<<endl;
        fout<<"Galutine mokejimo suma: "<<fixed<<setprecision(2)<<totalSum+(21*totalSum/100)<<" eur."<<endl;
        fout.close();
    }


    int main() {
        item restaurantItems[100];
        orderItem orderedItems[100];
        int MenuSize = 0;
        ofstream fout("cekis.txt");
        fout.close();
        int opcija = 1;
        getData(restaurantItems, MenuSize, orderedItems);
        while(opcija == 1 or opcija == 2 or opcija == 3 or opcija == 4) {
            cout<<"1. Uzsakyti patiekalus "<<endl;
            cout<<"2. Perzvelgti meniu "<<endl;
            cout<<"3. Perzvelgti uzsakyta maista "<<endl;
            cout<<"4. Spauzdint ceki "<<endl;
            cout<<"Pasirinkite opcijas: "<<endl;
            cin>>opcija;
            switch(opcija) {
                case 1: {
                    cout<<"Irasykite patiekalo numeri: "<<endl;
                    cout<<"Norint iseiti irasyktie -1"<<endl;
                    int patiekaloOpcija = 1;
                    while(patiekaloOpcija != -1 and patiekaloOpcija <= (MenuSize-1)) {
                        cin>>patiekaloOpcija;
                        if(patiekaloOpcija != -1 and patiekaloOpcija <= (MenuSize-1)) {
                            orderedItems[patiekaloOpcija].count++;
                            cout<<"Prisidejote i uzsakyma: "<<orderedItems[patiekaloOpcija].itemLabel<<" "<<orderedItems[patiekaloOpcija].itemPrice<<" eur."<<endl;
                            cout<<"Irasykite patiekalo nr arba -1 ,kad iseit"<<endl;
                        }
                    }
                    break;
                }
                case 2: {
                    showData(restaurantItems, MenuSize);
                    break;
                }
                case 3: {
                    for(int i = 0; i < MenuSize; i++) {
                        if(orderedItems[i].count > 0) {
                            cout <<"nr. "<<i<<" "<<left<<setw(40)<<orderedItems[i].itemLabel <<" "<< left << setw(10)<<orderedItems[i].itemPrice <<" eur. | Kiekis: "<<orderedItems[i].count<<" x"<< endl;
                        }
                    }
                    break;
                }
                case 4: {
                    makeReceipt(orderedItems, MenuSize);
                    break;
                }
                default: {
                    break;
                }
            }
        }

        return 0;
    }
