#include "syscall.h"
#define MAX_LENGTH 255

int main() 
{
    int fileID;
    int len;
    char fileName[32];
    char s[1024];

    PrintString("Input file to cat: ");
    ReadString(fileName, MAX_LENGTH);
    
    fileID = Open(fileName, 1);
   // PrintNum(fileID);
   // PrintString("\n");
    if (fileID != -1) 
    {
         len = Seek(-1, fileID);
        // PrintNum(len);
        Close(fileID);
        //PrintString("abbds\n");
        fileID = Open(fileName, 1);
         Seek(0, fileID);
        //PrintNum(fileID);
        //PrintString("abs");
        Read(s, len + 1, fileID);
        //PrintString("xyz");
         //PrintNum(len);
         //Close(fileID);
        // // PrintNum(len);
        // // PrintString("Da dong file\n");
        //  fileID = Open(fileName, 0);
        //  PrintNum(fileID);
        //  Seek(0, fileID);
        //  //PrintString("Da seek\n");
        //  Read(s, len, fileID);
        //PrintString(s);
        Close(fileID);
        
        PrintString("\nFile content: \n");
        PrintString(s);
    }
    else
        PrintString("Cannot open file to read!");
    Halt();
}
