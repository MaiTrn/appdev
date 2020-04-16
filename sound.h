//In this file we define related constants and declare functions
//for handing sound.

//define sound struct (deal with .wav file)
typedef struct {
	char chunkID[4];		//should always be "RIFF"
	int chunkSize;
	char format[4];			//should always be "WAVE"
	char subchunk1ID[4]; 	//should always be "fmt "
	int subchunk1Size;		//should be 16 for PCM
	short audioFormat;		//should be 1 for PCM
	short numChannels;		//could be 1 for mono, 2 for stereo
	int sampleRate;			//usually is 44100, or 16000
	int byteRate;		//calculated as: sampleRate*numChannels*bitsperSample/8
	short blockAlign;		//how many bytes in 1 block
	short bitsperSample;	//could be 8 or 16
	char subchunk2ID[4];	//should be always "data"
	int subchunk2Size;		//can be calculated
}WAVheader;

//function declarations
WAVheader readwavhdr(FILE *fp);
void displaywavhdr(WAVheader h);
