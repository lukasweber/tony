//
// Created by Lukas Weber on 28.12.16.
//

#ifndef TONY_TONEGENERATOR_H
#define TONY_TONEGENERATOR_H


#include <vector>
#include <list>
#include "Tone.h"
#include "WavFile.h"

#define SAMPLE_RATE 44100


class ToneGenerator
{
private:
    double sampleRate;
    std::list<Tone> tones;
public:
    ToneGenerator();
    void GenerateRandomTones();
    uint32_t GetTotalSamples();
    void ReadMelodyFromFile(std::string fileName);
    std::vector<int16_t> GetByteStream();
    WavFile * SaveAsWavFile(std::string fileName);
};


#endif //TONY_TONEGENERATOR_H
