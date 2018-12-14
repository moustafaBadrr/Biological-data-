#include "Protein.h"

Protein::Protein(){}

Protein::~Protein(){}


Protein::Protein(char * p , Protein_Type atype)
{
    this->seq=new char [this->length];
    for (int i=0; i < this->length; ++i)
    {
        this->seq[i]=p[i];
    }
    seq[length]= NULL;
    type=atype;
}

Protein Protein::operator= (Protein p)
{
	seq = new char[length + 1];
	for (int i = 0; i < p.length; i++)
	{
		seq[i] = p.seq[i];
	}
	seq[p.length] = NULL;
	type = p.type;

	return *this;
}

bool Protein::operator== (Protein p)
{
    int q=0;
    for (int i = 0 ; i < this -> length; i++)
    {
        if (this -> seq[i] != p.seq[i])
        {
            q++;
        }
    }
    if (q > 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool Protein::operator!= (Protein p)
{
    int q=0;
    for (int i = 0 ; i < this -> length; i++)
    {
        if (this -> seq[i] != p.seq[i])
        {
            q++;
        }
    }
    if (q == this->length)
    {
        return true;
    }
    else
    {
        return false;
    }
}

RNA Protein::operator+ (Protein p)
{
    Protein ob;
    ob.set_Length(this -> length + p.get_Length());

    for (int i = 0 ; i < this -> length; ++i)
    {
        ob.seq[i] = this -> seq[i];
    }
    for (int i = this -> length; i < ob.getLength(); ++i)
    {
        ob.seq[i + this->length] = p.seq[i];
    }
    return ob;
}

istream & operator >> (istream & in, Protein & p)
{
	cout << "Insert the length: ";
	in >> p.length;
	p.seq = new char[p.length+1];
	cout<<endl;
	cout << "Insert the Sequence : ";
	string sequence_sentence;
	in >> sequence_sentence;
	for (int i = 0; i < r.length; ++i)
	{
		p.seq[i] = sequence_sentence[i];
	}
	p.seq[p.length] = NULL;

	return in;
}

ostream & operator<<(ostream &out, Protein p)
{
    int x = p.get_Length();
	for (int i = 0; i < x ; ++i)
	{
		out << p.seq[i];
	}

	return out;
}


DNA* Protein::GetDNAStrandsEncodingMe(const DNA & bigDNA)
{

    DNA d;
    RNA r;
    Protein p;
    CodonsTable c;
    d.ConvertToRNA();
    r.ConvertToProtein(c.CodonsTable());

    int x = d.get_Length(); // DNA length
    int y = this->length;   // Protein length
}
