/**
 * A test program to test the file system.
 *
 * @author Thomas Reichherzer
 */

#include <string>
 
#include "fileSystem.hpp"

using namespace std;

/**
 * A test program for testing file system operations.
 *
 * @param args - a list of arguments
*/
int main(int argc, char* argv[])
{
	FileSystem fileSystem;

    string filename = "./disk1.bin";
	
	fileSystem.format( 100, filename );
		  
	return 0;
}
