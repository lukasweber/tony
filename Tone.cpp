//
// Created by Lukas Weber on 28.12.16.
//

#include <cmath>
#include "Tone.h"
#include <iostream>

Tone::Tone(double pSampleRate, double pFrequency, double pLength)
        :  sampleRate(pSampleRate), frequency(pFrequency), length(pLength)
{
    //TODO Make this setable
    amplitude = 20000;
}

void Tone::WriteTone(std::vector<int16_t> &buffer)
{
    //get the total number of samples for this tone
    const uint32_t totalSamples = GetTotalSamples();

    //calculate the pulsatance
    //const double w =  ;

    //generate all samples for this tone and add them to the buffer
    for(int32_t t = 0; t < totalSamples; t++)
    {
        const int16_t sample = (int16_t) (sin((2 * M_PI * frequency * t) / sampleRate) * amplitude);
        buffer.push_back(sample);
    }
}

uint32_t Tone::GetTotalSamples()
{
    //calculate the total number of samples for this tone
    return (uint32_t) (sampleRate * length);
}

