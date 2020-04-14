#include "problem2.h"
#include<iostream>
#include<string>
    using std::cout;
    using std::cin;
    using std::\n;
    using std::string;

    int cesarmain()
    {
        int choice;
        cout << "1. Encryption \n 2. Decryption \n Enter choice(1,2): ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) 
        {
            string msg;
            cout << "Message can only be alphabetic \n";
            cout << "Enter message: ";
            getline(cin, msg);

            int key;
            cout << "Enter key (0-25): ";
            cin >> key;
            cin.ignore();

            string encryptedText = msg;

            for (int i = 0; i < msg.size(); i++) 
            {

                if (msg[i] == 32) 
                {
                    continue;
                }
                else 
                {

                    if ((msg[i] + key) > 122) 
                    {
                        int temp = (msg[i] + key) - 122;
                        encryptedText[i] = 96 + temp;
                    }
                    else if (msg[i] + key > 90 && msg[i] <= 96) 
                    {
                        int temp = (msg[i] + key) - 90;
                        encryptedText[i] = 64 + temp;
                    }
                    else 
                    {
                        encryptedText[i] += key;
                    }
                }
            }
            cout << "Encrypted Message: " << encryptedText;
        }
        else if (choice == 2) 
        {
            string encpMsg;
            cout << "Message can only be alphabetic \n";
            cout << "Enter encrypted text: ";
            getline(cin, encpMsg);
            int dcyptKey;
            cout << "Enter key (0-25): ";
            cin >> dcyptKey;
            cin.ignore();
            string decryptedText = encpMsg;
            for (int i = 0; i < encpMsg.size(); i++) 
            {
                if (encpMsg[i] == 32) {
                    continue;
                }
                else 
                {
                    if ((encpMsg[i] - dcyptKey) < 97 && (encpMsg[i] - dcyptKey) > 90) 
                    {
                        int temp = (encpMsg[i] - dcyptKey) + 26;
                        decryptedText[i] = temp;
                    }
                    else if ((encpMsg[i] - dcyptKey) < 65) 
                    {
                        int temp = (encpMsg[i] - dcyptKey) + 26;
                        decryptedText[i] = temp;
                    }
                    else 
                    {
                        decryptedText[i] = encpMsg[i] - dcyptKey;
                    }
                }
            }
            cout << "Decrypted Message: " << decryptedText << "\n";
        }
        else {
            cout << "Invalid choice";
        }
        return 0;
    }
    string message;
    string mappedKey;
    void messageAndKey() 
    {
        string msg;
        cout << "Enter message: ";
        getline(cin, msg);
        cin.ignore();
        for (int i = 0; i < msg.length(); i++) 
        {
            msg[i] = toupper(msg[i]);
        }
        string key;
        cout << "Enter key: ";
        getline(cin, key);
        cin.ignore();
        for (int i = 0; i < key.length(); i++) 
        {
            key[i] = toupper(key[i]);
        }
        string keyMap = "";
        for (int i = 0, j = 0; i < msg.length(); i++) 
        {
            if (msg[i] == 32) 
            {
                keyMap += 32;
            }
            else {
                if (j < key.length()) 
                {
                    keyMap += key[j];
                    j++;
                }
                else 
                {
                    j = 0;
                    keyMap += key[j];
                    j++;
                }
            }
        } 
        message = msg;
        mappedKey = keyMap;
    }

    int tableArr[26][26];
    void createVigenereTable() 
    {
        for (int i = 0; i < 26; i++) 
        {
            for (int j = 0; j < 26; j++) 
            {
                int temp;
                if ((i + 65) + j > 90) 
                {
                    temp = ((i + 65) + j) - 26;
                    tableArr[i][j] = temp;
                }
                else 
                {
                    temp = (i + 65) + j;
                    tableArr[i][j] = temp;
                }
            }
        }
    }

    void cipherEncryption(string message, string mappedKey)
    {
        createVigenereTable();
        string encryptedText = "";
        for (int i = 0; i < message.length(); i++) 
        {
            if (message[i] == 32 && mappedKey[i] == 32) 
            {
                encryptedText += " ";
            }
            else 
            {
                int x = (int)message[i] - 65;
                int y = (int)mappedKey[i] - 65;
                encryptedText += (char)tableArr[x][y];
            }
        }
        cout << "Encrypted Text: " << encryptedText;
    }

    int itrCount(int key, int msg) 
    {
        int counter = 0;
        string result = "";
        for (int i = 0; i < 26; i++)
        {
            if (key + i > 90) 
            {
                result += (char)(key + (i - 26));
            }
            else 
            {
                result += (char)(key + i);
            }
        }
        for (int i = 0; i < result.length(); i++) 
        {
            if (result[i] == msg) 
            {
                break;
            }
            else 
            {
                counter++;
            }
        }
        return counter;
    }


    void cipherDecryption(string message, string mappedKey) 
    {
        string decryptedText = "";
        for (int i = 0; i < message.length(); i++) 
        {
            if (message[i] == 32 && mappedKey[i] == 32) 
            {
                decryptedText += " ";
            }
            else 
            {
                int temp = itrCount((int)mappedKey[i], (int)message[i]);
                decryptedText += (char)(65 + temp);
            }
        }

        cout << "Decrypted Text: " << decryptedText;
    }


    int decrymain()
    {
        cout << "Message and key can only be alphabetic \n";
        int choice;
        cout << "1. Encryption\n2. Decryption\nChoose(1,2): ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) 
        {
            cout << "Encryption \n";
            messageAndKey();
            cipherEncryption(message, mappedKey);

        }
        else if (choice == 2) 
        {
            cout << "Decryption \n";
            messageAndKey();
            cipherDecryption(message, mappedKey);

        }
        else 
        {
            cout << "Wrong Choice \n";
        }

        return 0;
    }