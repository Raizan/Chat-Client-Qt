#include "rc4algorithm.h"
RC4Algorithm::RC4Algorithm(string key)
{
    for (int i=0; i<256; i++){
        S[i]=i;
        T[i]=key[i% key.length()];
    }
    initPermutation();
    this->i=0;
    this->j=0;
}

RC4Algorithm::~RC4Algorithm()
{
}

void RC4Algorithm::initPermutation()
{
    int j=0;
    for(int i=0;i<256;i++){
        j = (j+S[i]+T[i])%256;
        swap(S[i],S[j]);
    }
}

unsigned char RC4Algorithm::genKey()
{
    i = (i+1) % 256;
    j = (j+S[i]) % 256;
    swap(S[i],S[j]);
    int t = (S[i] + S[j]) % 256;
    return S[t];
}

string RC4Algorithm::encrpyt(string plaintext)
{
    string ciphertext;
    for(unsigned int i=0;i<plaintext.length();i++){
          ciphertext[i] = genKey() ^ plaintext[i];
    }
    return ciphertext;
}

string RC4Algorithm::decrypt(string ciphertext)
{
    string plaintext;
    for(unsigned int i=0;i<ciphertext.length();i++){
        plaintext[i] = genKey() ^ ciphertext[i];
    }
    return plaintext;
}

