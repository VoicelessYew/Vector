cmake_minimum_required(VERSION 3.10.0)
project(project1 VERSION 0.1.0 LANGUAGES C CXX)

set(COMPILER_LOCATION "C:/msys64/mingw64/bin")
set(CMAKE_AR                        ${COMPILER_LOCATION}/ar.exe)
set(CMAKE_ASM_COMPILER              ${COMPILER_LOCATION}/gcc.exe)
set(CMAKE_C_COMPILER                ${COMPILER_LOCATION}/gcc.exe)
set(CMAKE_CXX_COMPILER              ${COMPILER_LOCATION}/g++.exe)
set(CMAKE_LINKER                    ${COMPILER_LOCATION}/ld.exe)
set(CMAKE_OBJCOPY                   ${COMPILER_LOCATION}/objcopy.exe)
set(CMAKE_RANLIB                    ${COMPILER_LOCATION}/ranlib.exe)
set(CMAKE_SIZE                      ${COMPILER_LOCATION}/size.exe)
set(CMAKE_STRIP                     ${COMPILER_LOCATION}/strip.exe)

add_subdirectory(lib)

add_executable(project1 main.cpp)

target_include_directories(project1 PUBLIC ${CMAKE_SOURCE_DIR}/lib)
target_link_libraries(project1 PUBLIC Vector)