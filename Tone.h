//
// Created by lukas on 28.12.16.
//

#ifndef TONY_TONE_H
#define TONY_TONE_H


#include <vector>
#include <cstdint>

class Tone {
private:
    double frequenzy;
    double sampleRate;
public:
    Tone(double sampleRate, double frequenzy);
    void WriteTone(std::vector<uint32_t> &buffer);
};


#endif //TONY_TONE_H
