#include "Encryptor.h"
#include <cstdio>

Encryptor::Encryptor(const char* srcFile, const char* destFile)
    : sourceFile(srcFile), destinationFile(destFile), p_file(nullptr), p_file2(nullptr) {
    fopen_s(&p_file, sourceFile, "r");
    fopen_s(&p_file2, destinationFile, "w");
}


Encryptor::~Encryptor() {
    if (p_file) fclose(p_file);
    if (p_file2) fclose(p_file2);
}

void Encryptor::encrypt() {
    unsigned char uchReadBuffer;
    int lintCount;

    do {
        lintCount = fread_s(&uchReadBuffer, 1, 1, 1, p_file);
        if (lintCount != 0) {
            uchReadBuffer = uchReadBuffer + 1;
            fwrite(&uchReadBuffer, 1, 1, p_file2);
        }
    } while (lintCount != 0);
}

void Encryptor::decrypt() {
    unsigned char uchReadBuffer;
    int lintCount;

    do {
        lintCount = fread_s(&uchReadBuffer, 1, 1, 1, p_file);
        if (lintCount != 0) {
            uchReadBuffer = uchReadBuffer - 1;
            fwrite(&uchReadBuffer, 1, 1, p_file2);
        }
    } while (lintCount != 0);
}
