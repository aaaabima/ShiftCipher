/*
 * Mochamad Arya Bima Agfian
 * 140810190031
 * Kelas A
 * ShiftCypher
 */
#include <iostream>
#include <string.h>

using namespace std;

void Encrypt(char plainText[], char cypherText[], int key);
void Decrypt(char plainText[], int key);

main()
{
  char nama[30];
  char cypherText[30];
  int k;
  
  while(true){
    cout << "Name input : ";
    cin.getline(nama, 30);
    cout << "Shift Key : ";
    cin >> k;

    Encrypt(nama,cypherText,k);
    cout << "Ecryption result : ";
    for (int i = 0; i < strlen(nama); i++)
      cout << cypherText[i];
    
    Decrypt(cypherText,k);
    cout << "\nDecryption result : ";
    for (int i = 0; i < strlen(nama); i++)
      cout << cypherText[i];

    char repeat;
    cout << "\n\nRepeat? (Y/N) "; cin >> repeat;
    if(repeat == 'y' || repeat == 'Y'){
      cin.ignore();
      true;
    }
    else
      break;
  }
}

void Encrypt(char plainText[30], char cypherText[30], int key)
{
  for (int i = 0; i < strlen(plainText); i++)
  {
    int ascii = int(plainText[i]);
    if (int(plainText[i]) <= int('Z') && int(plainText[i]) >= int('A')){
      ascii += key;
      while(ascii > int('Z'))
        ascii -= 26;
      cypherText[i] = char(ascii);
    }
    else if (int(plainText[i]) <= int('z') && int(plainText[i]) >= int('a')){
      ascii += key;
      while(ascii > int('z'))
        ascii -= 26;
      cypherText[i] = char(ascii);
    }
    else
      cypherText[i] = char(ascii);
  }
}

void Decrypt(char plainText[], int key){
  for (int i = 0; i < strlen(plainText); i++)
  {
    int ascii = int(plainText[i]);
    if (int(plainText[i]) <= int('Z') && int(plainText[i]) >= int('A')){
      ascii -= key;
      while(ascii < int('A'))
        ascii += 26;
      plainText[i] = char(ascii);
    }
    else if (int(plainText[i]) <= int('z') && int(plainText[i]) >= int('a')){
      ascii -= key;
      while(ascii < int('a'))
        ascii += 26;
      plainText[i] = char(ascii);
    }
    else
      plainText[i] = char(ascii);
  }
}