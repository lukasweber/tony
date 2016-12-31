# Tony

## Who's Tony?
Tony can play very simple melodies which you give him :)
So, you could write a simple file with a melody and he's creating a wave-file for you.

This project is just for fun to get a little bit into audio-programming.

## Installation
Just clone from git and call make.
```
git clone https://github.com/devlukas/tony
cd tony
make
```

## Usage
Create a new Textfile with your melody inside.
For example try this:
```
echo "C4;D4;E4;F4;G4;--;G4;--;A4;A4;A4;A4;G4;--;A4;A4;A4;A4;G4;--;F4;F4;F4;F4;E4;--;E4;--;D4;D4;D4;D4;C4;" >> melody1
```
And now generate the wave-file and listen to it :)
```
./tony melody1 && aplay output.wav
```
