/*=============================================================================
| Assignment: pa02 - Calculating an 8, 16, or 32 bit
| checksum on an ASCII input file
|
| Author: Benjamin Giang
| Language: c, c++, Java
|
| To Compile: javac pa02.java
| gcc -o pa02 pa02.c
| g++ -o pa02 pa02.cpp
|
| To Execute: java -> java pa02 inputFile.txt 8
| or c++ -> ./pa02 inputFile.txt 8
| or c -> ./pa02 inputFile.txt 8
| where inputFile.txt is an ASCII input file
| and the number 8 could also be 16 or 32
| which are the valid checksum sizes, all
| other values are rejected with an error message
| and program termination
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

int main(int argc, char* argv[])
{
  // Takes in command line arguements
  char* inputFile = argv[1];
  char* checksumSize = argv[2];

  FILE* infile = fopen("i1.txt", "r"); // change i10A to inputFile
  int checksumBits = atoi(checksumSize); // in bits

  checksumBits = 8; // delete

  char inputString[3000];
  unsigned long int res8bit = 0;
  unsigned long int res16bit = 0;
  unsigned long int res32bit = 0;
  
  unsigned long checksum = 0; // %lx type unsigned long in hexadecimal
  int characterCnt = 0;


  // checks if checksumSize is valid
  if(checksumBits != 8 && checksumBits != 16 && checksumBits != 32)
  {
    fprintf(stderr, "Valid checksum sizes are 8, 16, or 32\n");
    return 0;

  } else
  {

    // Readfile
    int i = 0;
    char ch;

    while (fscanf(infile, "%c", &ch) != EOF)
    {
      // printf("%c", ch);
      inputString[i] = ch;
      i++;
    }
    inputString[i] = '\0';

    fclose(infile);



    switch (checksum_size)
  {
    case 8:
    res8bit = calc8bit(inputString);
    print80(input);
    printf("\n");
    // Use 0xff masking to display only last 2 hex values
    printf("%2d bit checksum is %8lx for all %4d chars\n", checksum_size, res8bit & 0xff, (int)strlen(input));
    break;
  case 16:
    // Pad with a necessary X
    if (strlen(input) % 2)
    strcat(input,"X");
    print80(input);
    printf("\n");
    res16bit = calc16bit(input);
    // Use 0xffff masking to display only last 4 hex values
    printf("%2d bit checksum is %8lx for all %4d chars\n", checksum_size, res16bit & 0xffff, (int)strlen(input));
    break;
  case 32:
    // Pad with necessary X's
    while (strlen(input) % 4)
    strcat(input,"X");
    print80(input);
    printf("\n");
    res32bit = calc32bit(input);
    // Use 0xffffffff masking to display only last 8 hex values
    printf("%2d bit checksum is %8lx for all %4d chars\n", checksum_size, res32bit & 0xffffffff, (int)strlen(input));
    break;
  }

  }



  // Prints
  printf("\n");
  printString(inputString, strlen(inputString));
  printf("%2d bit checksum is %8lx for all %4d chars\n", checksumBits, checksum, characterCnt);






  return 0;
}

/*=============================================================================
| I Benjamin Giang (be297303) affirm that this program is
| entirely my own work and that I have neither developed my code together with
| any another person, nor copied any code from any other person, nor permitted
| my code to be copied or otherwise used by any other person, nor have I
| copied, modified, or otherwise used programs created by others. I acknowledge
| that any violation of the above terms will be treated as academic dishonesty.
+=============================================================================*/