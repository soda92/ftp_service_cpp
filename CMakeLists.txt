cmake_minimum_required(VERSION "3.16")
project(test_ftp)

include_directories(libncftp-3.2.6/libncftp)
include_directories(libncftp-3.2.6/sio)
include_directories(libncftp-3.2.6/Strn)

add_executable(test-ftp test-ftp.cpp)
