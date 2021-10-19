cmake_minimum_required(VERSION 3.20)
project(BitmapReading)

set(CMAKE_CXX_STANDARD 23)

add_executable(BitmapReading src/bitmap.cpp src/Pixel.cpp src/BitmapFile.cpp)
