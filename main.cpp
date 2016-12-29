#include <iostream>
#include "ToneGenerator.h"
#include "WavFile.h"

int main()
{
    std::cout << "TONY" << std::endl;
    ToneGenerator generator;
    generator.GenerateRandomTones();

    std::vector<int16_t> soundData = generator.GetByteStream();
    WavFile file("test.wav", 44100, soundData);

    file.WriteFile();
    return 0;
}