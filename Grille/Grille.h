class Grille   : public Component
{
public:
    //==============================================================================
    Grille()
    {
        //setSize(640,480);
        for(auto i =1; i<51;i++)
        {
            auto bt = new TextButton;
            bt->setButtonText(String(i));
            bt->setColour(TextButton::ColourIds::buttonOnColourId, Colours::darkorange);
            bt->setClickingTogglesState(true);
            addAndMakeVisible(bt);
            arrayGrille.add(bt);
        }
        
    }
    ~Grille()
    {}
    
    //==============================================================================
    void paint (Graphics& g) override
    {
        
    }
    void resized() override
    {
        for(auto i =0;i<50;i++)
        {
        
            arrayGrille[i]->setBoundsRelative(((i%10))*0.1f, (i/10)*0.1f, 0.1f, 0.1f);
        }
    }
    
private:
    OwnedArray<TextButton> arrayGrille;
    //==============================================================================
    // Your private member variables go here...
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Grille)
};
