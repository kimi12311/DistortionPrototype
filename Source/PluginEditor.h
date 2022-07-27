/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

using namespace juce;

//==============================================================================
/**
*/
class NewProjectAudioProcessorEditor : public juce::AudioProcessorEditor, private ComboBox::Listener, Slider::Listener
{
public:
    NewProjectAudioProcessorEditor (NewProjectAudioProcessor&);
    ~NewProjectAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:

    void comboBoxChanged(ComboBox* comboBoxThatHasChanged) override;
    void sliderValueChanged(Slider* sliderThatHasChanged) override;
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    NewProjectAudioProcessor& audioProcessor;
    ComboBox disChoice;
    Slider Threshold;
    Slider Mix;
    Slider Drive;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(NewProjectAudioProcessorEditor)


};
