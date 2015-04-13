#include "sha1.h"

Sha1::Sha1(QString input){
    this->setStringToHash(input);
}

Sha1::~Sha1(){

}

void Sha1::setStringToHash(QString input){
    this->stringToHash = input;
}

QString Sha1::getStringToHash(){
    return this->stringToHash;
}

unsigned char Sha1::getHashedString(){
    return this->hashedString;
}

void Sha1::hash(QString input){
    string stdstr = input.toStdString();
    const char * cstr = stdstr.c_str();
    SHA1((unsigned char*)cstr, cstr.size(), this->hashedString); // Store the result to hashedString variable
}

QString Sha1::generateSalt(QString input){
    // Don't have any idea
}
