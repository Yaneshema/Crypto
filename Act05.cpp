
#include "AesGestion.h"
#include <iostream>

using namespace std;

int main() {

    AesGestion* aes = new AesGestion;
    aes->GenerateAESKey();
    aes->SaveAESKeyToFile("aes.txt");
    cout << "New aes key in aes.txt" << endl;
}
