#include "CodonsTable.h"
#include <fstream>
#include <cstring>
CodonsTable::CodonsTable()
{
    //ctor
}

CodonsTable::~CodonsTable()
{
    //dtor
}

void CodonsTable::LoadCodonsFromFile(string codonsFileName)
{
	fstream codons_file(codonsFileName.c_str());

	if (codons_file.fail())
	{
		cout << "Error the File Can't open......\n Insert the name correctly please\n..";
	}

	int x = 0;
	char arr[6] ;
	while (!codons_file.eof()) // to read all file
	{
		codons_file.getline(arr,6);
		if (arr[0] == NULL)  // Because the array of char read the first index is NULL and i don't know why?
		{
			continue;
		}
		codons[x].value[0] = arr[0];
	    codons[x].value[1] = arr[1];
		codons[x].value[2] = arr[2];
		codons[x].value[3] = NULL;

		if ( arr[0] == 'U' && arr[1] == 'A' && arr[2] == 'A'|| arr[0] == 'U' && arr[1] == 'A'&& arr[2] == 'G'||
             arr[0] == 'U' && arr[1] == 'G' && arr[2] == 'A' )
		{
			codons[x].AminoAcid = ' ';
		}
		else
		{
			codons[x].AminoAcid = arr[4];
		}
		x++;
	}
}

Codon CodonsTable::getAminoAcid(char* arr)  // take char array of size 3 to get the amino acid from the file
{
    int q = 0;
	Codon get_amino;
	get_amino.value[0] = arr[0];
	get_amino.value[1] = arr[1];
	get_amino.value[2] = arr[2];
	get_amino.value[3] = NULL;

	for (int i = 0; i < 64; i++)
	{
		if (arr[0] == codons[i].value[0] && arr[1] == codons[i].value[1] && arr[2] == codons[i].value[2])
		{
			get_amino.AminoAcid = codons[i].AminoAcid;
			q++;
			break;
		}
	}
	if (q == 0) //check if the Amino acid is here or not
    {
        get_amino.AminoAcid = '0';  // 0 mean false
    }
	return get_amino;
}

//take char array of three characters and the fourth to the NULL
void CodonsTable::setCodon(char* value, char AminoAcid,int& index)
{
	for (int i=0; i< 3; ++i)
    {
        codons[index].value[i] = value[i];
    }
	codons[index].AminoAcid = AminoAcid;
}



/*
Codon CodonsTable::getAminoAcid(char* arr)
{


    int x = strlen(arr);
    cout<<"The size is : "<<x<<endl;
	Codon get_amino;
	for (int i=0; i < sizeof(arr);++i)
    {
        get_amino.value[i] = arr[i];
        get_amino.value[i+1] = arr[i+1];
        get_amino.value[i+2] = arr[i+2];
        get_amino.value[i+3] = NULL;
    }
    for (int i = 0; i < 64; ++i)
	{
        if (get_amino.value[i] == codons[i].value[i] && get_amino.value[i+1] == codons[i].value[i+1] &&
            get_amino.value[i+2] == codons[i].value[i+2])
		{
		    cout<<"TEST";
			get_amino.AminoAcid = codons[i].AminoAcid;
            cout<<get_amino.AminoAcid;
            break;
		}
		else
        {
            cout<<"TEST1";
            continue;
        }
    }
	return get_amino;
}
*/
