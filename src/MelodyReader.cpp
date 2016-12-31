//
// Created by Lukas Weber on 30.12.16.
//

#include <algorithm>
#include "MelodyReader.h"
#include "ToneGenerator.h"
#include <sstream>
#include <fstream>

namespace string_split
{
    void split(const std::string &s, char delim, std::vector<std::string> &elems)
    {
        std::stringstream ss;
        ss.str(s);
        std::string item;
        while (std::getline(ss, item, delim)) {
            elems.push_back(item);
        }
    }

    std::vector<std::string> split(const std::string &s, char delim)
    {
        std::vector<std::string> elems;
        split(s, delim, elems);
        return elems;
    }
}

void MelodyReader::WriteMelody(std::string filename, std::list<Tone> & tones)
{
    using namespace string_split;

    //Read the textfile to a string
    std::ifstream t(filename);
    std::stringstream buffer;
    buffer << t.rdbuf();
    std::string melodyText = buffer.str();

    //split the string by ;
    std::vector<std::string> melodySplit = split(melodyText, ';');

    for(auto & tone : melodySplit)
    {
        double frequency = GetFrequencyByTone(tone);
        tones.push_back(Tone(SAMPLE_RATE, frequency, 0.4));
    }
}

double MelodyReader::GetFrequencyByTone(std::string toneName)
{
    //convert string to uppercase
    std::transform(toneName.begin(), toneName.end(),toneName.begin(), ::toupper);

    //search the tone inside the vector
    auto index = std::find(TONE_NAMES.begin(), TONE_NAMES.end(), toneName);

    //calculate the position of the tone
    long position = index - TONE_NAMES.begin();

    if(position > 0 && index != TONE_NAMES.cend())
    {
        return 440.0 * pow(pow(2.0, 1.0/12.0),position - 48.0);
    }
    return 0;
}


