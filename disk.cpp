/**
 * Simulates a physical disk. The disk reads and writes blocks of data.
 *
 * @author Thomas Reichherzer
 */

#include "disk.hpp"

#include <stdexcept>

using namespace std;

#define NUM_BLOCKS 1

/**
 * Constructs a disk simulated by a file.
 * 
 * @param sizeInKB - the size of the disk in kilo bytes
 * @param path - the path of the file simulating the disk
 *
 *
 * @throw exception if the parameter values are invalid or an error occurred creating the disk
*/
Disk::Disk( int sizeInKB, const string& path )
{
	if (sizeInKB <= 0) {
		throw invalid_argument ("invalid disk size");
	}
	
	_sizeInKB = sizeInKB;

	_physicalDisk = fopen( path.c_str(), "w+" );
	if( _physicalDisk == NULL ) {
		throw runtime_error ("failed to create physical disk file");
	}
}

/**
 * Reads a data block from the disk.
 * 
 * @param blockNumber - specifies the block to be read
 * @param blockData - a block of data the size of BLOCK_SIZE
 * 
 * @return number of bytes read
 *
 * @throw exception if the parameter values are invalid or an error occurred reading a block from the disk
 */
int Disk::readBlock( int blockNumber, char* blockData )
{
	if ((blockNumber >= _sizeInKB) || (blockNumber < 0)) {
		throw invalid_argument("invalid block number");
	}
	
	//offset specified number of bytes from the beginning of the disk
	int error = fseek(_physicalDisk, blockNumber*BLOCK_SIZE, 0);
	if( error )	{
		throw runtime_error ("couldn't seek to specified block");
	}
	
	//read NUM_BLOCKS unit of 1024 bytes from file _physicalDisk to array blockData
	int count = fread( blockData, BLOCK_SIZE, NUM_BLOCKS, _physicalDisk );
	if( count != NUM_BLOCKS  ) {
		throw runtime_error ("couldn't read block");
	}
				
	return BLOCK_SIZE;
}

/**
 * Writes a data block to the disk.
 * 
 * @param blockNumber - specifies the location where the block of data be written
 * @param blockData - the block of data to be written
 * @param numberOfBytes - the number of bytes to write into the block
 * 
 * @return number of bytes written
 *
 * @throw exception if the parameter values are invalid or an error occurred reading a block from the disk
 */
int Disk::writeBlock( int blockNumber, const char* blockData, int numberOfBytes  )
{
	cout << "Disk::writeBlock num:" << blockNumber << endl;
	cout << "Disk::writeBlock len:" << numberOfBytes << endl;
	int error, count;
	if ((blockNumber >= _sizeInKB) || (blockNumber < 0)) {
		throw invalid_argument("Invalid block number");
	}
	//offset specified number of bytes from the beginning of the disk
	error = fseek(_physicalDisk, blockNumber*BLOCK_SIZE, 0);
	if( error ) {
		throw out_of_range("couldn't seek to specified block");
	}
	//if number of bytes to write is bigger than a block, write maximum of a block,
	//else write the number of bytes
	int len = (numberOfBytes > BLOCK_SIZE ? BLOCK_SIZE : numberOfBytes);
	//read NUM_BLOCKS unit of BLOCK_SIZE bytes from file _physicalDisk to array blockData
	count = fwrite( blockData, len, NUM_BLOCKS, _physicalDisk );
	if( count != NUM_BLOCKS ) {
		throw runtime_error("couldn't write block");
	}
				
	return BLOCK_SIZE;
}
	 
/**
 * Returns the size of the disk.
 * 
 * @return the size of the disk in kilo bytes
*/
int Disk::getSize()
{
	return _sizeInKB;
}
