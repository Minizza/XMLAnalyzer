#include "commun.h"
#include "enTete.h"
#include <iostream>
#include <cstring>
#include <typeinfo>

using namespace std;

extern FILE* xmlin;
extern int xmldebug;
int xmlparse(Document**);

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
        #ifdef DEBUG
        catDatFile(fid,nomFichier);
        rewind(fid);
        #endif
        xmlin=fid;
        Document* rootDoc=NULL;
        int b=xmlparse(&rootDoc);
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

}
int templateOption(int argc, char** argv)
{

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
                        cerr<<"Parsing failed"<<endl;
                        return 1;
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
                templateOption(argc, argv);
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
                validateOption(argc, argv);
                return 0;
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