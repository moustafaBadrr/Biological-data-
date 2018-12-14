#include "Sequence.h"
#include "protein.h"
#include "CodonsTable.h"
#include "RNA.h"
#include "DNA.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
    char arr[10] = {'A','A','A','A','C','G','T','G','C'};
    CodonsTable t;
    t.LoadCodonsFromFile("RNA_codon_table.txt");
    t.getAminoAcid(arr);
    int choice;
    cin>>choice;
    cout << "\n 1-DNA"<< "\n 2-RNA"<< "\n 3-Protein" << endl;
    cout<<endl;
    if (choice == 1 )
    {
        DNA d;
        int x;
        cout << "\n 1-Convert to RNA Sequence \n";
        cout << "\n 2-Build Complementary Strand of the DNA Sequence \n";
        cin>>x;
        if (x == 1 )
        {
            d.ConvertToRNA();
        }
        if (x == 2 )
        {
            d.BuildComplementaryStrand();
        }
    }
    if (choice == 2 )
    {
        RNA r;
        cout << "\n 1-Convert to DNA Sequence \n";
        cout << "\n 2-Convert to Protein Sequence \n";
        int x;
        cin>>x;
        if (x == 1 )
        {
            r.ConvertToDNA();
        }
        if (x == 2 )
        {
            CodonsTable c;
            r.ConvertToProtein(c.LoadCodonsFromFile("RNA_codon_table.txt"));
        }
    }
    if (choice == 3 )
    {
        Protein p;
        DNA d;
        RNA r;
        p.GetDNAStrandsEncodingMe(d.ConvertToRNA(););
    }

    return 0;
}
