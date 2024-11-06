#pragma once
#ifndef ENCRYPTOR_H
#define ENCRYPTOR_H
#include <cstdio> // Ensure stdio.h is included for FILE

class Encryptor {
public:

    // deklarace konstruktoru, parametry source, destination
    Encryptor(const char* srcFile, const char* destFile);

    // deklarace destruktoru
    ~Encryptor();

    //deklarace encrypt a decrypt
    void encrypt();
    void decrypt();

private:


    // deklarace cest k souborum source, destination a pointeru na soubory file a file2
    const char* sourceFile;
    const char* destinationFile;
    FILE* p_file;
    FILE* p_file2;
};

#endif // ENCRYPTOR_H
