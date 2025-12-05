#include <iostream>
using namespace std;
string vigenere(string text,string key,bool EncDec);
int main () {
    string plaintext;
    string ciphertext;
    string key;
    char x;

    do{
          cout << "Welcome to the Vigenere Cipher Application!" << endl;
    cout << "This application allows you to encrypt plaintext using the Vigenere cipher." << endl;
    cout << "Please note that the Vignere Cipher only works for capital letters." << endl;
    cout << "Please choose one of the following options" << endl;
    cout<<"1.Encryption 2.Decryption 3.exit"<<endl;
    int option;
    cin>>option;

    string plaintext;
    string ciphertext;
    string key;

    switch(option){
        case 1:
            cout<<"Please enter the plaintext: "<<endl;
            cin>>plaintext;
            cout<<"Please enter the key: "<<endl;
            cin>>key;
          
            ciphertext = vigenere(plaintext,key,0);
            cout<<"Cipher text: "<<ciphertext<<endl;
            cout<<"Press Y/y to repeat the process or any key to exit"<<endl;
            cin>>x;
            break;

        case 2:
            cout<<"Please enter the ciphertext: "<<endl;
            cin>>plaintext;
            cout<<"Please enter the key: "<<endl;
            cin>>key;
            ciphertext = vigenere(plaintext,key,1);
            cout<<"Plaintext: "<<ciphertext<<endl;
            cout<<"Press Y/y to repeat the process or any key to exit"<<endl;
            cin>>x;
            break;
            

        case 3:
            x='n';
            break;
    
    }
    }while(x=='Y' || x=='y');
  
}

string vigenere(string text,string key,bool EncDec) {
    string newkey = key, newtext;
    while(newkey.length()<text.length())
    {
        newkey+=key;
    }
    if (EncDec==0)
    {
        for(int i = 0; i < text.length(); i++) 
        {
            newtext+=(text[i] + newkey[i])%26 + 65;
        }

    }else{
        for(int i = 0; i < text.length(); i++) 
        {
            newtext+=(text[i] - newkey[i] + 26)%26 + 65;
        }
    }
    return newtext;

}