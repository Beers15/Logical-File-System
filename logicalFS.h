#ifndef LOGICALFS_H
#define LOGICALFS_H

#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include "entry.h"
#include "volumeEntry.h"
#include "fsLow.h"

#define AVGDIRENTRIES 100
#define ENTRYFLAG_DIR 0
#define ENTRYFLAG_FILE 1
#define ENTRYFLAG_UNUSED 2

void initRoot(uint64_t position, uint64_t blockSize, entry entries[], entry* entryList, uint64_t rootDirBlocks, uint64_t numDirEntries);
void init(volumeEntry* vcb, char* bitMapBuf, entry entries[], entry* entryList, uint64_t volumeSize, uint64_t blockSize, uint64_t lbaCount, char* fileName, uint64_t rootDirBlocks, uint64_t numDirEntries);
void* readFromVolume(char fileName[], entry* entryList, uint64_t numDirEntries, int currentDirIndex, uint64_t blockSize);
int writeToVolume(void* buffer, char fileName[], uint64_t fileSize, int currentDirIndex, uint16_t type, entry* entryList, char* bitMap, uint64_t blockSize, uint64_t lbaCount);
int writeDirectoryToVolume(char dirName[], int currentDirIndex, uint16_t type, entry* entryList, char* bitMap, uint64_t blockSize, uint64_t lbaCount);
int deleteFromVolume(int fileIndex, entry* entryList, char* bitMap, uint64_t blockSize, uint64_t lbaCount);
int deleteDirectoryFromVolume(int directoryIndex, entry* entryList, char* bitMap, uint64_t blockSize, uint64_t lbaCount);

#endif