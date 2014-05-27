/* 
 * File:   main.cpp
 * Author: slenderman
 *
 * Created on 19 de mayo de 2014, 10:53 AM
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <curl/curl.h>//para conectarnos con el sitio
#include <cstring>
#include <ctime>
#include <libxml2/libxml/parser.h>
#include <libxml2/libxml/xmlversion.h>
#include <libxml2/libxml/tree.h>
#include <libxml2/libxml/xmlstring.h>
//#include<openssl/blowfish.h>


using namespace std;


/*
 * 
 */
//string data;
//size_t writeCallback(char* buf, size_t size, size_t nmemb, void* up)
//{ //callback must have this declaration
//    //buf is a pointer to the data that curl has for us
//    //size*nmemb is the size of the buffer
//
//    for (int c = 0; c<size*nmemb; c++)
//    {
//        data.push_back(buf[c]);
//    }
//    return size*nmemb; //tell curl how many bytes we handled
//}
static size_t data_write(void* buf, size_t size, size_t nmemb, void* userp)
{
	if(userp)
	{
		std::ostream& os = *static_cast<std::ostream*>(userp);
		std::streamsize len = size * nmemb;
		if(os.write(static_cast<char*>(buf), len))
			return len;
	}

	return 0;
}

/**
 * timeout is in seconds
 **/
CURLcode curl_read(const std::string& url, std::ostream& os, long timeout = 30)
{
	CURLcode code(CURLE_FAILED_INIT);
	CURL* curl = curl_easy_init();
        struct curl_slist *headers=NULL; // iniciar como NULL 
        headers = curl_slist_append(headers, "Accept: application/xml");

	if(curl)
	{
		if(CURLE_OK == (code = curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &data_write))
		&& CURLE_OK == (code = curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L))
		&& CURLE_OK == (code = curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L))
		&& CURLE_OK == (code = curl_easy_setopt(curl, CURLOPT_FILE, &os))
		&& CURLE_OK == (code = curl_easy_setopt(curl, CURLOPT_TIMEOUT, timeout))
		&& CURLE_OK == (code = curl_easy_setopt(curl, CURLOPT_URL, url.c_str()))
                && CURLE_OK ==(code = curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers))
                  )
		{
			code = curl_easy_perform(curl);
		}
		curl_easy_cleanup(curl);
	}
	return code;
}
void obtenerxmldesitio(){
//  
    string direccion="http://sebastian.cl/isw-rest/api/mensajeCifrado";
//    
//    
curl_global_init(CURL_GLOBAL_ALL);

	std::ofstream ofs("mensajerecibido.xml");
	if(CURLE_OK == curl_read(direccion, ofs))
	{
		// Web page successfully written to file
            cout << "Retorna Fichero de Nombre mensajeresibido.xml"<< endl;
	}

//	std::ostringstream oss;
//	if(CURLE_OK == curl_read(direccion, ofs))
//	{
//		// se guarda el codigo del xml en un string
//		std::string html = oss.str();
//	}

	if(CURLE_OK == curl_read(direccion, std::cout))
	{
		// se muestra el archivo xml en la consola
	}

	curl_global_cleanup();
}
static void print_element_names(xmlNode * a_node)
{
    xmlNode *cur_node = NULL;
    xmlChar *valor;
 
 
    for (cur_node = a_node; cur_node; cur_node = cur_node->next) {
        if (cur_node->type == XML_ELEMENT_NODE) {
            valor=xmlNodeGetContent(cur_node);
            
                cout <<endl<< cur_node->name <<":"<<valor<<endl;
                
           // printf("node type: Element, name: %s\n", cur_node->name);
        }
 
        print_element_names(cur_node->children);
    }
}
void leerxml(){
    xmlDoc *documento=NULL;
    xmlNode *elementos_root=NULL;
    
    LIBXML_TEST_VERSION
            
    documento =xmlReadFile("mensajerecibido.xml",NULL,0);
    if(documento == NULL){
        cout <<"error no sepuede leer el fichero"<< endl;
        
    }
 elementos_root = xmlDocGetRootElement(documento);
 
    print_element_names(elementos_root);
 
    /*Libera la memoria usada para almacenar el árbol que representa el DOM*/
    xmlFreeDoc(documento);
 
    /*
     *Libera las variables globales que pudieron haber sido alocadas por el parser.
     */
    xmlCleanupParser();
  
};

int main(int argc, char** argv) {
    
    string opcion1="-d";
    string opcion2="-v";
    for(int i=1;i<argc;i++)
        if(argv[1]== opcion1)
        {
            obtenerxmldesitio();
            leerxml();
        }else{
        if(argv[1]==opcion2){
            
            
                                cout << "Fecha de compilacion: " << __DATE__ << " " << __TIME__ << endl;
                                cout <<"Grupo(8)"<<endl;
                                cout <<"**********************"<<endl;
                                cout << "Jose Acuña"<< endl<< "Christian Trujillo"<< endl<< "Luis Sandoval"<<endl;
                                system("date \t");
        }else{
            
            if(argv[1]==" ")
                cout <<"ingrese opcion ";
        
        }
    }
    
    return 0;
}

