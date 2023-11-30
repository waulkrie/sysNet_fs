/**
 * Emulates a file system.
 *
 * @author Thomas Reichherzer
 */

#include <stdexcept>
#include <iostream>
#include <cstring>


 
#include "fileSystem.hpp"
#include "inode.hpp"

/**
 * Formats the disk.
 *
 * @param diskSizeInKB - the size of the disk in KB
 * @param path - the path of the virtual disk
 *
 * @throw exception if the disk cannot be created or formatted
 */
void FileSystem::format( int diskSizeInKB, string& path )
{
    // create a disk; any exception will be returned to the caller
	_disk = new Disk(diskSizeInKB, path);
    //      FD*   _openFiles[NUM_INODES];
	SuperBlock* sb = new SuperBlock(diskSizeInKB-1, NUM_INODES-1, 1);
	writeSuperBlock(*sb);
	
	
    // complete implementation of this function
    // you must use the functions read/writeSuperblock() & read/writeInode()
	// formatting requires that you setup the superblock, write empty inodes,
	// and setup your free list for the remaining blocks
		    
}

/**
 * Opens a file by the specified name and returns a file descriptor.
 * 
 * @param name - the name of the file to be opened
 *
 * @returns a file descriptor if the file was successfully opened or NULL, if an error occurred
 */
FD* FileSystem::openf(string& name)
{
	return NULL;
}

/**
 * Closes the file given the file descriptor.
 * 
 * @throw exception if an error occurred closing the file
 */
int FileSystem::closef(FD& stream)
{

	return -1;
}

/**
 * Reads data from a file stream and stores them at the specified location.
 * 
 * @param stream - the file stream to be read
 * @param data - the buffer to store data in
 * @param size - the number of bytes to be read
 * 
 * @throw exception if an error occurred reading from the file
 */
int FileSystem::readf(FD& stream, char* data, int size)
{
	return -1;
}

/**
 * Writes data to a file stream given a file descriptor and data to be written.
 * 
 * @param stream - the file stream to append data
 * @param data - the buffer with data to be written to a file
 * @param size - the number of bytes to be written
 *
 * @throw exception if an error occurred writing to the file
 */
int FileSystem::writef(FD& stream, char* data, int size)
{
	return -1;
}
	 
/**
 * Reads the super block from disk.
 *
 * @return the superBlock from disk
 */
SuperBlock* FileSystem::readSuperBlock( )
{
	char buffer[BLOCK_SIZE];

    // read block and convert it to the superblock
	try {
		_disk->readBlock(0, buffer);
	}
	catch (exception& e) {
		throw runtime_error ("unable to read superblock from disk");
	}
		  
	// read number of disk blocks from block
	int numDiskBlocks = byteArrayToInt(buffer, 0 );
		  
	// read number of inodes from block
	int numInodes =  byteArrayToInt(buffer, 4 );
		  
	// read start of free block to disk
		  		  
	// finish implementing this function 

	return NULL;
}

/**
 * Writes the super block to disk.
 *
 * @param superBlock - the super block to be written to disk
 */
void FileSystem::writeSuperBlock(SuperBlock& superBlock )
{
	// setup buffer to be written to disk
	char buffer[BLOCK_SIZE] = {0};
			
	// write number of disk blocks into buffer
	intToByteArray( superBlock.getNumberOfDiskBlocks(), buffer, 0);
			
	// write number of inodes into buffer
	intToByteArray(superBlock.getNumberOfInodes(), buffer, 4);

	// finish this function
	/**
	 * The superblock is the first block (block 0) on the disk. It contains information
	 *  about the number of blocks on the file system, the number of i-nodes,
	 *  and the index of the first block in the free list.
	 *  The list of i-node blocks following the superblock is needed to implement files. 
	*/
	// write first free block to disk
	intToByteArray(superBlock.getFirstBlockFreeList(), buffer, 8);
	int blocks = superBlock.getNumberOfDiskBlocks();

	// write the superblock to disk
	_disk->writeBlock(0, buffer, BLOCK_SIZE);
	memset(buffer, 0, BLOCK_SIZE);
	
	// write free blocks and inodes to disk
	cout << "writing blocks: " << blocks << '\n';
	while (blocks)
	{
		_disk->writeBlock(blocks, buffer, BLOCK_SIZE);
		blocks--;
	}
	int inodes = superBlock.getNumberOfInodes();
	cout << "writing inodes: " << inodes << '\n';
	while (inodes)
	{
		_disk->writeBlock(inodes, buffer, BLOCK_SIZE);
		inodes--;
	}
	
}
	 
/**
 * Reads an Inode from disk.
 *
 * @param inode - the inode to read into
 * @param blockNumber - the block number that holds the inode to be read
 *
*/
void FileSystem::readInode(Inode& inode, int blockNumber)
{
	char block[BLOCK_SIZE];
	
	try {
		// read block containing the Inode
		_disk->readBlock(blockNumber, block);
	} catch (exception& e) {
		throw runtime_error ("unable to read Inode");
	}

    // finish implementing this method

}
	 
/**
 * Writes an Inode to disk.
 *
 * @param inode - the inode to be written to disk
 * @param blockNumber - the block number in which the inode will be written
 *
*/
void FileSystem::writeInode(Inode& inode, int blockNumber)
{
	// implement this function
}
	 
/**
 * Prints the content of the Inodes of the virtual disk to the screen.
 */
void FileSystem::printInodes()
{
	// implement this function
}

/**
 * Prints the block numbers of disk blocks that are free.
 */
void FileSystem::printFreeBlocks()
{
	// implement this function
}
	 
	 
/**
 * Writes an integer to a byte array.
 *
 * @param value - the integer to be written to a byte array
 * @param buffer - the byte array in which the integer will be written
 * @param pos - the position in the byte array where an integer will be written
 */
void FileSystem::intToByteArray( int value, char* buffer, int pos )
{
	int i;

    for (i = 0; i < 4; i++) {
        int shift = (4 - 1 - i) * 8;
        buffer[i+pos] = (char) (( (unsigned int) value >> shift) & 0xFF);
    }
}

 /**
  * Reads an integer from a byte array at a specific location.
  *
  * @param buffer - the byte array from which an integer will be read
  * @param pos - the position in the array from where an integer will be read
  *
  * @return an integer read from the byte array
 */
int FileSystem::byteArrayToInt( char* buffer, int pos )
{
	int i, value = 0;

    for (i = 0; i < 4; i++) {
		int shift = (4 - 1 - i) * 8;
        value += (buffer[i + pos] & 0x000000FF) << shift;
    }
    return value;
}