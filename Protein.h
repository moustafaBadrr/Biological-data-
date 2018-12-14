#ifndef PROTEIN_H
#define PROTEIN_H

#include "Sequence.h"

enum Protein_Type {Hormon, Enzyme, TF, Cellular_Function};

class Protein : public Sequence
{
  	private:
        Protein_Type type;
      public:
 	 	// constructors and destructor
 	 	Protein();
 	 	Protein(char * p);
 	 	~Protein()
 	 	bool operator= (Protein p);
 	 	bool operator== (Protein p);
 	 	bool operator!= (Protein p);
 	 	bool operator+ (Protein p);
 	 	friend istream & operator >> (istream & in, Protein & p);
 	 	friend ostream & operator<<(ostream &out, Protein p);
 	 	// return an array of DNA sequences that can possibly
        // generate that protein sequence
        DNA* GetDNAStrandsEncodingMe(const DNA & bigDNA);
};


#endif // PROTEIN_H
