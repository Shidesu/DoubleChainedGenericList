cmake_minimum_required(VERSION 3.5)
project(listeChainee C)
project(doubleChainedListPOOStyle C)#Crée un projet C nommé doubleChainedListPOOStyle

#Assigne 11 à la variable CMAKE_C_STANDARD
set(CMAKE_C_STANDARD 11)

#Permet de générer une librairie à partir de listeChainee.c et listeChainee.h
add_library(doubleChainedListPOOStyle SHARED sources/listeChainee.c headers/listeChainee.h)

set_target_properties(doubleChainedListPOOStyle PROPERTIES PUBLIC_HEADER "headers/listeChainee.h")

install(TARGETS doubleChainedListPOOStyle
        LIBRARY DESTINATION "${CMAKE_CURRENT_SOURCE_DIR}/bin"
        ARCHIVE DESTINATION "${CMAKE_CURRENT_SOURCE_DIR}/bin"
        RUNTIME DESTINATION "${CMAKE_CURRENT_SOURCE_DIR}/bin"
        PUBLIC_HEADER DESTINATION "${CMAKE_CURRENT_SOURCE_DIR}/include")
