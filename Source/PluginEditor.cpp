/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
using namespace juce;

//==============================================================================
NewProjectAudioProcessorEditor::NewProjectAudioProcessorEditor (NewProjectAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
    addAndMakeVisible(&disChoice);
    disChoice.addItem("Hard Clip", 1);
    disChoice.addItem("Soft Clip", 2);
    disChoice.addItem("Half Wave Rect", 3);
    disChoice.addItem("Tanh", 4);
    disChoice.setSelectedId(1);
    disChoice.addListener(this);

    addAndMakeVisible(&Threshold);
    Threshold.setRange(0.0f, 1.0f, 0.001);
    Threshold.addListener(this);

    addAndMakeVisible(&Mix);
    Mix.setRange(0.0f, 1.0f, 0.001);
    Mix.addListener(this);

    addAndMakeVisible(&Drive);
    Drive.setRange(0.0f, 10.0f, 0.01f);
    Drive.addListener(this);

}

NewProjectAudioProcessorEditor::~NewProjectAudioProcessorEditor()
{
}

//==============================================================================
void NewProjectAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
}

void NewProjectAudioProcessorEditor::resized()
{
    disChoice.setBounds(50, 50, 200, 50);
    Threshold.setBounds(50, 100, 200, 50);
    Mix.setBounds(50, 150, 200, 50);
    Drive.setBounds(50, 200, 200, 50);
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

void NewProjectAudioProcessorEditor::comboBoxChanged(ComboBox* comboBoxThatHasChanged) 
{
    audioProcessor.menuChoice = comboBoxThatHasChanged->getSelectedId();
}

void NewProjectAudioProcessorEditor::sliderValueChanged(Slider* slider) {
    if (&Mix == slider) {
        audioProcessor.mix = Mix.getValue();
    }
    if (&Threshold == slider) {
        audioProcessor.thresh = Threshold.getValue();
    }
    if (&Drive == slider) {
        audioProcessor.drive = Drive.getValue();
    }
}
