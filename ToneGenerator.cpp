//
// Created by Lukas Weber on 28.12.16.
//

#include "ToneGenerator.h"
#include "MelodyReader.h"
#include <fstream>
#include <iostream>

ToneGenerator::ToneGenerator() : sampleRate(SAMPLE_RATE) {}

void ToneGenerator::GenerateRandomTones()
{
    //tones.push_back(Tone(261.626,sampleRate, 1));
    tones.push_back(Tone(sampleRate, 261.626, 0.5));
    tones.push_back(Tone(sampleRate, 293.66, 0.5));
    tones.push_back(Tone(sampleRate, 329.63, 0.5));
    tones.push_back(Tone(sampleRate, 349.23, 0.5));
    tones.push_back(Tone(sampleRate, 392.00, 0.5));
    tones.push_back(Tone(sampleRate, 0, 0.5));
    tones.push_back(Tone(sampleRate, 392.00, 0.5));
    GetByteStream();
}

std::vector<int16_t> ToneGenerator::GetByteStream()
{
    std::vector<int16_t> byteStreamOut;

    //resize the binary output vector to the count of the total smaples
    byteStreamOut.reserve(GetTotalSamples());

    //get the binary for each tone and merge together
    for(auto& tone : tones)
    {
        tone.WriteTone(byteStreamOut);
    }

    return byteStreamOut;
}

uint32_t ToneGenerator::GetTotalSamples()
{
    uint32_t totalSamples = 0;
    for(auto & tone : tones)
    {
        totalSamples += tone.GetTotalSamples();
    }
    return totalSamples;
}

WavFile* ToneGenerator::SaveAsWavFile(std::string pFileName)
{
    std::vector<int16_t> soundData = GetByteStream();
    WavFile* pFile = new WavFile(pFileName, SAMPLE_RATE, soundData);
    pFile->WriteFile();
    return pFile;
}

void ToneGenerator::ReadMelodyFromFile(std::string fileName)
{
    MelodyReader reader;
    reader.WriteMelody(fileName, this->tones);
}

