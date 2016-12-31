#include <iostream>
#include "ToneGenerator.h"
#include "WavFile.h"
#include "MelodyReader.h"

int main()
{
    std::cout << "TONY Alpha v0.0.1" << std::endl;

    //just to test :)
    ToneGenerator generator;
    generator.ReadMelodyFromFile("melody1");

    WavFile* pFile = generator.SaveAsWavFile("test.wav");

    std::cout << "File: " << pFile->GetFileName() << std::endl;

    delete pFile;

    return 0;
}