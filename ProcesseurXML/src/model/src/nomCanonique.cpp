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

NomCanonique::NomCanonique(string* aNom, string* aNamespace) : nom(*aNom), namespaceNom(*aNamespace)
{
#ifdef DEBUG
	cout << "Construction de <NomCanonique>" << endl;
#endif
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