/*
Main driver file for cypher program.
It uses the Cipher and Queue classes to encode and decode messages.
*/

/*
Harshal Patel
04/06/2025
Project-3: Cypher
Purpose: Code for a cypher program that encodes and decodes messages with a key.
Citations:
    Used this to check if a character is a letter: https://cplusplus.com/reference/cctype/isalpha/
    
I certify that I followed the collaboration policy.
*/

#include "Cipher.h"
#include "Queue.h"
#include <iostream>
#include <string>
using namespace std;

// main function
int main() {

    // Variables for the first and second key
    string first_key;
    string second_key;

    // Prompts user for the first and second key
    cout << "Type in the first word to use as the key: ";
    cin >> first_key;
    cout << "Type in the second word to use as the key: ";
    cin >> second_key;

    // size variable that holds the size of first_key
    int size = first_key.length();

    // Allocates memory for the new first and second keys
    char* key1_stripped = new char[size + 1];
    char* key2_stripped = new char[size + 1];

    // Lowercases letters and appends them to the new first and second key variable only if they are letters
    for (int i = 0; i < size; i++) {
        if (isalpha(first_key[i])) {
            key1_stripped[i] = tolower(first_key[i]);
        }
        if (isalpha(second_key[i])) {
            key2_stripped[i] = tolower(second_key[i]);
        }
    }
    
    // Create cipher ojbect
    Cipher cipher;

    // Sets the first and second key
    cipher.setCipher(size, key1_stripped, key2_stripped);

    // Sets new_key to the cipher key by calling getCipher()
    char* new_key = cipher.getCipher();

    // Variable for the user's choice
    char user_choice;

    // Variable for the message and result
    string message;
    string result;

    // Do-while loop for menu until user enters 'q' to quit
    do {
        // Prints menu
        cout << "\nKeys: " << first_key << " and " << second_key << "\n";
        cout << "New Key: " << new_key << "\n";
        cout << "[e] encode with this key\n";
        cout << "[d] decode with this key\n";
        cout << "[q] quit\n";

        // Primpts user for choice
        cin >> user_choice;
        cin.ignore();
        
        // If statement to handle user's choice
        if (user_choice == 'e' || user_choice == 'd') {

            // Prompts user for message
            cout << "Enter what to ";
            
            // Calls encodeMessage function if user chose 'e', decodeMessage function if user chose 'd', and prints results
            if (user_choice == 'e') {
                cout << "encode: ";
                getline(cin, message);
                result = cipher.encodeMessage(message);
                cout << "result: " << result << "\n";
            }
            else if (user_choice == 'd') { 
                cout << "decode: ";
                getline(cin, message);
                result = cipher.decodeMessage(message);
                cout << "result: " << result << "\n";
            }
            
        }
        // Exit loop if user chooses 'q' to quit
    } while (user_choice != 'q');

    // free memory
    delete[] key1_stripped;
    delete[] key2_stripped;
    delete[] new_key;

    return 0;
}

