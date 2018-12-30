# Exemple d'implémentation d'un menu dans la barre de tâche

Remplacer simplement le fichier main.cpp par celui-ci
Ajouter l'icone de Juce à votre programme ou votre propre icone

![Texte alternatif](taskbar.png) 

Le code:

<code>
  
#if JUCE_WINDOWS || JUCE_LINUX || JUCE_MAC // Pour ne pas l'implémenter sur IOS ou android
  
class TestTrayIcon : public SystemTrayIconComponent, private Timer

{

public:

    TestTrayIcon(){
    
        setIconImage (ImageFileFormat::loadFrom(BinaryData::juce_icon_png,BinaryData::juce_icon_pngSize));
        setIconTooltip ("TestTrayIcon");
        m.addItem (1, "Quit");
        
    }
    ~TestTrayIcon(){
        
    }
    void mouseDown(const MouseEvent& event) override{
        Process::makeForegroundProcess();
        startTimer (50);
    }
    static void menuInvocationCallback (int chosenItemID, TestTrayIcon*)
    {
        if (chosenItemID == 1)
            JUCEApplication::getInstance()->systemRequestedQuit();
    }
    void timerCallback() override
    {
        stopTimer();
        m.showMenuAsync (PopupMenu::Options(), ModalCallbackFunction::forComponent (menuInvocationCallback, this));
    }
private:
    PopupMenu m;
};
#endif

// On associe notre classe à notre fenetre

  #if JUCE_WINDOWS || JUCE_LINUX || JUCE_MAC
  
            taskbarIcon.reset (new TestTrayIcon());
  #endif
  
// on déclare notre objet

    private:
            std::unique_ptr<Component> taskbarIcon;
            
</code>


