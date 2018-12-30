/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "MyLookAndFeel.h"

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
        setSize(640, 480);
        
        sliderKnob.setLookAndFeel(&lookAndFeel);
        sliderKnob.setRange(0, 128);
        sliderKnob.setNumDecimalPlacesToDisplay(0);
        addAndMakeVisible(sliderKnob);
        resized();
    }
    ~MainComponent()
    {
        // important 
        sliderKnob.setLookAndFeel(nullptr);
    }

    //==============================================================================
    void paint (Graphics&) override
    {
        
    }
    void resized() override
    {
      
        sliderKnob.setBoundsRelative(0.3f, 0.3f, 0.4f, 0.4f);
        sliderKnob.setTextBoxStyle(Slider::TextBoxAbove, false, sliderKnob.getWidth() * 0.6, sliderKnob.getHeight()* 0.2);
    }

private:
    //==============================================================================
    // Your private member variables go here...
    Slider sliderKnob {Slider::SliderStyle::Rotary,Slider::TextBoxAbove};
    CustomLookAndFeel lookAndFeel;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
