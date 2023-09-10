#include "audio_sd.h"
#include <stdio.h>
#include "fatfs.h"

static FRESULT sd_result;
static FATFS sdCard;

static FIL testFile;

void sd_card_init() {
	uint8_t file_name[] = "test.txt";
	uint8_t temp_number;
	uint8_t test_text[] = "hello world there";

	sd_result = f_mount(&sdCard, SDPath, 1);
	if (sd_result != 0){
		printf("error in mounting an sd card: %d\n", sd_result);
//		while (1);
	}
	else {
		printf("succeeded in mounting the SD card\n");
	}

	sd_result = f_open(&testFile, (void*)file_name, FA_WRITE|FA_CREATE_ALWAYS);
	if (sd_result != 0) {
		printf("error in creating a file: %d \n", sd_result);
//		while(1);
	}
	else {
		printf("succeeded in opening a file\n");
	}

	sd_result = f_write(&testFile, (void*)test_text, (UINT)sizeof(test_text), (UINT*)&temp_number);
	if(sd_result != 0){
		printf("error in writing to the file: %d\n", sd_result);
//		while (1);
	}
	else {
		printf("succeeded in writing to the file\n");
	}

	f_close(&testFile);

}
