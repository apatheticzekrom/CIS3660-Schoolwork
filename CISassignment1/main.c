/*=============================================================================
| Assignment: pa01 - Encrypting a plaintext file using the Vigenere cipher
|
| Author: Benjamin Giang
| Language: c, c++, Java
|
| To Compile: javac pa01.java
| gcc -o pa01 pa01.c
| g++ -o pa01 pa01.cpp
|
| To Execute: java -> java pa01 kX.txt pX.txt
| or c++ -> ./pa01 kX.txt pX.txt
| or c -> ./pa01 kX.txt pX.txt
| where kX.txt is the keytext file
| and pX.txt is plaintext file
|
| Note: All input files are simple 8 bit ASCII input
|
| Class: CIS3360 - Security in Computing - Fall 2021
| Instructor: McAlpin
| Due Date: per assignment
|
+=============================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_ARRAY_SIZE 3000
#define MAX_CHAR_ARR 512

const char* readKeyFile(FILE* infile)
{
  char* inputString = (char*)malloc(sizeof(char) * MAX_CHAR_ARR);
  int i = 0;

  char ch;
  while (fscanf(infile, "%c", &ch) != EOF)
  {
    if(isalpha(ch))
    {
      inputString[i] = tolower(ch);
      i++;
      // printf("%c", inputString[i]);
    }
  }
  // printf("%s", inputString);

  return inputString;
}

void printString(char* str, int len)
{
    int i = 0;
    
    while(i < len)
    {
      if(i % 80 == 0)
      {
        printf("\n");
      }
      printf("%c", str[i]);
      i++;
      if(i >= 512)
      {
        break;
      }
      
    }
}

const char* readMessageFile(FILE* infile)
{
  char* inputString2 = (char*)malloc(sizeof(char) * MAX_ARRAY_SIZE);
  int i = 0;
  char ch;

  while (fscanf(infile, "%c", &ch) != EOF)
  {
    if(isalpha(ch))
    {
      inputString2[i] = tolower(ch);
      i++;
      // printf("%c", inputString[i]);
    }
  }
  
  return inputString2;
}

char* encrypt(char* msg, char* key)
{
  int mesLen = strlen(msg);
  int keyLen = strlen(key);

  char temp_key[mesLen];
  char encMsg[mesLen];

  int i, j;

  for(i = 0, j = 0; i < mesLen; ++i, ++j)
  {
    if(j == keyLen)
    {
      j = 0;
    }
    temp_key[i] = key[j];
  }

  temp_key[i] = '\0';
  i = 0;
  

  while(i < mesLen)
  {
    encMsg[i] = ((msg[i] - 'a' + temp_key[i] - 'a') % 26) + 'a';
    i++;
  }
  encMsg[i] = '\0';


  char* newMsg = (char*)malloc(sizeof(char) * mesLen);
  strcpy(newMsg, encMsg);
  
  return newMsg;
}




int main(int argc, char* argv[]) // change main.c to pa01.c
{
  
  // Takes in command line arguements
  char* keyFile = argv[1];
  char* encryptFile = argv[2];

  FILE* infile = fopen(keyFile, "r"); // change k1.txt to keyFile
  FILE* infile2 = fopen(encryptFile, "r"); // change p1.txt to encryptFile

  char* inputKey = (char*)malloc(sizeof(char) * MAX_ARRAY_SIZE); // Viginere key
  char* inputMessage = (char*)malloc(sizeof(char) * MAX_CHAR_ARR); // plaintext
  char* cipherText = (char*)malloc(sizeof(char) * MAX_CHAR_ARR); // ciphertext
  
  inputKey = (char*)readKeyFile(infile);

  inputMessage = (char*)readMessageFile(infile2);
  while(strlen(inputMessage) < 512)
  {
    strcat(inputMessage, "x");
  }

  cipherText = (char*)encrypt(inputMessage, inputKey);

  fclose(infile);
  fclose(infile2);

  // Print statements
  printf("\n\nVigenere Key:\n");
  printString(inputKey, strlen(inputKey));

  printf("\n\n\nPlaintext:\n");
  printString(inputMessage, strlen(inputMessage));
  
  printf("\n\n\nCiphertext:\n");
  printString(cipherText, strlen(cipherText));
  
  // Frees Stuff
  free(inputKey);
  free(inputMessage);
  free(cipherText);
  
  return 0;
}




/*=============================================================================
| I Benjamin Giang be297303 affirm that this program is
| entirely my own work and that I have neither developed my code together with
| any another person, nor copied any code from any other person, nor permitted
| my code to be copied or otherwise used by any other person, nor have I
| copied, modified, or otherwise used programs created by others. I acknowledge
| that any violation of the above terms will be treated as academic dishonesty.
+=============================================================================*/