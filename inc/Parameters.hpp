#ifndef PARAMETERS_HPP
#define PARAMETERS_HPP

/*
This is used as a centralised way to define the parameter ID's and visual names.
It prevents accidental mismatches when accessing parameters via the APVTS.
*/

#include "JuceHeader.h"

struct Parameters {
    struct ParamInfo {
        juce::String id;
        juce::String name;
    };

    // Define all parameters here, for example:
    // ParamInfo example{"example_id", "example_name"};
};

#endif /* PARAMETERS_HPP */