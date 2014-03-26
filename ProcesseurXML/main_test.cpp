#include "commun.h"
#include "enTete.h"
#include <iostream>
#include <cstring>
#include "boost/program_options.hpp"

#include "elementNoeud.h"
#include "elementDonnees.h"

using namespace std;

extern FILE* yyin;
int xmlparse(void);

int main(int argc, char** argv)
{
		deque<AbstractAttribut*> attributs;
		deque<AbstractElement*> enfants;
		
		string nom1("coucou c'est du texte");
		ElementDonnees f1(&nom1);
		enfants.push_back(&f1);
		
		deque<AbstractAttribut*> attributs2;
		deque<AbstractElement*> enfants2;
		string nom3("fils");
		ElementNoeud f3(&nom3, &attributs, &enfants2);
		enfants.push_back(&f3);
		
		string nom2("olol les comz");
		ElementComz f2(&nom2);
		enfants.push_back(&f2);
		
		string nom("noeudTest");
		ElementNoeud noeud(&nom, &attributs, &enfants);
	
		noeud.versFlux(cout);
	
		cout << endl <<"Test de l'iterator" << endl;
		for(AbstractElement::iterator it = noeud.begin(); it != noeud.end(); it++)
		{
				AbstractElement* elt = *it;
				elt->versFlux(cout);
		}
		
    /*namespace po=boost::program_options;
    // Handling of options 
    po::options_description desc("Available commands are");
    desc.add_options()
    ("help,h","Give you da help")
    ("input-files,i", po::value<std::vector<std::string>>(), "Input files")
    ("add,a",po::value<int>(),"Add something to da b*tch");

    po::positional_options_description p;
    p.add("input-files", -1);
// parse the options
    po::variables_map vm;
    po::store(po::command_line_parser(argc, argv).options(desc).positional(p).run(), vm);
    po::notify(vm);


    if(vm.count("help"))
    {
        std::cerr <<argv[0] <<desc;
    }
    if(vm.count("add"))
    {
        cerr << vm["add"].as<int>()<<" We get that number"<<endl;
    }
    if(vm.count("input-files")){
        std::vector<std::string> files = vm["input-files"].as<std::vector<std::string>>();
        for(std::string file : files){
            std::cout << "Input file " << file << std::endl;
        }
    }
   // int retour = xmlparse();
   // if (!retour)
   // {
   //    cout<<"Entrée standard reconnue"<<endl;
   // }
   // else
   // {
   //    cout<<"Entrée standard non reconnue"<<endl;
   // }
    cout << argv[0] << endl ;
    return 1;*/
}
