#include <iostream>
#include <string.h>
#include <cstring>  // For strlen and memset

using namespace std;

const char Alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int main()
{
    char key[50];
    char first_word[50];
    cout<<"Iveskit rakta: ";
    cin>>key;
    cout<<endl;
    cout<<"Iveskite pradini zodi: ";
    cin>>first_word;
    cout<<endl;

    int key_len = strlen(key);
    int word_len = strlen(first_word);

    char extended_key[50];
    for (int i = 0; i < word_len; i++) {
        extended_key[i] = key[i % key_len];
    }

    extended_key[word_len] = '\0';

    char new_word[50];
    for(int i = 0; i < word_len; i++) {
        char currentLetter1 = extended_key[i];
        char currentLetter2 = first_word[i];

        int currentLetterIndex1 = 0;
        int currentLetterIndex2 = 0;

        for(int j = 0; j < sizeof(Alphabet); j++) {
            if(Alphabet[j] == currentLetter1) {
                currentLetterIndex1 = j;
            }
            if(Alphabet[j] == currentLetter2) {
                currentLetterIndex2 = j;
            }
        }
        int newLetterIndex = (currentLetterIndex1 + currentLetterIndex2) % sizeof(Alphabet);
        new_word[i] = Alphabet[newLetterIndex];
    }

    new_word[word_len] = '\0';  // Explicitly add the null terminator
    cout<<new_word;


    return 0;
}
