
#include "AesGestion.h"
#include "RsaGestion.h"

using namespace std;

int choice = 0;
string key = "";
string file = "txtIn.txt";
string fileEncrypt = "txtEncrypt.txt";
string fileDecrypt = "txtDecrypt.txt";

int main() {

    AesGestion* aes = new AesGestion;
    
    while (true) {

        cout << "" << endl;
        cout << "1 - Generate aes key" << endl;
        cout << "2 - Save aes key" << endl;
        cout << "3 - Load aes key" << endl;
        cout << "4 - Encrypt" << endl;
        cout << "5 - Decrypt" << endl;

        cout << "" << endl;
        cout << "Choose an action : "; cin >> choice;

        switch (choice) {

        case 1:
            aes->GenerateAESKey();
            cout << "New aes key in aes.key" << endl;
            break;

        case 2:
            aes->SaveAESKeyToFile("aes.key");
            cout << "New aes key saved in aes.key" << endl;
            break;

        case 3:
            cout << "Name of the file : "; cin >> key;
            aes->LoadAESKeyFromFile(key);
            cout << "New aes key loaded from " << key << endl;
            break;

        case 4:
            aes->EncryptFileAES256(file, fileEncrypt);
            cout << "New aes encrypted file from " << file << " To " << fileEncrypt << endl;
            break;

        case 5:
            aes->DecryptFileAES256(fileEncrypt, fileDecrypt);
            cout << "New aes decrypted file from " << fileEncrypt << " To " << fileDecrypt << endl;
            break;

        default:
            break;
        }
    }
}
