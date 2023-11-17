/**
 * Models an inode in a file system.
 *
 * @author Thomas Reichherzer
 */

#include "inode.hpp"

#include <stdexcept>
#include <string>

using namespace std;

Inode::Inode (int type, int owner, int filesize, string& filename)
{
	_type = type;
	_owner = owner;
	_filesize = filesize;

	if (filename.length() > FILENAME_LENGTH) { 
		throw invalid_argument ("filename too long");
	}
	for (unsigned int i=0; i < filename.length(); i++) {
		_filename[i] = filename[i];
	}
	
	for (unsigned int i=0; i < MAX_POINTERS; i++) {
		_pointer[i] = -1;
	}
	
}

string Inode::getFilename()
{
	return string(_filename, FILENAME_LENGTH);
}

int Inode::getPointer(int index)
{
	if (index < 0 || index >= MAX_POINTERS) {
		throw invalid_argument("index is out of range");
	}
	
	return _pointer[index];
}

void Inode::setPointer (int pointer, int index)
{
	if (index < 0 || index >= MAX_POINTERS) {
		throw invalid_argument("index is out of range");
	}
	
	_pointer[index] = pointer;
}