cmake_minimum_required(VERSION 3.6)
project(tony)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp ToneGenerator.cpp ToneGenerator.h Tone.cpp Tone.h WavFile.cpp WavFile.h)
add_executable(tony ${SOURCE_FILES})