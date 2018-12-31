

#pragma once
//==============================================================================
class CustomLookAndFeel : public LookAndFeel_V4
{
public:
    CustomLookAndFeel()
    {

        imageKnob = ImageCache::getFromMemory(BinaryData::knob_png, BinaryData::knob_pngSize);
        imageToggle = ImageCache::getFromMemory(BinaryData::toggle_png, BinaryData::toggle_pngSize);
}

//==============================================================================
void drawRotarySlider(Graphics& g,
                                       int x, int y, int width, int height, float sliderPos,
                                       float rotaryStartAngle, float rotaryEndAngle, Slider& slider)
{
    
    if (imageKnob.isValid())
    {
        const double rotation = (slider.getValue()
                                 - slider.getMinimum())
        / (slider.getMaximum()
           - slider.getMinimum());
        
        const int frames = imageKnob.getHeight() / imageKnob.getWidth();
        const int frameId = (int)ceil(rotation * ((double)frames - 1.0));
        const float radius = jmin(width / 2.0f, height / 2.0f);
        const float centerX = x + width * 0.5f;
        const float centerY = y + height * 0.5f;
        const float rx = centerX - radius - 1.0f;
        const float ry = centerY - radius;
        
        
        g.drawImage(imageKnob,(int)rx,(int)ry,2 * (int)radius,2 * (int)radius,0,frameId*imageKnob.getWidth(),imageKnob.getWidth(), imageKnob.getWidth());
    }

}
    Image imageKnob;

//==============================================================================
   
    void    drawToggleButton	(	Graphics & 	g,
                                 ToggleButton & button	,
                                 bool 	shouldDrawButtonAsHighlighted,
                                 bool 	shouldDrawButtonAsDown 
                                 )
    {
        auto fontSize = jmin (15.0f, button.getHeight() * 0.75f);
    
        
        if(shouldDrawButtonAsHighlighted)
        {
            g.fillRect(0, button.getHeight() - (int(fontSize)), button.getWidth(), int(fontSize));
        }
        
       if(button.getToggleState())//        if(shouldDrawButtonAsDown)
        {
            g.drawImage(imageToggle, 0, 0, button.getWidth(),button.getHeight(), 0, 0, imageToggle.getWidth(), imageToggle.getWidth());
           
            
        }
        else
        {
            g.drawImage(imageToggle, 0, 0, button.getWidth(),button.getHeight(), 0, imageToggle.getWidth(), imageToggle.getWidth(), imageToggle.getWidth());
  
        }

        
        g.setColour (button.findColour (ToggleButton::textColourId));
        g.setFont (fontSize);
        
        if (! button.isEnabled())
            g.setOpacity (0.5f);
        
        g.drawFittedText (button.getButtonText(),
                          button.getLocalBounds(),
                          Justification::centredBottom, 4);
        
    }
    //==============================================================================
    Image imageToggle;
};
