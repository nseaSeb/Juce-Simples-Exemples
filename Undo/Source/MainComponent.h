/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

namespace IDs
{
#define DECLARE_ID(name) const juce::Identifier name (#name);
    
    DECLARE_ID (Slider1)
    DECLARE_ID (Slider2)
    
#undef DECLARE_ID
}

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent   : public Component, private Timer
{
public:
    //==============================================================================
    MainComponent()
    {
        setSize (640, 480);
        
        addAndMakeVisible (undoButton);
        addAndMakeVisible (redoButton);
        undoButton.setButtonText("Undo");
        redoButton.setButtonText ("Redo");
// ici une petite astuce pour se passer d'un listener
        undoButton.onClick = [this] { undoManager.undo(); };
        redoButton.onClick = [this] { undoManager.redo(); };
        
        addAndMakeVisible(slider1);
        addAndMakeVisible(slider2);
        slider2.setValue(12);
        
// On déclare notre ValueTree
        ValueTree myValueTree ("myApp");
        
// On initialise le value tree avec les valeurs des Slider
        myValueTree.setProperty(IDs::Slider1, slider1.getValue(), &undoManager);
        myValueTree.setProperty(IDs::Slider2, slider2.getValue(), &undoManager);

        // On attache nos slider à leurs propriétées et on y associe notre UndoManager
        
        slider1.getValueObject().referTo(myValueTree.getPropertyAsValue(IDs::Slider1,&undoManager));
        slider2.getValueObject().referTo(myValueTree.getPropertyAsValue(IDs::Slider2,&undoManager));
/*
 Il est également possible d'associer une value (et meme plusieurs objets)

    Value valueSlider1 = myValueTree.getPropertyAsValue(Ids::Slider1, &undoManager);
    Value valueSlider2 = myValueTree.getPropertyAsValue(IDs::Slider2, &undoManager);
 
    slider1.getValueObject().referTo(valueSlider1);
    slider2.getValueObject().referTo(valueSlider2);
*/
        
        resized();
        startTimer (500);
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
        slider1.setBoundsRelative(0.1f, 0.1f, 0.8f, 0.3f);
        slider2.setBoundsRelative(0.1f, 0.5f, 0.8f, 0.3f);
        undoButton.setBoundsRelative(0.1f, 0.9f, 0.3f, 0.09f);
        redoButton.setBoundsRelative(0.5f, 0.9f, 0.3f, 0.09f);
    }
    bool keyPressed (const KeyPress& key) override
    {
 
/* 
 On recupère les evenements clavier qui nous concernent
 Ici encore nous nous passons d'un listener car les objets component
 récupèrent les evenements clavier par defaut
*/
        if (key == KeyPress ('z', ModifierKeys::commandModifier, 0))
        {
            undoManager.undo();
            return true;
        }
        
        if (key == KeyPress ('z', ModifierKeys::commandModifier | ModifierKeys::shiftModifier, 0))
        {
            undoManager.redo();
            return true;
        }
        
        return Component::keyPressed (key);
        
    }
private:
    void timerCallback() override
    {
            undoManager.beginNewTransaction();
    }
    //==============================================================================
    // Your private member variables go here...
    Slider  slider1;
    Slider  slider2;
    TextButton undoButton, redoButton;
    UndoManager undoManager;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
