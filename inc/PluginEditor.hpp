#ifndef PLUGINEDITOR_HPP
#define PLUGINEDITOR_HPP

#include <JuceHeader.h>

// Local
#include "PluginProcessor.hpp"


class NewProjectAudioProcessorEditor : public juce::AudioProcessorEditor {
   public:
    NewProjectAudioProcessorEditor(NewProjectAudioProcessor&);
    ~NewProjectAudioProcessorEditor() override;

    void paint(juce::Graphics&) override;
    void resized() override;

   private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    NewProjectAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(NewProjectAudioProcessorEditor)
};

#endif  // PLUGINEDITOR_HPP