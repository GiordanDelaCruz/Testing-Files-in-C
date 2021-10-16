#include <stdio.h>
#include<string.h>
#include<sys/stat.h>

// Declare functions
void readFile( char* array, int sizeOfArr );
 int checkIfFileExists(const char* filename);

// Main function
int main(){

  // Declare variables
  char fileName[50];

  // Get file name from User
  printf("Please enter the name of the file you would like to open.\n");
  fgets(fileName, 50, stdin);

  // Remove the "\n" character created from the standard input (stdin)
  fileName[strcspn(fileName, "\n")] = 0;

  // Determine if file exists
    if( checkIfFileExists( strcat(fileName, ".txt") ) )
  {
      printf("The name of the file you have entered is %s\n", fileName);
      printf("file exists\n\n");

      // Read file contents
      printf("The context in your file is:\n");
      readFile( fileName, 50);
  }
  else
  {
      printf("file does not exists");
  }


  return 0;
}

/** This function will open a file and print out the contents inside the file.
 *
 *  @param array                        Pointer to the address of the first element of the array
 *  @param sizeOfArr                    Size of the array
 */
 void readFile( char* array, int sizeOfArr ){

   // Declare variables & File Pointer
   char fName[sizeOfArr];
   char buf[0x100];
   FILE *fpointer;

   // Read the file name sent from the parameters
   for(int i=0; i < sizeOfArr; i++){

     fName[i] = array[i];

   }

   // Remove the "\n" character created from the standard input (stdin)
   fName[strcspn(fName, "\n")] = 0;

   /** Read the file
    *  Note: In order to pass the file name as a argument to the fopen() function, a buffer was used
    */
    snprintf(buf, sizeof(buf), "%s", fName);
    FILE *fPointer = fopen(buf, "r");

    // Declare a variable to store the data in the file
    char singleLine[150];

   /** [ OPTIONAL CODE ] Write contents in file
    *
    *   fprintf( fPointer, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nunc nisi libero, eleifend a ex nec, ultricies rutrum mi justo.");
    */

   // Print out all the text inside the file
   while( !feof(fPointer) ){

     // Read a line from the file
     fgets(singleLine, 150, fPointer);

     // Put the data into the terminal
     puts(singleLine);
   }

   // Terminate the file pointer to return resources
   fclose(fPointer);
 }

 /** This function will check if a file exists
  *
  *  @param fileName          Name of file
  */
 int checkIfFileExists(const char* filename){
     struct stat buffer;
     int exist = stat(filename,&buffer);
     if(exist == 0)
         return 1;
     else
         return 0;
 }
