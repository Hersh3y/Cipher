/*
Header file that defines the Cipher class.
*/

#ifndef CIPHER_H
#define CIPHER_H

#include "Queue.h"
#include <iostream>
#include <string>
using namespace std;

class Cipher {

public:

    // Cipher() default constructor which sets the key to “cpsc” and “cpsc” 
    Cipher();

    // Cipher(int, char*) overloaded constructor which sets the key
    Cipher(int, char*);

    /* setCipher(int, char *, char *) to take in the two repeating keys (where int are the size of 
       the arrays should be equal in size.) and sets the cypher */
    void setCipher(int, char *, char *);

    /* char * getCipher() to get back the key as a string
       Returns a pointer to the key array */
    char* getCipher();

    /* string encodeMessage(string in) to send in a string message to encode and 
       returns the encoded message as a string */
    string encodeMessage(string in);

    /* string decodeMessage(string in) to send in an encoded string message and 
       returns the decoded message as a string */
    string decodeMessage(string in);
    
    /* shifts l1, by l2 in the direction determined by reverse (true is in reverse, false is forward) 
       Returns */
    static char letterShift(char l1, char l2, bool reverse);

private:

    /* shifts l1, by l2 in the direction determined by reverse (true is in reverse, false is forward) and
       Returns shifted letter */
    string combined_key;

};

#endif
