cmake_minimum_required(VERSION "3.16")
project(test_ftp)

add_subdirectory(ftpclient-cpp)
include_directories(ftpclient-cpp/FTP)

add_executable(test-ftp test-ftp.cpp)
target_link_libraries(test-ftp ftpclient)