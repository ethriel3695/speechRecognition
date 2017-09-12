#include <iostream>
#include <fstream>
using namespace std;

int main () {

    fstream ifs("E:/src/Github/speechTranslation/goodbye.wav", ios_base::in);

    if(ifs.is_open())
    {
        //char * First_Chunk_ID = new char;
        //ifs.read(First_Chunk_ID, 4);

        char First_Chunk_ID[5] = ""; //an array of 5 chars. 4 for the ID and 1 extra to put a null terminator at the end
        ifs.read(First_Chunk_ID, 4);

        //char * charArray_File_Size = new char;
        //ifs.read(charArray_File_Size, sizeof(long));
        //long File_Size = atol(charArray_File_Size);

        long File_Size;  //no need for this to ba char array. The data is stored in binary.
        ifs.read(reinterpret_cast<char*>(&File_Size), sizeof(long));

        //...

        //char * Data = new char;
        //ifs.get(Data, 10000);

        char Data[10000]; //if you want to read 10000 chars, make a buffer of 10000 chars
        ifs.read(Data, 10000); //use read(), not get(). Everything in the file is binary

        cout << "First_Chunk_ID : " << First_Chunk_ID << endl
        << "charArray_File_Size : " << charArray_File_Size << endl
        << "File_Size : " << File_Size << endl
        << "Form_Type_ID : " << Form_Type_ID << endl
        << "Second_Chunk_ID : " << Second_Chunk_ID << endl
        << "charArray_Wave_Format_Size : " << CharArray_Wave_Format_Size << endl
        << "Wave_Format_Size : " << Wave_Format_Size << endl
        << "Wave_Format_Info : " << Wave_Format_Info << endl
        << "Third_Chunk_ID : " << Third_Chunk_ID << endl
        << "charArray_Data_Size : " << charArray_Data_Size << endl
        << "Data_Size : " << Data_Size << endl
        << "Data : " << Data << endl
        << "Data gcount : " << ifs.gcount() << endl << endl;

    }
}