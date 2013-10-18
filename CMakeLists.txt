cmake_minimum_required(VERSION 2.6)

#find_package(CURL REQUIRED)
#find_package(OpenSSL REQUIRED)
#find_package(Curses REQUIRED)
#find_package(SQLITE3 REQUIRED)

add_subdirectory (libleg)

find_path ( irr irrlicht.h /usr/include/irrlicht)
if (irr)
    add_subdirectory(lgfx)
    add_executable (legion main-irrlicht.cpp)
    target_link_libraries (legion lgfx)
else (irr)
    add_executable (legion main.cpp)
endif (irr)

target_link_libraries (legion leg)

#install (TARGETS moorie_cli DESTINATION bin)


