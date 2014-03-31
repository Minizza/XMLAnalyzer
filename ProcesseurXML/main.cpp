#include "commun.h"
#include "enTete.h"
#include <iostream>
#include <cstring>
#include <typeinfo>

using namespace std;

extern FILE* xmlin;
extern int xmldebug;
int xmlparse(Document**);

Document* parseFile(FILE* fid)
{
    xmlin=fid;
    Document* doc=NULL;
    int b=xmlparse(&doc);
    return doc;
}

void catDatFile(FILE * fid,char* nomFichier)
{
    cout<<"=============DEBUT DU DEBUG"<<endl;
    int temp;
    if (fid) {
        while ((temp = getc(fid)) != EOF)
            putchar(temp);
    }
    cout<<"=============FIN DU DEBUG"<<endl;
}

int parseOption(int argc, char** argv)
{
    FILE * fid;
    char * nomFichier =argv[2];
    fid=fopen(nomFichier ,"r");
    if(fid!=NULL)
    {
        int returnCode = 0;
        #ifdef DEBUG
        catDatFile(fid,nomFichier);
        rewind(fid);
        #endif
        Document* rootDoc = parseFile(fid);
        if(rootDoc!=NULL)
        {
            rootDoc->versFlux(std::cout);
            fclose(fid);
            return 0;
        }
        else
        {
            return 2;
        }
    }
    else
    {
        return 1;
    }
}
int validateOption(int argc, char** argv)
{
    //Le fichier XML
    FILE * fidXML;
    char * nomFichierXML =argv[2];
    fidXML=fopen(nomFichierXML ,"r");

    //Le fichier XSD
    FILE * fidXSD;
    char * nomFichierXSD =argv[3];
    fidXSD=fopen(nomFichierXSD ,"r");

    if(fidXML && fidXSD)
    {
        Document* docXML = parseFile(fidXML);
        Document* docXSD = parseFile(fidXSD);
        if(!docXML || !docXSD)
        {
            return 3;
        }
        bool valid = docXML->validationXSD(*docXSD);
        if(valid)
        {
            cout << "The file " << nomFichierXML << " is valid wrt " << nomFichierXSD << endl;

        }
        else
        {
            cout << "The file " << nomFichierXML << " is not valid wrt " << nomFichierXSD << endl;
        }
	return 0;
    }
    else if (!fidXML)
    {
        return 1;
    }
    else if (!fidXSD)
    {
        return 2;
    }
    else
    {
        return 3;
    }
}
int templateOption(int argc, char** argv)
{
    //Le fichier XML
    FILE * fidXML;
    char * nomFichierXML =argv[2];
    fidXML=fopen(nomFichierXML ,"r");

    //Le fichier XSL
    FILE * fidXSL;
    char * nomFichierXSL =argv[3];
    fidXSL=fopen(nomFichierXSL ,"r");

    if(fidXML!=NULL&&fidXSL!=NULL)
    {
        Document* docXML = parseFile(fidXML);
        Document* docXSL = parseFile(fidXSL);
        if(!docXML || !docXSL)
        {
            return 3;
        }
        std::string html = docXML->transformationXSL(*docXSL);
        // docXML->versFlux(cout);
        // docXSL->versFlux(cout);
        // cout << html << endl;
        return 0;
    }
    else if (fidXML==NULL)
    {
        return 1;
    }
    else if (fidXSL==NULL)
    {
        return 2;
    }
    else
    {
        return 3;
    }
}
int main(int argc, char** argv)
{
    #ifdef XMLDEBUG
    xmldebug=1;
    #endif
    if (argc>1)
    {
        if(string(argv[1])=="-p")
        {
            if (argc>2)
            {
                int success = parseOption(argc, argv);
                switch(success)
                {

                    
                    case 0:
                    {
                        return 0;
                    }
                    case 1:
                    {
                        cerr<<"Unable to open "<<argv[2]<<endl;
                        return 1;
                    }
                    case 2:
                    {
                        cerr<<"No root markup"<<endl;
                        return 1;
                    }
                    case 3:
                    {
                        #ifdef DEBUG
                        cerr<<"Parsing error"<<endl;
                        #endif
                    }
                }
                
            }
            else
            {
                cerr<<"You must provide an argument to the command -p"<<endl;
                return 1;
            }
        }
        else if(string(argv[1])=="-t")
        {
            if (argc>3)
            {
                int success = templateOption(argc, argv);
                switch(success)
                {
                    case 0:
                    {
                        return 0;
                    }
                    case 1:
                    {
                        cerr<<"Unable to open file "<<argv[2]<<endl;
                        return 1;
                    }
                    case 2:
                    {
                        cerr<<"Unable to open file "<<argv[3]<<endl;
                        return 1;
                    } 
                }

                return 0;
            }
            else
            {
                cerr<<"You must provide two arguments to the command -t: an xml file and an xsl file"<<endl;
                return 1;
            }
        }
        else if(string(argv[1])=="-v")
        {
            if (argc>3)
            {
                int success = validateOption(argc, argv);
                switch(success)
                {
                    case 0:
                    {
                        return 0;    
                    }
                    case 1:
                    {
                        cerr<<"Unable to open file "<<argv[2]<<endl;
                        return 1;
                    }
                    case 2:
                    {
                        cerr<<"Unable to open file "<<argv[3]<<endl;
                        return 1;
                    }
                    case 3:
                    {
                        cerr<<"No root markup"<<endl;
                        return 1;
                    }
                }
                    
            }
            else
            {
                cerr<<"You must provide two arguments to the command -v: an xml file and an xsd file"<<endl;
                return 1;
            }
        }
        else if(string(argv[1])=="-h")
        {
            cerr<<"Available commands are:"<<endl;
            cerr<<
            argv[0]<<" -p file.xml : parse and display the xml file"<<endl<<
            argv[0]<<" -v file.xml file.xsd : parse both xml and xsd files and display the validation result"<<endl<<
            argv[0]<<" -t file.xml file.xsl : parse both xml and xsl files and display de transformation result of file.xml by the stylesheet file.xsl"<<endl<<
            argv[0]<<" -h : displays this help"<<endl;
            return 1;
        }
    }
    else
    {
        cerr<<"No argument given"<<endl;
        cerr<<"Available commands are:"<<endl;
        cerr<<
        argv[0]<<" -p file.xml : parse and display the xml file"<<endl<<
        argv[0]<<" -v file.xml file.xsd : parse both xml and xsd files and display the validation result"<<endl<<
        argv[0]<<" -t file.xml file.xsl : parse both xml and xsl files and display de transformation result of file.xml by the stylesheet file.xsl"<<endl<<
        argv[0]<<" -h : displays this help"<<endl;
        return 1;
    }
    return 1;
}
// int main(int argc, char** argv)
// {
//     // xmldebug=1;
//     namespace po=boost::program_options;
//     // Handling of options 
//     po::options_description desc("Available commands are");
//     desc.add_options()
//     ("parse,p",po::value<std::vector<std::string>>(),"parse and display the xml file")
//     ("validate,v", po::value<std::vector<std::string>>(), "parse both xml and xsd files and display the validation result")
//     ("transforme,t",po::value<std::vector<std::string>>(),"parse both xml and xsl files and display de transformation result of file.xml by the stylesheet file.xsl")
//     ("help,h","displays this help");


//     po::positional_options_description p;
//     p.add("parse", -1);
//     p.add("validate", 2);
//     p.add("trasnform", 2);
// // parse the options
//     po::variables_map vm;
//     po::store(po::command_line_parser(argc, argv).options(desc).positional(p).run(), vm);
//     po::notify(vm);


//     if(vm.count("help"))
//     {
//         std::cerr <<argv[0]<<" "<<desc<<endl<<argv[1];
//     }
//     else if(vm.count("parse")){
//         std::vector<std::string> files = vm["parse"].as<std::vector<std::string>>();
//         #ifdef DEBUG
//         for(std::string file : files){
//             std::cout << "Input file " << file << std::endl;
//         }
//         cout<<"First argument : "<<files[0]<<endl;
//         #endif
//         FILE * fid;
//         fid=fopen(files[0].c_str() ,"r");
//         #ifdef DEBUG
//         int temp;
//         if (fid) {
//             while ((temp = getc(fid)) != EOF)
//                 putchar(temp);
//         }
//         cout<<"FIN DU DEBUG"<<endl;
//         fclose(fid);
//         fid=fopen(files[0].c_str() ,"r");
//         #endif
//         xmlin=fid;
//         Document* rootDoc=NULL;
//         int b=xmlparse(&rootDoc);
//         rootDoc->versFlux(std::cout);
//         fclose(fid);
//     }
//     else
//     {

//         FILE * fid;
//         fid=fopen("files/simple_no_att.xml" ,"r");
//         #ifdef DEBUG
//         int temp;
//         if (fid) {
//             while ((temp = getc(fid)) != EOF)
//                 putchar(temp);
//         }
//         cout<<"FIN DU DEBUG"<<endl;
//         fclose(fid);
//         fid=fopen("files/simple_no_att.xml" ,"r");
//         #endif
//         xmlin=fid;
//         Document* rootDoc=NULL;
//         int b=xmlparse(&rootDoc);
//         rootDoc->versFlux(std::cout);
//         fclose(fid);
//     }
//     // else
//     // {
//     //     cerr<<"No argument given"<<endl;
//     //     std::cerr <<argv[0]<<" "<<desc<<endl;
//     //     return 0;
//     // }
//    // int retour = xmlparse();
//    // if (!retour)
//    // {
//    //    cout<<"Entrée standard reconnue"<<endl;
//    // }
//    // else
//    // {
//    //    cout<<"Entrée standard non reconnue"<<endl;
//    // }
//     return 1;
// }
