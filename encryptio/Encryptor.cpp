#include "Encryptor.h"
#include <cstdio>





// definice konstruktoru
Encryptor::Encryptor(const char* srcFile, const char* destFile)

    // inicializace clenu
    : sourceFile(srcFile), destinationFile(destFile), p_file(nullptr), p_file2(nullptr) {
    
    
    //otevreni souboru file a file2 do prislusnych modu
    fopen_s(&p_file, sourceFile, "r");
    fopen_s(&p_file2, destinationFile, "w");
}

//definice destruktoru

Encryptor::~Encryptor() {
    
    // zavre file a file2
    if (p_file) fclose(p_file);
    if (p_file2) fclose(p_file2);
}


//definice rutiny encrypt
void Encryptor::encrypt() {
    
    
    unsigned char uchReadBuffer;
    int lintCount;

    do {
       
        //lintcount != 0 fread precetl byte
        lintCount = fread_s(&uchReadBuffer, 1, 1, 1, p_file);
        
        
        //pokud je mozno precist byte zapise hodnotu bytu + 1 v ASCII do file2
        if (lintCount != 0) {
            uchReadBuffer = uchReadBuffer + 1;
            fwrite(&uchReadBuffer, 1, 1, p_file2);
        }
    } while (lintCount != 0);
}


//stejne jako encrypt ale posouva o -1
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
