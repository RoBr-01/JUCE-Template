#ifndef PARAMETERS_HPP
#define PARAMETERS_HPP

/*
This is used as a centralised way to define the parameter ID's and visual names.
It prevents accidental mismatches when accessing parameters via the APVTS.
*/

#include "JuceHeader.h"

struct Parameters {
    struct ParamInfo {
        const char* id;
        const char* name;
    };

    // Define all parameters here, for example:
    // ParamInfo example{"example_id", "example_name"};
};

inline const Parameters g_Parameters;

// Easy way to get a parameter safely, do mind that this is not normalized and
// not smoothed!
template <typename T>
inline T getParamAs(const juce::AudioProcessorValueTreeState& apvts,
                    const char* id) {
    if (auto* param = apvts.getRawParameterValue(id))
        return static_cast<T>(param->load());
    return T{};
}

#endif /* PARAMETERS_HPP */