#include "Sequence.h"


Sequence::Sequence()
{
}


Sequence::~Sequence()
{
}

Sequence::Sequence(int l)
{
    length=l;
    seq=new char[length];
}

Sequence::Sequence(Sequence& rhs)
{
	seq = new char[length];
	for (int i = 0; i < length; i++)
	{
		seq[i] = rhs.seq[i];
	}
	seq[length] = NULL;
}

void Sequence::set_Length(int l)
{
    length=l;
}

int Sequence::get_Length()
{
    return length;
}

istream & operator>>(istream & in, Sequence& s)
{
	cout << "Insert the length of the Sequence : ";
	int l;
	cin>>l;
    s.set_Length(l);
	cout << "Insert the Sequence : ";
	for (int i = 0; i < s.get_Length(); i++)
	{
		in >> s.seq[i];
	}
	return in;
}

ostream & operator<<(ostream & out,Sequence& s)
{
	cout << "The length equal: ";
	cout<< s.get_Length() << endl;
	cout<<"The sequence.... \n";
	for (int i = 0 ; i < s.get_Length() ; i++)
	{
		out << s.seq[i];
	}
	cout << endl;
	return out;
}

void Align(char* seq1, char* seq2, int seq1_size, int seq2_size)
{

    int **LCS_Alogarithm;
    LCS_Alogarithm = new int*[seq1_size+ 1];
    for (int i = 0; i < seq1_size+1; i++)
    {
        LCS_Alogarithm[i] = new int[seq2_size+1];
    }
    char **literals;
    literals = new char*[seq1_size+ 1];
    for (int i = 0 ; i < seq1_size + 1; i++)
    {
        literals[i] = new char[seq2_size + 1];
    }
    for (int i = 0 ; i < seq1_size + 1 ; i++)
    {
        LCS_Alogarithm[i][0] = 0;
    }
    for (int j = 0 ; j < seq2_size + 1 ; j++)
    {
        LCS_Alogarithm[0][j] = 0;
    }
    for (int i = 0; i < seq1_size + 1; i++)
    {
        for (int j = 0; j < seq2_size+1; j++)
        {
            literals[i][j] = '0';
        }
    }
    for (int i = 1 ; i < seq1_size + 1 ; i++)
    {
        for (int j = 1 ; j < seq2_size + 1 ; j++)
        {

            if (seq1[i-1] == seq2[j-1])
            {
                LCS_Alogarithm[i][j] = LCS_Alogarithm[i - 1][j - 1] + 1;
                literals[i][j] = 'b';
            }
            else if (seq1[i - 1] != seq2[j - 1] && LCS_Alogarithm[i][j - 1] <= LCS_Alogarithm[i - 1][j])
            {
                LCS_Alogarithm[i][j] = LCS_Alogarithm[i - 1][j];
                literals[i][j] = 'u';
            }
            else
            {
                LCS_Alogarithm[i][j] = LCS_Alogarithm[i][j-1];
                literals[i][j] = 'l';
            }

        }

    }
    int i = seq1_size, j =seq2_size;
    int sizee = (LCS_Alogarithm[i][j]);
    char* arr = new char(sizee);
    int c = 0;
    while (true)
    {

        if (LCS_Alogarithm[i][j] == 0)
        {
            break;
        }
        if (LCS_Alogarithm[i][j] == 'b')
        {
            arr[c] = seq1[i - 1];
            i--;
            j--;
            c++;
        }
        else if (literals[i][j] == 'u')
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    for(int i = sizee - 1 ; i >= 0 ; i--)
    {
        cout << arr[i];
    }
}

