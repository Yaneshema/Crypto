
#include "AesGestion.h"
#include "RsaGestion.h"

using namespace std;

int choice = 1;
string key = "";
string file = "txtIn.txt";
string fileEncrypt = "txtEncrypt.txt";
string fileDecrypt = "txtDecrypt.txt";

AesGestion* aes = new AesGestion;
RsaGestion* rsa = new RsaGestion;

int main() {

    while (true) {

        cout << "" << endl;
        cout << "1 - Use AES" << endl;
        cout << "2 - Use RSA" << endl;

        cout << "" << endl;
        cout << "Choose an action : "; cin >> choice;

        switch (choice) {

        case 1:

            while (choice != 0) {

                cout << "" << endl;
                cout << "0 - Quit" << endl;
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

            break;

        case 2:

            while (choice != 0) {

                cout << "" << endl;
                cout << "0 - Quit" << endl;
                cout << "1 - Generate rsa keys" << endl;
                cout << "2 - Load ras keys" << endl;
                cout << "3 - Load ras private key" << endl;
                cout << "4 - Load ras public 7key" << endl;
                cout << "5 - Encrypt file" << endl;
                cout << "6 - Decrypt file" << endl;

                cout << "" << endl;
                cout << "Choose an action : "; cin >> choice;

                switch (choice) {

                case 1:

                    rsa->generationClef("rsaPublic.key", "rsaPrivate.key", 1024);
                    cout << "New rsa keys in rsaPublic.key and rsaPrivate.key" << endl;
                    break;

                case 2:

                    cout << "Enter private key : "; cin >> key;
                    rsa->chargementClefsPrive(key);
                    cout << "New rsa key loaded from " << key << endl;

                    cout << "Enter public key : "; cin >> key;
                    rsa->chargementClefsPublic(key);
                    cout << "New rsa public key loaded from " << key << endl;
                    break;

                case 3:

                    cout << "Enter private key : "; cin >> key;
                    rsa->chargementClefsPrive(key);
                    cout << "New rsa private key loaded from " << key << endl;
                    break;

                case 4:

                    cout << "Enter public key : "; cin >> key;
                    rsa->chargementClefsPrive(key);
                    cout << "New rsa public key loaded from " << key << endl;
                    break;

                case 5:

                    rsa->chiffrementFichier("txtIn.txt", "txtEncrypt.txt");
                    cout << "New rsa encrypted file from " << file << " To " << fileEncrypt << endl;
                    break;

                case 6:

                    rsa->dechiffrementFichier("txtEncrypt.txt", "txtDecrypt.txt");
                    cout << "New rsa decrypted file from " << fileEncrypt << " To " << fileDecrypt << endl;
                    break;

                default:

                    break;

                }

            }

            break;

        default:

            break;

        }
    }
}
