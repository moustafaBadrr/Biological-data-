#include "RNA.h"

RNA::RNA(){}

RNA::~RNA(){}

RNA::RNA(char * seq, RNA_Type atype)
{
    this->seq=new char[this->length];
    for (int i=0; i < this->length; ++i)
    {
        this->seq[i]=seq[i];
    }
    seq[length]= NULL;
    type=atype;
}

RNA::RNA(RNA &rhs)
{
    this->seq=new char[this->length];
    for (int i=0; i < this->length; ++i)
    {
        this->seq[i]=rhs.seq[i];
    }
    seq[length]= NULL;
    type=rhs.type;
}

void RNA::Print()
{
    for(int i=0; i < this->length ; ++i)
	{
		if (this->seq[i] == NULL)
		{
			continue;
		}
		else if ( this-> seq[i] == 'T')
        {
             seq[i] ='U';
        }
    }
    for(int i=0; i < this->length ; ++i)
	{
		if (this->seq[i] == NULL)
		{
			continue;
		}
		else
        {
            cout<<seq[i];
        }
    }
}

Protein RNA::ConvertToProtein(const CodonsTable &table)
{
    char* arr = new char[ (this->length / 3 ) + 1 ];
    int x = 0;
    Codon c;
    for (int i = 0; i < this->length ; i += 3)
    {
        char load[4];
        load[0] = this -> seq[i];
        load[1] = this -> seq[i+1];
        load[2] = this -> seq[i+2];
        load[3] = NULL;

        c = table.getAminoAcid(load);
		if (c.AminoAcid == ' ')
		{
			cout << "your sequence hasn't an amino acid...."<<endl;
		}
		else
        {
            arr[x] = c.AminoAcid;
        }
        x++;
    }
    arr[this->length / 3] = NULL;
    Protein p(arr, this->length / 3);

    return p;
}

DNA RNA::ConvertToDNA()
{
    char* arr = this -> seq;
    for (int i=0; i < this->length ; ++i)
    {
        if (arr[i] == NULL)
        {
            continue;
        }
        if (arr[i] == 'U')
        {
            arr[i] = 'T';
        }
    }
    arr[this -> length] = NULL;
    int x=this->length;
    DNA d(arr, tail,0,x);
    return d;
}

RNA RNA::operator= (RNA r)
{
    this->length = r.get_Length();
	seq = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		seq[i] = d.seq[i];
	}
	seq[length] =NULL;
	type = r.type;

	return *this;
}

bool RNA::operator== (RNA r)
{
    int q=0;
    for (int i = 0 ; i < this -> length; i++)
    {
        if (this -> seq[i] != r.seq[i])
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
bool RNA::operator!= (RNA r)
{
    int q=0;
    for (int i = 0 ; i < this -> length; i++)
    {
        if (this -> seq[i] != r.seq[i])
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
RNA RNA::operator+ (RNA r)
{
    RNA ob;
    ob.set_Length(this -> length + r.get_Length());

    for (int i = 0 ; i < this -> length; ++i)
    {
        ob.seq[i] = this -> seq[i];
    }
    for (int i = this -> length; i < ob.getLength(); ++i)
    {
        ob.seq[i + this->length] = r.seq[i];
    }
    return ob;
}

istream & operator >> (istream & in, RNA & r)
{
	cout << "Insert the length: ";
	in >> r.length;
	r.seq = new char[r.length+1];
	cout<<endl;
	cout << "Insert the Sequence : ";
	string sequence_sentence;
	in >> sequence_sentence;
	for (int i = 0; i < r.length; ++i)
	{
		r.seq[i] = sequence_sentence[i];
	}
	r.seq[r.length] = NULL;

	return in;
}

ostream & operator<<(ostream &out, RNA r)
{
	int x = r.get_Length();
	for (int i = 0; i < x; ++i)
	{
		out << r.seq[i];
	}

	return out;
}

