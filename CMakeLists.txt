cmake_minimum_required(VERSION 3.24)
project(sysNet1_fs CXX)
#set_target_properties(sysNet1_fs PROPERTIES LINKER_LANGUAGE CXX)

set(CMAKE_C_STANDARD 11)

add_executable(sysNet1_fs disk.cpp disk.hpp fileSystem.cpp fileSystem.hpp inode.cpp inode.hpp superBlock.hpp main.cpp)
