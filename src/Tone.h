//
// Created by Lukas Weber on 28.12.16.
//

#ifndef TONY_TONE_H
#define TONY_TONE_H


#include <vector>
#include <cstdint>

class Tone
{
private:
    double frequency;
    double sampleRate;
    double length;
    double amplitude;
public:
    Tone(double pSampleRate, double pFrequency, double pLength);
    uint32_t GetTotalSamples();
    void WriteTone(std::vector<int16_t> &buffer);
};


#endif //TONY_TONE_H
