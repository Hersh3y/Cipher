/*
Implementation file for the Cipher class.
It implements a cipher key and handles encoding and decoding messages using the key.
*/

#include "Cipher.h"
#include "Queue.h"
#include <iostream>
#include <string>
using namespace std;

// Cipher() default constructor which sets the key to “cpsc” and “cpsc”
Cipher::Cipher() {

    // Variable for default key
    string default_key = "cpsc";

    // Sets size variable to the size of default_key
    int size = default_key.size();

    // Allocate memory for the two keys
    char* key1 = new char[size];
    char* key2 = new char[size];

    // For-loop to turn the default key into two keys that are char arrays
    for (int i = 0; i < size; i++) {
        key1[i] = default_key[i];
        key2[i] = default_key[i];
    }

    // Set the cipher to the default key
    setCipher(size, key1, key2);

    // Free memory
    delete[] key1;
    delete[] key2;
}

// Cipher(int, char*) overloaded constructor which sets the key
Cipher::Cipher(int size, char* key) {
    // Calls setCipher to set cipher
    setCipher(size, key, key);
}

/* setCipher(int, char *, char *) to take in the two repeating keys (where int are the size of 
   the arrays should be equal in size.) and sets the cypher */
void Cipher::setCipher(int size, char* key1, char* key2) {

    // Clears the combinesd_key
    combined_key.clear();

    // For-loop over the keys
    for (int i = 0; i < size; i++) {

        // Convert the elements to lowercase
        char character1 = tolower(key1[i]);
        char character2 = tolower(key2[i]);
        
        // Convert letter to number
        int shift1 = character1 - 'a' + 1;
        int shift2 = character2 - 'a' + 1;

        // Shifts letter
        int total_shift = (shift1 + shift2) % 26;

        if (total_shift == 0) {
            total_shift = 26;
        }

        // Convert back to letter and appends to combined_key
        combined_key += static_cast<char>('a' + total_shift - 1);

    }
}

/* char * getCipher() to get back the key as a string
   Returns a pointer to the key array */
char* Cipher::getCipher() {

    // Allocate memory for the key
    char* key = new char[combined_key.size()];

    // For-loop to copy the combined_key to key array
    for (int i = 0; i < static_cast<int>(combined_key.size()); i++) {
        key[i] = combined_key[i];
    }

    // Returns pointer to the key array
    return key;
}

/* string encodeMessage(string in) to send in a string message to encode and 
   returns the encoded message as a string */
string Cipher::encodeMessage(string in) {

    // Create queue object
    Queue queue1;

    // For-loop to put combined_key into queue
    for (int i = 0; i < static_cast<int>(combined_key.size()); i++) {
        char character = combined_key[i];
        queue1.enqueue(character);
    }

    // Variable for stripped message
    string stripped_message;

    // For-loop to strip the input
    for (int i = 0; i < static_cast<int>(in.length()); i++) {

        char character2 = in[i];

        if (isalpha(character2)) {
            stripped_message += tolower(character2);
        }

    }
    
    // Result variable for the encoded message
    string result;
    
    // Encode each character using the cipher key
    for (int i = 0; i < static_cast<int>(stripped_message.length()); i++) {
        
        char c = stripped_message[i];
        char shift;
        char shifted_character;
    
        queue1.dequeue(shift);
        shifted_character = letterShift(c, shift, false);
        result += shifted_character;
        queue1.enqueue(shift);
    }
    
    return result;
}

/* string decodeMessage(string in) to send in an encoded string message and 
   returns the decoded message as a string */
string Cipher::decodeMessage(string in) {

    // Create queue object
    Queue queue1;

    // For-loop to put combined_key into queue
    for (int i = 0; i < static_cast<int>(combined_key.size()); i++) {
        char character = combined_key[i];
        queue1.enqueue(character);
    }

    // Result variable for the decoded message
    string result;

    // For-loop through and build the decoded message
    for (int i = 0; i < static_cast<int>(in.length()); i++) {

        char character = in[i];
        char shift;
        char shifted_letter;
    
        queue1.dequeue(shift);
        shifted_letter = letterShift(character, shift, true);
        result += shifted_letter;
        queue1.enqueue(shift);

    }

    return result;
}

/* shifts l1, by l2 in the direction determined by reverse (true is in reverse, false is forward) and
   Returns shifted letter */
char Cipher::letterShift(char l1, char l2, bool reverse) {

    // Convert to number
    int character = (tolower(l1)) - 'a';
    int shift = (tolower(l2)) - 'a' + 1;

    // Check for reverse
    if (reverse) {
        character = (character - shift + 26) % 26;
    }
    else { 
        character = (character + shift) % 26;
    }

    // Convert to char
    char result = 'a' + character;

    return result;
}
