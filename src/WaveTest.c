#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "WaveHeader.h"

int main() {
    int size = 0, audio_size = 0;
    char buf[1024] = {0};
    FILE *in = NULL,*out = NULL;
    WAVE wav;

    in = fopen("../data/one-8kHz.pcm", "rb");
    assert(in);
    fseek(in, 0, SEEK_END); //定位到文件末 
	audio_size = ftell(in); //文件长度
    printf("audio size : %d\n", audio_size);

    WAVE_Init(&wav, audio_size, 8000, 1, 16);
    printf("%ld\n", sizeof(wav));
    WAVE_Print(&wav);

    
    out = fopen("../data/one-8kHz.wav", "wb");
    assert(in);

    size = fwrite(&wav, 1, sizeof(wav), out);
    printf("write wave header : %d\n", size);
    fflush(out);
    assert(size > 0);

    fseek(in, 0, SEEK_SET);
    while (1) {
        size = fread(buf, 1, sizeof(buf), in);
        printf("read    data : %d\n", size);
        if (size > 0 && size != EOF) {
            size = fwrite(buf, 1, size, out);
            printf("write   data : %d\n", size);
            fflush(out);
        } else {
            break;
        }
    }

    fclose(in);
    fclose(out);
    WAVE_DeInit(&wav);
}