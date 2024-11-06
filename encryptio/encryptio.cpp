#include "Encryptor.h"
#include <iostream>
#include <windows.h>

int main() {
    
    
    //deklarace cest k souborum
    const char* sourcePath = "c:\\Temp\\test.txt";
    const char* destinationPath = "c:\\Temp\\test01.txt";

    Encryptor encryptor(sourcePath, destinationPath);
    if (MessageBoxA(NULL, "Encrypt?", "Encryptor", MB_YESNO) == IDYES)
    {
        encryptor.encrypt();
    }
    else
    {
        encryptor.decrypt();
    }
    
    
    

    printf("Encryption Complete!");
    return 0;
}
