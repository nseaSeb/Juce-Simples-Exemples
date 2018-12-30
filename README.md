# Juce-SplashScreen
Simple SplashScreen Exemple

L'url de la classe SplashScreen sur le site de Juce:
https://docs.juce.com/master/classSplashScreen.html

Un simple exemple pour ajouter un SplashScreen dans une application Juce

1) J'ai créer une simple application pour faire cette exemple en utilisant le template de Juce nommé [Gui Application]
2) J'ajoute dans mon dossier source une image et par glisser déposer je l'ajoute à mes fichiers source dans l'application Projucer
3) Je m'assure que mon image sera compilé, incluse dans mon application (binary resource)

4) J'ouvre Main.cpp
5) Je repere la fonction d'initialisation
6) j'insère le code:
 auto splash = new SplashScreen ("Splash",ImageFileFormat::loadFrom(BinaryData::splash_png, (size_t) BinaryData::splash_pngSize),true);
7) puis le code:
 splash->deleteAfterDelay (RelativeTime::seconds (4), true);
8) Et c'est tout !

Notez BinaryData::splash_png pour retrouver mon image dans le fichier binaire de mon application

splash->deleteAfterDelay (RelativeTime::seconds (4), true);

splash le pointeur vers mon objet SplashScreen crée et nommé splash

-> car splash est un pointeur

deleteAfterDelay appel la fonction qui fermera notre splashSreen apres un delais

RelativeTime::seconds (4) 4 secondes ici

true , booléen pour valider que nous sommes ok pour que l'utilisateur puisse fermer le splash avant que le delais soit passé...

splash->deleteAfterDelay (RelativeTime::seconds (4), false); // dans ce cas pas de clic autorisé pour fermer...
