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
    

  
        button1.setLookAndFeel(&lookAndFeel);
   
     //   button1.setClickingTogglesState(true);
        button1.setToggleState(true, dontSendNotification);
       
        addAndMakeVisible(button1);
        resized();
    }
    ~MainComponent()
    {
        // important 
        sliderKnob.setLookAndFeel(nullptr);
        button1.setLookAndFeel(nullptr);
    }

    //==============================================================================
    void paint (Graphics&) override
    {
        
    }
    void resized() override
    {
        button1.setBoundsRelative(0.01f,0.01f,0.24f,0.24f);
        sliderKnob.setBoundsRelative(0.3f, 0.3f, 0.4f, 0.4f);
        sliderKnob.setTextBoxStyle(Slider::TextBoxAbove, false, sliderKnob.getWidth() * 0.6, sliderKnob.getHeight()* 0.2);
    }

private:
    //==============================================================================
    // Your private member variables go here...
    Slider sliderKnob {Slider::SliderStyle::Rotary,Slider::TextBoxAbove};
    ToggleButton  button1 {"Toggle Bouton 1"};
    
    CustomLookAndFeel lookAndFeel;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
