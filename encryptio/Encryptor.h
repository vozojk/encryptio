#pragma once
#ifndef ENCRYPTOR_H
#define ENCRYPTOR_H
#include <cstdio> // Ensure stdio.h is included for FILE

class Encryptor {
public:
    Encryptor(const char* srcFile, const char* destFile);
    ~Encryptor();
    void encrypt();
    void decrypt();

private:
    const char* sourceFile;
    const char* destinationFile;
    FILE* p_file;
    FILE* p_file2;
};

#endif // ENCRYPTOR_H
