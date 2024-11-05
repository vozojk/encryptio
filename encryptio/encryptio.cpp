#include "Encryptor.h"
#include <iostream>
#include <windows.h>

int main() {
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
    
    
    

    std::cout << "Encryption complete." << std::endl;
    return 0;
}
