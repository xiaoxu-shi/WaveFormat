#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "WaveHeader.h"

void WAVE_Init(WAVE *wav, int nAudioSize, int nSampleRate, int nChannel, int uiBitsPerSample) {
    wav->header.fccID[0] = 'R';
    wav->header.fccID[1] = 'I';
    wav->header.fccID[2] = 'F';
    wav->header.fccID[3] = 'F';
    wav->header.dwSize = nAudioSize + (sizeof(struct WAVE) - sizeof(wav->header.fccID) - sizeof(wav->header.dwSize));
    wav->header.fccType[0] = 'W';
    wav->header.fccType[1] = 'A';
    wav->header.fccType[2] = 'V';
    wav->header.fccType[3] = 'E';
    
    wav->fmt.fccID[0] = 'f';
    wav->fmt.fccID[1] = 'm';
    wav->fmt.fccID[2] = 't';
    wav->fmt.fccID[3] = ' ';
    wav->fmt.dwSize = 16;
    wav->fmt.wFormatTag = 1;
    wav->fmt.wChannels = nChannel;
    wav->fmt.dwSamplesPerSec = nSampleRate;
    wav->fmt.dwAvgBytesPerSec = nSampleRate*nChannel*uiBitsPerSample/8;
    wav->fmt.wBlockAlign = nChannel*uiBitsPerSample/8;
    wav->fmt.uiBitsPerSample = uiBitsPerSample;


    wav->data.fccID[0] = 'd';
    wav->data.fccID[1] = 'a';
    wav->data.fccID[2] = 't';
    wav->data.fccID[3] = 'a';
    wav->data.dwSize = nAudioSize;
}

void WAVE_DeInit(WAVE *wav) {

}

void WAVE_Print(WAVE *wav) {
    assert(wav);
    printf("wav.header.fccID                : %.4s\n", wav->header.fccID);
    printf("wav.header.fccType              : %.4s\n", wav->header.fccType);
    printf("wav.header.dwSize               : %d\n", wav->header.dwSize);

    printf("wav->fmt.fccID                  : %.4s\n", wav->fmt.fccID);
    printf("wav->fmt.dwSize                 : %d\n", wav->fmt.dwSize);
    printf("wav->fmt.wFormatTag             : %d\n", wav->fmt.wFormatTag);
    printf("wav->fmt.wChannels              : %d\n", wav->fmt.wChannels);
    printf("wav->fmt.dwSamplesPerSec        : %d\n", wav->fmt.dwSamplesPerSec);
    printf("wav->fmt.dwAvgBytesPerSec       : %d\n", wav->fmt.dwAvgBytesPerSec);
    printf("wav->fmt.wBlockAlign            : %d\n", wav->fmt.wBlockAlign);
    printf("wav->fmt.uiBitsPerSample        : %d\n", wav->fmt.uiBitsPerSample);

    printf("wav.data.fccID                  : %.4s\n", wav->data.fccID);
    printf("wav.data.dwSize                 : %d\n", wav->data.dwSize);
}