cmake_minimum_required(VERSION 3.5.1)
project(tony)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main.cpp src/ToneGenerator.cpp src/ToneGenerator.h src/Tone.cpp src/Tone.h src/WavFile.cpp src/WavFile.h src/MelodyReader.cpp src/MelodyReader.h)
add_executable(tony ${SOURCE_FILES})