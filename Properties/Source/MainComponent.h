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
        initProperties();
        int w,h;
        w = props.getUserSettings()->getIntValue("Width");
        if(w==0)
            w=640;
        h = props.getUserSettings()->getIntValue("Height");
        if(h==0)
            h=480;
        setSize(w,h);
     
    }
    ~MainComponent()
    {
       props.getUserSettings()->setValue("Width", getWidth());
       props.getUserSettings()->setValue("Height", getHeight());
    }
    
    void initProperties()
    {
        PropertiesFile::Options options;
        options.applicationName = ProjectInfo::projectName;
        options.filenameSuffix = ".settings";
        options.osxLibrarySubFolder = "Application Support";
        options.folderName = File::getSpecialLocation(File::SpecialLocationType::userApplicationDataDirectory).getChildFile(ProjectInfo::projectName).getFullPathName();
        options.storageFormat = PropertiesFile::storeAsXML;
        
        props.setStorageParameters(options);
    }
    
    void paint (Graphics&) override
    {}
    void resized() override
    {}

private:
        ApplicationProperties props;
    //==============================================================================
    // Your private member variables go here...


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
