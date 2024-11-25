#include <iostream>
#include <string.h>
#include <cstring>  // For strlen and memset

using namespace std;

const char Alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

const int ASCII_MIN = 33, ASCII_MAX = 126;
const int ASCII_RANGE = ASCII_MAX - ASCII_MIN + 1;

void DecryptionWord(bool isAlphabet, char key[50], char EncryptedWord[50]) {

    int key_len = strlen(key);
    int word_len = strlen(EncryptedWord);

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
        char currentLetter1 = extended_key[i];
        char currentLetter2 = EncryptedWord[i];

        // Naujo žodžio raidės skaičiavimo indexai
        int currentLetterIndex1 = 0;
        int currentLetterIndex2 = 0;
        int newLetterIndex;
        // Jeigu šifravimas pagal abecelę:
        if(isAlphabet == true) {
            // Sukam ciklą per abecelę
            for(int j = 0; j < sizeof(Alphabet); j++) {
                // Surandam indexus raidžių (rakto ir šifruojamo žodžio)
                if(Alphabet[j] == toupper(currentLetter1)) {
                    currentLetterIndex1 = j;
                }
                if(Alphabet[j] == toupper(currentLetter2)) {
                    currentLetterIndex2 = j;
                }
            }
            // uzsifruotas tekstas - raktas + Dydis abeceles % dydis abecles
            newLetterIndex = (currentLetterIndex2 - currentLetterIndex1 + sizeof(Alphabet)) % sizeof(Alphabet);
            new_word[i] = Alphabet[newLetterIndex];
        }
        else {
            // Surandam indexus raidžių (rakto ir šifruojamo žodžio) pagal ascii
            currentLetterIndex1 = int(currentLetter1); // raktas
            currentLetterIndex2 = int(currentLetter2); // zodis

            //newLetterIndex = (currentLetterIndex2 - currentLetterIndex1 - 32 + 95) % 95 + 32;
            newLetterIndex = ((currentLetterIndex2 - ASCII_MIN) - (currentLetterIndex1 - ASCII_MIN) + ASCII_RANGE) % ASCII_RANGE + ASCII_MIN;
            new_word[i] = char(newLetterIndex);
        }
    }
    // Formatavimas
    new_word[word_len] = '\0';
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
        char currentLetter1 = extended_key[i];
        char currentLetter2 = nonEncryptedWord[i];

        // Naujo žodžio raidės skaičiavimo indexai
        int currentLetterIndex1 = 0;
        int currentLetterIndex2 = 0;
        // Jeigu šifravimas pagal abecelę:
        int newLetterIndex;
        if(isAlphabet == true) {
            // Sukam ciklą per abecelę
            for(int j = 0; j < sizeof(Alphabet); j++) {
                // Surandam indexus raidžių (rakto ir šifruojamo žodžio)
                if(Alphabet[j] == toupper(currentLetter1)) {
                    currentLetterIndex1 = j;
                }
                if(Alphabet[j] == toupper(currentLetter2)) {
                    currentLetterIndex2 = j;
                }
            }
            // Naudojam formulę (Indexas rakto + Indexas Sifruojamo zodzio) ir padalinta is abeceles ir gauta liekana
            newLetterIndex = (currentLetterIndex1 + currentLetterIndex2) % sizeof(Alphabet);
            new_word[i] = Alphabet[newLetterIndex];
        }
        else {
            // Surandam indexus raidžių (rakto ir šifruojamo žodžio) pagal ascii
            currentLetterIndex1 = int(currentLetter1); // raktas
            currentLetterIndex2 = int(currentLetter2); // zodis
            //newLetterIndex = ((currentLetterIndex1 + currentLetterIndex2 - 32) % 95 + 32);
            newLetterIndex = ((currentLetterIndex2 - ASCII_MIN) + (currentLetterIndex1 - ASCII_MIN)) % ASCII_RANGE + ASCII_MIN;
            new_word[i] = char(newLetterIndex);
        }
    }
    // Formatavimas
    new_word[word_len] = '\0';
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
