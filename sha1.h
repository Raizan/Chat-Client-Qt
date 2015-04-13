#ifndef SHA1
#define SHA1
#include <string>
#include <QString>
#include <openssl/sha.h>
using namespace std;

class Sha1 {
public:
    Sha1(QString input);
    ~Sha1();
    QString getStringToHash();
    void setStringToHash(QString input);

    unsigned char getHashedString(); // Get the hashed string

    QString hash(QString input); // Hash function
    QString generateSalt(QString input);

private:
    QString stringToHash; // To store string that will be hashed.
    unsigned char hashedString[20]; // To store hashed string.
};

#endif // SHA1

