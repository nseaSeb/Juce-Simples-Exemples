# Notes / Mémo
Ici quelques trucs et astuces 

* String
  Une fonction qui retourne true si la String contient une valeur numérique
  
<code>
  bool is_number(const String& str)
  
{

	return str.containsOnly("0123456789.-");
	
}
</code>

* Logger
  
<code>
Logger::writeToLog ("String"); </code>  

* Exemple de manipulation avec un tableau de Int

<code>
    int sysexdata[9] = { 0x00, 0X01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08 };
	
        sysexdata[4] = 0x44; //Remplace 0x04 par 0x44 
</code>
  
*3 approches pour passer nos valeurs :

<code>
void incrementer_par_valeur(int x) { 
	
    x++;
    
    // X est recopié
} 

void incrementer_par_pointeur(int * px) { 

    if(px) (*px)++; 
    
    //On doit vérifié que le pointeur n'est pas nul
} 

void incrementer_par_reference(int & x) { 

    x++; 
    
    // A privilégier
} 
</code>


#Les pointeurs: (merci à Daniel et xenakios du forum Juce)
std::unique_ptr : le ptr possède l'objet, et il sera supprimé, une fois que le ptr sortira du champ d'application. ScopedPointer est la même chose et enveloppe maintenant en interne un std::unique_ptr, donc aucune raison d'utiliser ScopedPointer dans un nouveau code
std::shared_ptr : la propriété est partagée entre tous les shared_ptr qui pointent vers le même objet. Une fois que le dernier shared_ptr sort du périmètre, l'objet est supprimé. ReferenceCountedObject::Ptr est la même chose, mais différemment implémenté, ReferenceCountedObject est un compteur de référence intrusif, vs std::shared_ptr est non-intrusif
std::weak_ptr : ne possède pas du tout l'objet, mais le ptr est automatiquement mis à nullptr, une fois que la pointee est effacée. Il y a le Composant::SafePointer et WeakReference dans le jus, qui font la même chose.
SharedResourcePointer : créer l'objet à la volée et le partager, s'il a déjà été créé ailleurs. Puisque vous n'avez aucun contrôle, quand il est créé et quand il ne l'est pas, ce n'est pas bien adapté à la persistance. Je ne suis pas au courant d'une version de la STL.
Une spécialité de weak_ptr, est, que pour utiliser un weak_ptr, vous devez créer un shared_ptr à partir du weak_ptr, ce qui empêchera l'objet d'être supprimé ailleurs (prolongeant la vie utile).
Cependant, lorsqu'ils sont utilisés avec les Composants, ils sont destinés à être créés, détruits, positionnés et peints sur le fil de message. Il ne peut donc pas être détruit en attendant. Il suffit donc de vérifier au début de la fonction.

Alors que weak_ptr peut être utilisé pour prolonger la durée de vie de shared_ptr, il n'est pas limité à être utilisé avec shared_ptr, afaik.
Il est limité à l'utilisation avec seulement shared_ptr. Il a besoin du support de la classe smart pointer qui implémente shared_ptr. Mais std::unique_ptr n'est qu'une très fine enveloppe autour d'un pointeur, il ne fait aucun type de référence ou de comptage de référence faible.

