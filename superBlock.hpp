#ifndef SUPERBLOCK_H_
#define SUPERBLOCK_H_

/**
 * Models a super block in a file system.
 *
 * @author Thomas Reichherzer
 */

class SuperBlock
{
	int _numberOfDiskBlocks;
	int _numberOfInodes;
	int _firstBlockOfFreeList;
	
	public:
		SuperBlock() : SuperBlock (0, 0, 0) { }
		SuperBlock(int numberOfDiskBlocks, int numberOfInodes, int firstBlockOfFreeList) : 
		 _numberOfDiskBlocks (numberOfDiskBlocks), 
		 _numberOfInodes (numberOfInodes), 
		 _firstBlockOfFreeList (firstBlockOfFreeList) 
		 {}
		
		int getNumberOfDiskBlocks () { return _numberOfDiskBlocks; }
		int getNumberOfInodes () { return _numberOfInodes; }
		int getFirstBlockFreeList () { return _firstBlockOfFreeList; }
		
		void setNumberOfDiskBlocks (int number) { _numberOfDiskBlocks = number; }
		void setNumberOfInodes (int number) { _numberOfInodes = number; }
		void setFirstBlockOfFreeList (int blockNumber) { _firstBlockOfFreeList = blockNumber; }
};

#endif /*SUPERBLOCK_H_*/