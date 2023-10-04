
#include "AesGestion.h"
#include "RsaGestion.h"
#include "HashGestion.h"

using namespace std;

int main() {

    int choice = -1;
    string fp = "";
    string key = "";
    string fileIn = "";
    string fileOut = "";

    AesGestion* aes = new AesGestion();
    RsaGestion* rsa = new RsaGestion();
    HashGestion* sha = new HashGestion();

    while (true) {

        cout << "" << endl;
        cout << "1 - Use AES" << endl;
        cout << "2 - Use RSA" << endl;
        cout << "3 - Use SHA256" << endl;

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

                    cout << "Enter input file name : "; cin >> fileIn;
                    cout << "Enter output file name : "; cin >> fileOut;
                    aes->EncryptFileAES256(fileIn, fileOut);
                    cout << "New aes encrypted file from " << fileIn << " To " << fileOut << endl;
                    break;

                case 5:

                    cout << "Enter input file name : "; cin >> fileIn;
                    cout << "Enter output file name : "; cin >> fileOut;
                    aes->DecryptFileAES256(fileIn, fileOut);
                    cout << "New aes decrypted file from " << fileIn << " To " << fileOut << endl;
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
                cout << "2 - Load rsa keys" << endl;
                cout << "3 - Load rsa private key" << endl;
                cout << "4 - Load rsa public key" << endl;
                cout << "5 - Encrypt file" << endl;
                cout << "6 - Decrypt file" << endl;

                cout << "" << endl;
                cout << "Choose an action : "; cin >> choice;

                switch (choice) {

                case 1:

                    rsa->generationClef("PublicKey", "PrivateKey", 1024);
                    cout << "New rsa keys in rsaPublic.key and rsaPrivate.key" << endl;
                    break;

                case 2:

                    cout << "Enter private key : "; cin >> key;
                    rsa->chargementClefsPrive(key);
                    cout << "New rsa key loaded from " << key << endl;
                    cout << "" << endl;
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

                    cout << "Enter input file name : "; cin >> fileIn;
                    cout << "Enter output file name : "; cin >> fileOut;
                    rsa->chiffrementFichier("txtIn.txt", "txtEncrypt.txt", 0);
                    cout << "New rsa encrypted file from " << fileIn << " To " << fileOut << endl;
                    break;

                case 6:

                    cout << "Enter input file name : "; cin >> fileIn;
                    cout << "Enter output file name : "; cin >> fileOut;
                    rsa->dechiffrementFichier(fileIn, fileOut, 0);
                    cout << "New rsa decrypted file from " << fileIn << " To " << fileOut << endl;
                    break;

                default:

                    break;
                }
            }

            break;

        case 3:

            cout << "Input file name : "; cin >> fileIn;
            fp = sha->CalculateFileSHA256(fileIn);
            cout << "SHA256 fingerprint : " << fp << endl;
            break;

        default:

            break;
        }
    }
}
