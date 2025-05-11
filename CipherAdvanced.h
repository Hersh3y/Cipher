/*
Header file that defines the Queue class
*/

#ifndef CIPHERADVANCED_H
#define CIPHERADVANCED_H

#include "Cipher.h"
#include "Queue.h"
#include <iostream>
using namespace std;

class CipherAdvanced : public Cipher {
public:

    /* takes in an encoded sequence of characters which make up one or more words and 
    attempts to decipher it. */
    void unknownMultiWordScramble(string scramble);

};

#endif

