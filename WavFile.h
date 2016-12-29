//
// Created by Lukas Weber on 28.12.16.
//

#ifndef TONY_WAVFILE_H
#define TONY_WAVFILE_H


#include <fstream>
#include <vector>

class WavFile
{
private:
    double sampleRate;

    std::ofstream fileStream;
    std::string name;
    std::vector<int16_t> & soundData;

    void WriteFileHeader();
    void WriteFileData();

    template <typename T>
    void WriteToStream(T value, unsigned size = sizeof(T))
    {
//        for (; size; --size, value >>= 8)
//            fileStream.put( static_cast <char> (value & 0xFF) );
        fileStream.write(reinterpret_cast<const char *>(&value), size);
    }
public:
    WavFile(std::string pFileName, double pSampleRate, std::vector<int16_t> & pSoundData);
    void WriteFile();
    const std::string GetFileName();
};


#endif //TONY_WAVFILE_H
