//
// Created by Lukas Weber on 28.12.16.
//

#include <fstream>
#include "WavFile.h"
#include <cstdint>

WavFile::WavFile(std::string pFileName, double pSampleRate, std::vector<int16_t> &pSoundData)
        :  name(pFileName), sampleRate(pSampleRate), soundData(pSoundData)
{
    //init new byte stream
    fileStream = std::ofstream(pFileName, std::ios::binary);
}

void WavFile::WriteFileHeader()
{
    //ensure that the write-position is at the beginning
    if(fileStream.tellp() == 0)
    {
        fileStream << "RIFF";                                    //ChunkID
        WriteToStream(uint32_t(36 + (soundData.size() * 2)));    //ChunkSize (Header Size + SoundData-Bytes)
        fileStream << "WAVE";                                    //RIFF-Type

        fileStream << "fmt ";                                    //Subchunk1-ID = Format-Chunk
        WriteToStream(uint32_t(16));                             //No extension data
        WriteToStream(uint16_t(1));                              //FORMAT = PCM (0x0001)
        WriteToStream(uint16_t(1));                              //Channels = 1 = MONO
        WriteToStream(uint32_t(sampleRate));                     //SampleRate
        WriteToStream(uint32_t((sampleRate * 16 * 1) / 8));      //ByteRate = (SampleRate * BitsPerSample * Channels) / 8
        WriteToStream(uint16_t(2));                              //Data Block-Size
        WriteToStream(uint16_t(16));                             //BitsPerSample

        fileStream << "data";                                    //Subchunk2-ID = Data-Chunk
        WriteToStream(uint32_t(soundData.size() * 2));           //DataChunk-Size = SoundData-Bytes
    }
    else
    {
        throw "Error on writing header: write-position has to be at the beginning!";
    }
}

void WavFile::WriteFileData()
{
    //ensure that the write position is at the end of the wave-header
    if(fileStream.tellp() == 44)
    {
        for(auto & data : soundData)
        {
            WriteToStream(data, 2);
        }
    }
    else
    {
        throw "Error on writing header: write-position has to be at the end of the wave header!";
    }

}

void WavFile::WriteFile()
{
    WriteFileHeader();
    WriteFileData();
}

const std::string WavFile::GetFileName()
{
    return name;
}



