cmake_minimum_required(VERSION 3.11)

project(cpm_example)

#-DCPM_SOURCE_CACHE:PATH=$CMakeProjectDir$/.cache

set(CMAKE_CXX_STANDARD 11)

############################################################################################################
set(CPM_DOWNLOAD_VERSION 0.27.2)
set(CPM_DOWNLOAD_LOCATION "${CMAKE_BINARY_DIR}/cmake/CPM_${CPM_DOWNLOAD_VERSION}.cmake")

if(NOT (EXISTS ${CPM_DOWNLOAD_LOCATION}))
    message(STATUS "Downloading CPM.cmake")
    file(DOWNLOAD https://github.com/TheLartians/CPM.cmake/releases/download/v${CPM_DOWNLOAD_VERSION}/CPM.cmake ${CPM_DOWNLOAD_LOCATION})
endif()

include(${CPM_DOWNLOAD_LOCATION})
############################################################################################################

CPMAddPackage(
        NAME gsl
        GITHUB_REPOSITORY ampl/gsl
        VERSION 2.5.0
)

add_executable(cpm_example src/main.cpp)

target_link_libraries(cpm_example gsl)