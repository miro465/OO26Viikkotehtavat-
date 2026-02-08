cmake_minimum_required(VERSION 3.16)

project(OOviikko5 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(OOviikko5 main.cpp
    Seuraaja.h
    Notifikaattori.h
    Seuraaja.cpp
    Notifikaattori.cpp)

include(GNUInstallDirs)
install(TARGETS OOviikko5
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
