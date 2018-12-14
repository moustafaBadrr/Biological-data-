#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <iostream>

using namespace std;

class Sequence
{
  	public:
        char * seq;
        int length;
    public:
 	 	// constructors and destructor
        Sequence();
        Sequence(int l);
        Sequence(Sequence& rhs);
        virtual ~Sequence();
        void set_Length(int l);
        int get_Length();
 	 	// pure virtual function that should be overridden because every
        // type of sequence has its own details to be printed
        virtual void Print()= 0;
 	 	friend istream& operator>> (istream& in, const Sequence& s);
        friend ostream& operator<< (ostream& out, const Sequence& s);
 	 	// friend function that will find the LCS (longest common
        // subsequence) between 2 sequences of any type, according to
        // polymorphism
        friend char* Align(Sequence * s1, Sequence * s2);
};

#endif // SEQUENCE_H
