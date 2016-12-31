#include <iostream>
#include "ToneGenerator.h"
#include "WavFile.h"
#include "MelodyReader.h"

int main(int argc, char* argv[])
{
    std::cout << "TONY Alpha v0.0.1" << std::endl;

    if(argc == 2)
    {
        ToneGenerator generator;
        generator.ReadMelodyFromFile(argv[1]);

        WavFile* pFile = generator.SaveAsWavFile("output.wav");

        std::cout << "File: " << pFile->GetFileName() << std::endl;

        delete pFile;
    }
    else
    {
        std::cout << "Wrong command! please use like: \"tony melody1\"" << std::endl;
    }

    return 0;
}