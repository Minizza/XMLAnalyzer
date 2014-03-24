#include "commun.h"
#include "enTete.h"
#include <iostream>
#include <cstring>
#include "boost/program_options.hpp"

using namespace std;

extern FILE* xmlin;
int xmlparse(void);

int main(int argc, char** argv)
{

    namespace po=boost::program_options;
    // Handling of options 
    po::options_description desc("Available commands are");
    desc.add_options()
    ("parse,p",po::value<std::vector<std::string>>(),"parse and display the xml file")
    ("validate,v", po::value<std::vector<std::string>>(), "parse both xml and xsd files and display the validation result")
    ("transforme,t",po::value<std::vector<std::string>>(),"parse both xml and xsl files and display de transformation result of file.xml by the stylesheet file.xsl")
    ("help,h","displays this help");


    po::positional_options_description p;
    p.add("parse", -1);
    p.add("validate", 2);
    p.add("trasnform", 2);
// parse the options
    po::variables_map vm;
    po::store(po::command_line_parser(argc, argv).options(desc).positional(p).run(), vm);
    po::notify(vm);


    if(vm.count("help"))
    {
        std::cerr <<argv[0]<<" "<<desc;
    }
    if(vm.count("parse")){
        #ifdef DEBUG
        std::vector<std::string> files = vm["parse"].as<std::vector<std::string>>();
        for(std::string file : files){
            std::cout << "Input file " << file << std::endl;
        }
        #endif
        cout<<files[0]<<endl;
        FILE * fid;
        int temp;
        fid=fopen(files[0].c_str() ,"r");
        if (fid) {
            while ((temp = getc(fid)) != EOF)
                putchar(temp);
        }
        fclose(fid);
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
    return 1;
}
