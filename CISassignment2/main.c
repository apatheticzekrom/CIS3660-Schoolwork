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

// Calculate 8 bit checksum
unsigned long int checksum8bit(char *input)
{
  int result = 0;
  for (int i = 0; i < strlen(input); i++)
  {
    result += input[i];
  }

  return result;
}

// Calculate 16 bit checksum
unsigned long int checksum16bit(char *input)
{
  int result = 0;
  for (int i = 0; i < strlen(input);)
  {
    result += input[i] << 8;
    result += (input[i + 1]);
    i+=2;
  }

  return result;
}

// Calculate 32 bit checksum
unsigned long int checksum32bit(char *input)
{
  unsigned long int result = 0;
  for (int i = 0; i < strlen(input);)
  {
    result += input[i] << 24;
    result += (input[i + 1]) << 16;
    result += (input[i + 2]) << 8;
    result += (input[i + 3]);
    i+=4;
  }
  
  return result;
}

// Print function, prints 80 char per line
void printString(char *str)
{
  for (int i = 0; i < strlen(str); i++)
  {
    if (i % 80 == 0)
    printf("\n");
    printf("%c", str[i]);
  }
}


int main(int argc, char **argv)
{
  // Takes in command line arguements and check them
  char* inputFile = argv[1];
  char* checksumsize = argv[2];
  int checksumBits = atoi(checksumsize);

  // Checks if checksumsize is valid
  if(checksumBits != 8 && checksumBits != 16 && checksumBits != 32)
  {
    fprintf(stderr, "Valid checksum sizes are 8, 16, or 32\n");
    return -1;
  }

  // Opening and reading the input file
  FILE *inputfile = fopen(inputFile,"r"); // change name to inputFile
  
  char *input = malloc(sizeof(char) * 1024);
  char ch = 'x';
  int i = 0;

  while (fscanf(inputfile, "%c", &ch) != EOF)
  {
    input[i] = ch;
    i++;
  }
  input[i] = '\0';

  fclose(inputfile);


  // Checksum stuff
  unsigned long int result = 0;

  if(checksumBits == 8)
  {
    result = checksum8bit(input);
    printString(input);
    printf("\n");

    printf("%2d bit checksum is %8lx for all %4d chars\n", checksumBits, result & 0xff, (int)strlen(input));
  
  } else if(checksumBits == 16)
  {
      if (strlen(input) % 2)
      {
        strcat(input,"X");
      }
      printString(input);
      printf("\n");
      result = checksum16bit(input);
      printf("%2d bit checksum is %8lx for all %4d chars\n", checksumBits, result & 0xffff, (int)strlen(input));

  } else if(checksumBits == 32)
  {
      while (strlen(input) % 4)
      {
        strcat(input,"X");
      }
      printString(input);
      printf("\n");
      result = checksum32bit(input);
      printf("%2d bit checksum is %8lx for all %4d chars\n", checksumBits, result & 0xffffffff, (int)strlen(input));
  }
  
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