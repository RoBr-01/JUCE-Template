# This was set up using the JUCE CMAKE template: 
# https://github.com/juce-framework/JUCE/blob/master/examples/CMake/AudioPlugin/CMakeLists.txt

cmake_minimum_required(VERSION 3.21)
project(Template VERSION 0.0.1)

# Compiler ID
message(STATUS "Compiler ID: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "Compiler Version: ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS "Compiler Path: ${CMAKE_CXX_COMPILER}")

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lib/JUCE)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc)

# Makes it easier to distinguish the different builds
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(JUCE_OUTPUT_NAME "${PROJECT_NAME}_debug")
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    set(JUCE_OUTPUT_NAME "${PROJECT_NAME}")
else()
    set(JUCE_OUTPUT_NAME "${PROJECT_NAME}_test")
endif()

juce_add_plugin(${JUCE_OUTPUT_NAME}
    # VERSION ...                               # Set this if the plugin version is different to the project version
    # ICON_BIG ...                              # ICON_* arguments specify a path to an image file to use as an icon for the Standalone version
    # ICON_SMALL ...
    # COMPANY_NAME ...                          # Specify the name of the plugin's author
    # IS_SYNTH TRUE/FALSE                       # Is this a synth or an effect?
    # NEEDS_MIDI_INPUT TRUE/FALSE               # Does the plugin need midi input?
    # NEEDS_MIDI_OUTPUT TRUE/FALSE              # Does the plugin need midi output?
    # IS_MIDI_EFFECT TRUE/FALSE                 # Is this plugin a MIDI effect?
    # EDITOR_WANTS_KEYBOARD_FOCUS TRUE/FALSE    # Does the editor need keyboard focus?
    # COPY_PLUGIN_AFTER_BUILD TRUE/FALSE        # Should the plugin be installed to a default location after building?
    # PLUGIN_MANUFACTURER_CODE                  # A four-character manufacturer id with at least one upper-case character
    # PLUGIN_CODE                              # A unique four-character plugin id with exactly one upper-case character
    # GarageBand 10.3 requires the first letter to be upper-case, and the remaining letters to be lower-case
    FORMATS AU VST3 Standalone # The formats to build. Other valid formats are: AAX Unity VST AU AUv3
    PRODUCT_NAME ${JUCE_OUTPUT_NAME}) # The name of the final executable, which can differ from the target name

juce_generate_juce_header(${JUCE_OUTPUT_NAME})

target_sources(${JUCE_OUTPUT_NAME}
    PRIVATE
    src/PluginEditor.cpp
    src/PluginProcessor.cpp)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lib/ScopedAlloc)
target_include_directories(${JUCE_OUTPUT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/lib/ScopedAlloc/Source)
target_link_libraries(${JUCE_OUTPUT_NAME} PRIVATE AllocationsChecker)

target_compile_definitions(${JUCE_OUTPUT_NAME}
    PUBLIC
    # JUCE_WEB_BROWSER and JUCE_USE_CURL would be on by default, but you might not need them.
    JUCE_WEB_BROWSER=0 # If you remove this, add `NEEDS_WEB_BROWSER TRUE` to the `juce_add_plugin` call
    JUCE_USE_CURL=0 # If you remove this, add `NEEDS_CURL TRUE` to the `juce_add_plugin` call
    JUCE_VST3_CAN_REPLACE_VST2=0)

target_link_libraries(${JUCE_OUTPUT_NAME}
    PRIVATE
    # AudioPluginData           # If we'd created a binary data target, we'd link to it here
    juce::juce_audio_utils
    PUBLIC
    juce::juce_recommended_config_flags
    juce::juce_recommended_lto_flags
    juce::juce_recommended_warning_flags)


option(BUILD_TESTS "Build tests" OFF)
if(BUILD_TESTS)
    message("Building tests")

endif()

