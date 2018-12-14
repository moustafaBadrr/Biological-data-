#ifndef RNA_H
#define RNA_H

#include "Sequence.h"

class Protein;
enum RNA_Type {mRNA, pre_mRNA, mRNA_exon, mRNA_intron};

class RNA : public Sequence
{
  	private:
        RNA_Type type;
  	public:
 	 	// constructors and destructor
        RNA();
        RNA(char * seq, RNA_Type atype);
        RNA(RNA& rhs);
        ~RNA();
 	 	// function to be overridden to print all the RNA information
        void Print();
        RNA operator= (RNA r);
        RNA operator== (RNA r);
        RNA operator!= (RNA r);
        RNA operator+ (RNA r);
        friend istream & operator >> (istream & in, RNA & r);
        friend ostream & operator<<(ostream &out, RNA r);
 	 	// function to convert the RNA sequence into protein sequence
        // using the codonsTable object
        Protein ConvertToProtein(const CodonsTable & table);
 	 	// function to convert the RNA sequence back to DNA
        DNA ConvertToDNA();
};

#endif // RNA_H
