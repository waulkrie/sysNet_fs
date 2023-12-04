#ifndef INODE_H_
#define INODE_H_

/**
 * Models an inode in a file system.
 *
 * @author Thomas Reichherzer
 */

#define MAX_POINTERS 250

// up to 8 characters plus . plus 3 letter extension is allowed
#define FILENAME_LENGTH 12

#include <string>

using namespace std;

// indicates if the inode points to a file or a directory
class Inode
{
	 // indicates if the inode points to a file or a directory
	 // 0 indicates that the Inode is unused
    int _type;
    
	// indicates the owner of the file (an Id)
    int _owner;
    
	// indicates the size of the file
    int _filesize;
	
	// specifies the filename 
	char _filename[FILENAME_LENGTH];
    
	// a list of direct pointers to data blocks of the file
    int _pointer[MAX_POINTERS];
	
	public:
		Inode (int type, int owner, int filesize, string& filename);
		
		int getType() { return _type; }
		int getOwner() { return _owner; }
		int getFilesize() { return _filesize; }
		string getFilename();
		int getPointer(int index);
		
		void setPointer (int pointer, int index);
} __attribute__((packed));

#endif /*INODE_H_*/
