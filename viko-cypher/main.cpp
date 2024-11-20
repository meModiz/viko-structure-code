#include <iostream>
#include <string.h>
#include <cstring>  // For strlen and memset

using namespace std;

const char Alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

void DecryptionWord(bool isAlphabet, char key[50], char EncryptedWord[50]) {
    int word_len = strlen(EncryptedWord);
    char new_word[50];
    for(int i = 0; i < word_len; i++) {
        // Paiimam po viena raidę iš šifruojamo žodžio ir rakto
        char currentLetter1 = toupper(key[i]);
        char currentLetter2 = toupper(EncryptedWord[i]);

        // Naujo žodžio raidės skaičiavimo indexai
        int currentLetterIndex1 = 0;
        int currentLetterIndex2 = 0;
        int newLetterIndex;
        // Jeigu šifravimas pagal abecelę:
        if(isAlphabet == true) {
            // Sukam ciklą per abecelę
            for(int j = 0; j < sizeof(Alphabet); j++) {
                // Surandam indexus raidžių (rakto ir šifruojamo žodžio)
                if(Alphabet[j] == currentLetter1) {
                    currentLetterIndex1 = j;
                }
                if(Alphabet[j] == currentLetter2) {
                    currentLetterIndex2 = j;
                }
            }
            // uzsifruotas tekstas - raktas + Dydis abeceles % dydis abecles
            newLetterIndex = (currentLetterIndex2 - currentLetterIndex1 + sizeof(Alphabet)) % sizeof(Alphabet);
        }
        else {
            // Surandam indexus raidžių (rakto ir šifruojamo žodžio) pagal ascii
            currentLetterIndex1 = int(currentLetter1);
            currentLetterIndex2 = int(currentLetter2);
            newLetterIndex = (currentLetterIndex2 - currentLetterIndex1 + 128) % 128;
        }
        // Naudojam formulę (Indexas rakto + Indexas Sifruojamo zodzio) ir padalinta is abeceles ir gauta liekana
        new_word[i] = Alphabet[newLetterIndex];
    }
    cout<<"Desifruotas zodis: "<<new_word<<endl;
    cout<<endl;
}

void EncryptWord(bool isAlphabet, char key[50], char nonEncryptedWord[50]) {
    int key_len = strlen(key);
    int word_len = strlen(nonEncryptedWord);

    // Rakto ilgis prilyginimas zodzio ilgiui (kartojasi raides)
    char extended_key[50];
    for (int i = 0; i < word_len; i++) {
        extended_key[i] = key[i % key_len];
    }
    // Formatavimas teksto
    extended_key[word_len] = '\0';

    char new_word[50];
    for(int i = 0; i < word_len; i++) {
        // Paiimam po viena raidę iš šifruojamo žodžio ir rakto
        char currentLetter1 = toupper(extended_key[i]);
        char currentLetter2 = toupper(nonEncryptedWord[i]);

        // Naujo žodžio raidės skaičiavimo indexai
        int currentLetterIndex1 = 0;
        int currentLetterIndex2 = 0;
        // Jeigu šifravimas pagal abecelę:
        int newLetterIndex;
        if(isAlphabet == true) {
            // Sukam ciklą per abecelę
            for(int j = 0; j < sizeof(Alphabet); j++) {
                // Surandam indexus raidžių (rakto ir šifruojamo žodžio)
                if(Alphabet[j] == currentLetter1) {
                    currentLetterIndex1 = j;
                }
                if(Alphabet[j] == currentLetter2) {
                    currentLetterIndex2 = j;
                }
            }
            // Naudojam formulę (Indexas rakto + Indexas Sifruojamo zodzio) ir padalinta is abeceles ir gauta liekana
            newLetterIndex = (currentLetterIndex1 + currentLetterIndex2) % sizeof(Alphabet);
        }
        else {
            // Surandam indexus raidžių (rakto ir šifruojamo žodžio) pagal ascii
            currentLetterIndex1 = int(currentLetter1);
            currentLetterIndex2 = int(currentLetter2);
            newLetterIndex = (currentLetterIndex1 + currentLetterIndex2) % 128;
        }
        new_word[i] = Alphabet[newLetterIndex];
    }
    // Formatavimas
    new_word[word_len] = '\0';  // Explicitly add the null terminator
    cout<<"Uzsifruotas zodis: "<<new_word<<endl;
    cout<<endl;
}

int main()
{
    int option = 1;
    while (option == 1 || option == 2) {
        cout<<"1. Sifravimas "<<endl;
        cout<<"2. Desifravimas "<<endl;
        cout<<"3. Isejimas"<<endl;
        cout<<"Pasirinkite: "<<endl;
        cin>>option;
        switch (option) {
            case 1: {
                int inside_option = 0;
                cout<<"Pasirinkite sifravimo buda: "<<endl;
                cout<<"1. Abecele "<<endl;
                cout<<"2. ASCII "<<endl;
                cin>>inside_option;
                bool isAlphabet = true;
                if (inside_option == 2) {
                    isAlphabet = false;
                }
                char key[50];
                char first_word[50];
                cout<<"Iveskit rakta: ";
                cin>>key;
                cout<<endl;
                cout<<"Iveskite pradini zodi: ";
                cin>>first_word;
                cout<<endl;

                EncryptWord(isAlphabet, key, first_word);
                break;
            }
            case 2: {
                int inside_option = 0;
                cout<<"Pasirinkite Desifravimo buda: "<<endl;
                cout<<"1. Abecele "<<endl;
                cout<<"2. ASCII "<<endl;
                cin>>inside_option;
                bool isAlphabet = true;
                if (inside_option == 2) {
                    isAlphabet = false;
                }
                char key[50];
                char first_word[50];
                cout<<"Iveskit rakta: ";
                cin>>key;
                cout<<endl;
                cout<<"Iveskite uzsifruota zodi zodi: ";
                cin>>first_word;
                cout<<endl;

                DecryptionWord(isAlphabet, key, first_word);
                break;
            }
        }
    }
    return 0;
}
