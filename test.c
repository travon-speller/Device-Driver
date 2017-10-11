#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

#define BUFFER_LENGTH 256               ///< The buffer length (crude but fine)
static char receive[BUFFER_LENGTH];     ///< The receive buffer from the LKM

int main(){
   int ret, fd;
   char stringToSend[BUFFER_LENGTH];
   char choice = ' ';

   printf("Starting device test code example...\n");
   fd = open("/dev/mailbox", O_RDWR);             // Open the device with read/write access
   if (fd < 0){
      perror("Failed to open the device...");
      return errno;
   }

   do{
      printf("Would you like to read (r || R), Write (w || W), or quit (q || Q)\n");
      choice = getchar();
      getchar();
      switch(choice)
      {
         case 'w':
               printf("Type in a short string to send to the kernel module:\n");
               scanf("%[^\n]%*c", stringToSend);                // Read in a string (with spaces)
               printf("Writing message to the device [%s].\n", stringToSend);
               ret = write(fd, stringToSend, strlen(stringToSend)); // Send the string to the LKM
               if (ret < 0){
                  perror("Failed to write the message to the device.");
                  return errno;
               }
               break;
         case 'W':
               printf("Type in a short string to send to the kernel module:\n");
               scanf("%[^\n]%*c", stringToSend);                // Read in a string (with spaces)
               printf("Writing message to the device [%s].\n", stringToSend);
               ret = write(fd, stringToSend, strlen(stringToSend)); // Send the string to the LKM
               if (ret < 0){
                  perror("Failed to write the message to the device.");
                  return errno;
               }
               break;
         case 'r':
               printf("Press ENTER to read back from the device...\n");
               getchar();

               printf("Reading from the device...\n");
               ret = read(fd, receive, BUFFER_LENGTH);        // Read the response from the LKM
               if (ret < 0){
                  perror("Failed to read the message from the device.");
                  return errno;
               }
               printf("The received message is: %s\n", receive);
               break;
         case 'R':
               printf("Press ENTER to read back from the device...\n");
               getchar();

               printf("Reading from the device...\n");
               ret = read(fd, receive, BUFFER_LENGTH);        // Read the response from the LKM
               if (ret < 0){
                  perror("Failed to read the message from the device.");
                  return errno;
               }
               printf("The received message is: %s\n", receive);
               break;
         case 'q':
               printf("Quit program\n");
               break;
         case 'Q':
               printf("Quit program\n");
               break;
         default:
               printf("End of the program\n");
               break;
      }
   }while(choice != 'q' || choice != 'Q');
   return 0;
}