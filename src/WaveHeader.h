/*
*   
*/
#ifndef __WAVE_HEADER_H__
#define __WAVE_HEADER_H__

struct WAVE
{
    struct HEADER
    {
        char            fccID[4];
        unsigned int    dwSize;
        char            fccType[4];
    } header;

    struct FMT
    {
        char            fccID[4]; 
        unsigned int    dwSize;
        unsigned short  wFormatTag;
        unsigned short  wChannels;
        unsigned int    dwSamplesPerSec;
        unsigned int    dwAvgBytesPerSec;
        unsigned short  wBlockAlign;
        unsigned short  uiBitsPerSample;
    } fmt;
    
    struct DATA
    {
        char            fccID[4];
        unsigned int    dwSize;
    } data;  
};

typedef struct WAVE WAVE;

void WAVE_Init(WAVE *wav, int nAudioSize, int nSampleRate, int nChannel, int uiBitsPerSample);
void WAVE_DeInit(WAVE *wav);
void WAVE_Print(WAVE *wav);

#endif //!__WAVE_HEADER_H__
