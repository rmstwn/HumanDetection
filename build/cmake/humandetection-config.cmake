# HumanDetection CMake config file
#
# This file sets the following variables:
# HumanDetection_FOUND - Always TRUE.
# HumanDetection_INCLUDE_DIRS - Directories containing the HumanDetection include files.
# HumanDetection_IDL_DIRS - Directories containing the HumanDetection IDL files.
# HumanDetection_LIBRARIES - Libraries needed to use HumanDetection.
# HumanDetection_DEFINITIONS - Compiler flags for HumanDetection.
# HumanDetection_VERSION - The version of HumanDetection found.
# HumanDetection_VERSION_MAJOR - The major version of HumanDetection found.
# HumanDetection_VERSION_MINOR - The minor version of HumanDetection found.
# HumanDetection_VERSION_REVISION - The revision version of HumanDetection found.
# HumanDetection_VERSION_CANDIDATE - The candidate version of HumanDetection found.

message(STATUS "Found HumanDetection-")
set(HumanDetection_FOUND TRUE)

find_package(<dependency> REQUIRED)

#set(HumanDetection_INCLUDE_DIRS
#    "C:/Program Files/OpenRTM-aist/2.0.1/cmake/../Components/c++/Category/OpenRTM-aist/2.0.1/Components/c++/Category/include/humandetection-"
#    ${<dependency>_INCLUDE_DIRS}
#    )
#
#set(HumanDetection_IDL_DIRS
#    "C:/Program Files/OpenRTM-aist/2.0.1/cmake/../Components/c++/Category/OpenRTM-aist/2.0.1/Components/c++/Category/include/humandetection-/idl")
set(HumanDetection_INCLUDE_DIRS
    "C:/Program Files/OpenRTM-aist/2.0.1/cmake/../Components/c++/Category/OpenRTM-aist/2.0.1/Components/c++/Category/include/"
    ${<dependency>_INCLUDE_DIRS}
    )
set(HumanDetection_IDL_DIRS
    "C:/Program Files/OpenRTM-aist/2.0.1/cmake/../Components/c++/Category/OpenRTM-aist/2.0.1/Components/c++/Category/include//idl")


if(WIN32)
    set(HumanDetection_LIBRARIES
        "C:/Program Files/OpenRTM-aist/2.0.1/cmake/../Components/c++/Category/OpenRTM-aist/2.0.1/Components/c++/Category//humandetection.lib"
        ${<dependency>_LIBRARIES}
        )
else(WIN32)
    set(HumanDetection_LIBRARIES
        "C:/Program Files/OpenRTM-aist/2.0.1/cmake/../Components/c++/Category/OpenRTM-aist/2.0.1/Components/c++/Category//humandetection.dll"
        ${<dependency>_LIBRARIES}
        )
endif(WIN32)

set(HumanDetection_DEFINITIONS ${<dependency>_DEFINITIONS})

set(HumanDetection_VERSION )
set(HumanDetection_VERSION_MAJOR )
set(HumanDetection_VERSION_MINOR )
set(HumanDetection_VERSION_REVISION )
set(HumanDetection_VERSION_CANDIDATE )

