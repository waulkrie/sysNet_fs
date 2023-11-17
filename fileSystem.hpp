#ifndef FILESYSTEM_H_
#define FILESYSTEM_H_

/**
 * Emulates a file system.
 *
 * @author Thomas Reichherzer
 */

#include <string>

#include "disk.hpp"
#include "inode.hpp"
#include "superBlock.hpp"

#define NUM_INODES 100 

using namespace std;

class FD {
	public:
		int inodeBlockNum;
		int fileptr;
};
	

class FileSystem
{
	Disk* _disk;
	FD*   _openFiles[NUM_INODES];
	
	
	public:
		void format( int diskSizeInKB, string& path );
		
		int closef(FD& stream);
		FD* openf(string& name);

		int readf(FD& stream, char* data, int size);
		int writef(FD& stream, char* data, int size);

		void printInodes();
		void printFreeBlocks();

	private:
		SuperBlock* readSuperBlock( );
		void writeSuperBlock(SuperBlock& superBlock );
		
		void readInode(Inode& inode, int blockNumber);
		void writeInode(Inode& inode, int blockNumber);
		
		void intToByteArray( int value, char* buffer, int pos );
		int byteArrayToInt( char* buffer, int pos );
};


#endif /*FILESYSTEM_H_*/