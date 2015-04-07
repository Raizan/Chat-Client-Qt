#ifndef RC4ALGORITHM_H
#define RC4ALGORITHM_H

#include <string>
using namespace std;
class RC4Algorithm
{
public:
    RC4Algorithm(string key);
    ~RC4Algorithm();
    void initPermutation();
    unsigned char genKey();
    string encrpyt(string plaintext);
    string decrypt(string ciphertext);
private:
    unsigned char S[256];
    unsigned char T[256];
    unsigned char K[256];
    int i;
    int j;
};

#endif // RC4ALGORITHM_H
