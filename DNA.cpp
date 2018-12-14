#include "DNA.h"

DNA::DNA(){}

DNA::~DNA(){}

DNA::DNA(char *seq, DNA_Type atype,int s,int e)
{
    this->seq=new char [this->length+1];
    for (int i=0; i < this->length; ++i)
    {
        this->seq[i]=seq[i];
    }
    seq[length]= NULL;
    this->type=atype;
    startIndex=s;
    endIndex=e;
}

DNA::DNA(const DNA& rhs)
{
    this->length=rhs.length;
    this->seq=new char [length+1];
    for (int i = 0; i < length; i++)
	{
		seq[i] = rhs.seq[i];
	}
	seq[length]=NULL;
	type=rhs.type;
}

void DNA::BuildComplementaryStrand()
{
	complementary_strand->seq = new char[length + 1];
    for (int i = startIndex; i < endIndex; i++)
	{
		if (seq[i] == 'A')
		{
			complementary_strand->seq[i] = 'T';
		}
		else if (seq[i] == 'T')
		{
			complementary_strand->seq[i] = 'A';
		}
		else if (seq[i] == 'C')
		{
			complementary_strand->seq[i] = 'G';
		}
		else if (seq[i] == 'G')
		{
			complementary_strand->seq[i] = 'C';
		}
	}
	complementary_strand->seq[length] = NULL;
	for (int i = startIndex ; i < endIndex; i++)
	{
		cout<< complementary_strand->seq[i];
	}
}
void DNA:: Print()
{
	for (int i = 0; i < this->length; i++)
	{
		if (this->seq[i] == NULL)
		{
			break;
		}
		else
        {
            cout << this->seq[i];
        }
	}
	DNA d;
	d.BuildComplementaryStrand();
}

RNA DNA::ConvertToRNA()
{
	this ->seq= new char[length+1];
	int i = 0;
    for (int i=0; i< length; ++i)
    {
        if (seq[i] == NULL)
        {
            break;
        }
        if (seq[i] == 'T')
        {
            seq[i] = 'U';
        }
    }
    seq[length] = NULL;
    RNA r(seq, length);
    return r;

}

DNA DNA::operator= (DNA d)
{
	this->length = d.get_Length();
	seq = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		seq[i] = d.seq[i];
	}
	seq[length] =NULL;

	startIndex = d.startIndex;
	endIndex = d.endIndex;

	return *this;
}

bool DNA::operator==(DNA d)
{
	if (length == d.length)
    {
        int q = 0;
        for (int i=0; i<length; ++i)
        {
            if (this -> seq[i] == NULL)
            {
                continue;
            }
            if (this -> seq[i] == d.seq[i])
            {
                q++;
            }
            if (q == length)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    else
    {
        return false;
    }
}

bool DNA::operator!= (DNA d)
{
    int q = 0;
    for (int i=0; i<length; ++i)
    {
        if (this -> seq[i] == NULL)
        {
            continue;
        }
        if (this -> seq[i] != d.seq[i])
        {
            q++;
        }
        if (q > 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

}

DNA DNA::operator+(DNA d)
{
    DNA d1;
    for (int i = 0; i < length; ++i)
    {
        d1.seq[i] = this -> seq[i] + d.seq[i];
    }
    return d1;
}

istream & operator >> (istream & in, DNA & d)
{
	cout << "Insert the length of the Sequence : ";
	in >> d.length;
	d.seq = new char[d.length+1];
	cout<<endl;
	cout << "Insert the Sequence : ";
	string sequence_sentence;
	in >> sequence_sentence;
	cout<<endl;
	for (int i = 0; i < d.length; i++)
	{
		d.seq[i] = sequence_sentence[i];
	}
	d.seq[d.length]=NULL;

	return in;
}

ostream & operator<<(ostream  &out, DNA d)
{
	int x = d.get_Length();
	for (int i = 0; i < x; ++i)
	{
		out << d.seq[i];
	}
	cout << endl;

	return out;
}
