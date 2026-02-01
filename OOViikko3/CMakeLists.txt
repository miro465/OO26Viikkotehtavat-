cmake_minimum_required(VERSION 3.16)

project(OOViikko3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(OOViikko3 main.cpp
    Chef.h
    ItalianChef.h)

include(GNUInstallDirs)
install(TARGETS OOViikko3
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
