/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent   : public Component
{
public:
    //==============================================================================
    MainComponent()
    {
        setSize(640,480);
        addAndMakeVisible(label1);
        addAndMakeVisible(label2);
        label2.setText(TRANS("Filter Frequency"), dontSendNotification);
    }
    ~MainComponent()
    {
    }

    //==============================================================================
    void paint (Graphics&) override
    {
    }
    void resized() override
    {
        label1.setBoundsRelative(0.01f, 0.01f, 0.98f, 0.1f);
        label2.setBoundsRelative(0.01f, 0.03f, 0.98f, 0.1f);
    }

private:
    //==============================================================================
    // Your private member variables go here...
    Label   label1{"M",TRANS("Master Volume")};
    Label   label2;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
