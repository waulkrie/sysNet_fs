#ifndef DISK_H_
#define DISK_H_

/**
 * Simulates a physical disk. The disk reads and writes blocks of data.
 * 
 * @author Thomas Reichherzer
 */

//defines 
/** The size of a block on disk in bytes */
#define BLOCK_SIZE 1024

#include <string>
#include <iostream>

using namespace std;

class Disk {
	
	int   _sizeInKB;      // the size of the disk in KB
	FILE* _physicalDisk;  // the file that implements the disk
	
	public:
		Disk( int sizeInKB, const string& path );
		
		int readBlock( int blockNumber, char* blockData );
		int writeBlock( int blockNumber, const char* blockData, int numberOfBytes  );
		int getSize();
};


#endif /*DISK_H_*/
