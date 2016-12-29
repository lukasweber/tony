#include <iostream>
#include "ToneGenerator.h"
#include "WavFile.h"

int main()
{
    std::cout << "TONY Alpha v0.0.1" << std::endl;

    //just to test :)
    ToneGenerator generator;
    generator.GenerateRandomTones();
    WavFile* pFile = generator.SaveAsWavFile("test.wav");

    std::cout << "File: " << pFile->GetFileName() << std::endl;

    return 0;
}