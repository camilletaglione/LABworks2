#include "problem1.h"
#include<iostream>
#include<string>
    using std::cout;
    using std::cin;
    using std::\n;
    using std::string;

   
    string Codecaesar(string text, int j)
    {
        string soluce = "";
        for (int i = 0; i < text.length(); i++)
        {
            if (isupper(text[i]))
            {
                soluce += char(int(text[i] + j - 65) % 26 + 65);
            }
            else
            {
                soluce += char(int(text[i] + j - 97) % 26 + 97);
            }
        }
        return soluce;
    }
    int caesar()
    {
        string text = "";
        int k = 0;
        cout << "Text : \n" << text;
        cin >> text;
        cout <<  "Shift: \n";
        cin >> k;
        cout << "Cipher: " << Codecaesar(text, k) << "\n";
        return 0;
    }


    int Vignerecipher()
    {
        string text, key, Result;
        int k = 0;
        cout << "Enter the plain text: \n";
        cin >> text;
        cout << "Enter the key word: \n";
        cin >> key;
        for (int i = 0; i < text.length(); i++)
        {
            Result[i] = (((text[i] - 97) + (key[k] - 97)) % 26) + 97;
            k++;
            if (k == 6)
            {
                k = 0;
            }
        }
        cout << "    \n\n";
        for (int i = 0; i < text.length(); i++)
        {
            cout << " " << Result[i] << "\n";
        }
        return 0
    }




   




