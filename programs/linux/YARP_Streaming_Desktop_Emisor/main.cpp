//****************************************************
//****************************************************
//
//              YARP: Streaming Desktop
//
//              Tipo: Emisor
//
//              Autor: David Velasco García
//		       @davidvelascogarcia
//
//****************************************************
//****************************************************

// Librerias

#include <iostream>
#include <yarp/os/all.h>
#include <yarp/sig/all.h>
#include <opencv2/opencv.hpp>
#include <yarp/sig/Image.h>


// Espacios de nombres

using namespace yarp::os;
using namespace yarp::sig;
using namespace yarp::sig::draw;
using namespace cv;
using namespace std;

int main()
{
    cout<< "Bienvenido al emisor de escritorio en streaming vía YARP"<<endl;
    cout<<endl;
    cout<<endl;
    Network yarp;
    cout<<"Iniciando red de YARP..."<<endl;
    Port puerto_envio;  	
    cout<<"Iniciando cliente..."<<endl;
    cout<<"Abriendo puerto de envío con nombre /emisor_desktop"<<endl;
    puerto_envio.open("/emisor_desktop");
//    Network::connect("/emisor_desktop","/receptor_desktop");
    cout<<"Enviando fuentes de imágen.."<<endl;
    Mat imagen;
	ImageOf<PixelBgr> B; 
	while(true)
	{	
		system("import -window root desktop.jpg");
		imagen=imread("desktop.jpg");	
   		B.setExternal(imagen.data,imagen.size[1],imagen.size[0]);
   		puerto_envio.write(B); 
		system("rm desktop.jpg");

}

    return 0;

}






