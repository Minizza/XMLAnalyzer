#include "nomCanonique.h"

ostream& operator<<(ostream&, const NomCanonique&);	
NomCanonique::NomCanonique()
{

}

NomCanonique::NomCanonique(NomCanonique* orig)
{

}
	
NomCanonique::~NomCanonique()
{

}

NomCanonique::NomCanonique(string* aNom, string* aNamespace) : nom(*aNom)
{
#ifdef DEBUG
	cout << "Construction de <NomCanonique>" << endl;
#endif
	delete aNom;
	if(aNamespace) 
	{
		namespaceNom = *aNamespace;
	}
	delete aNamespace;
}



	
std::ostream& NomCanonique::versFlux(std::ostream& os) const
{
	if(!namespaceNom.empty())
	{
		os << namespaceNom << ":";
	}
	os << nom;
}


ostream& operator<<(ostream& os, const NomCanonique& nom)
{
	nom.versFlux(os);
}