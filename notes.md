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
