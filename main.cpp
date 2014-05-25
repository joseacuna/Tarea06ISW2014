/* 
 * File:   main.cpp
 * Author: slenderman
 *
 * Created on 19 de mayo de 2014, 10:53 AM
 */
#include <iostream>
#include <cstdlib>
#include <curl/curl.h>
#include <cstring>
#include <ctime>

using namespace std;

/*
 * 
 */

//void direccion(){
//    CURL *curl;
//    CURLcode resultado;
//    
//    string direccion="http://sebastian.cl/isw-rest/api/mensajeCifrado";
//    
//    curl = curl_easy_init();
//    
//    if(curl){
//       curl_easy_setopt(curl,CURLOPT_URL,direccion.c_str());
//       
//        resultado=curl_easy_perform(curl);
//        
//        
//                
//        //limpiar curl        
//        curl_easy_cleanup(curl);
//                
//    }
//
//}
int main(int argc, char** argv) {
    
    string opcion1="-d";
    string opcion2="-v";
    for(int i=1;i<argc;i++)
        if(argv[1]== opcion1)
        {
            cout<<"opcion1";
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

