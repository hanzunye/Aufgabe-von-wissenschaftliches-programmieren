/*
 * main_aufgabe3.cpp
 *
 *  Created on: 14.12.2019
 *      Author:Yunze Han
 */
// ggf hilfreiche Bibliotheken....
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <random>
#include <vector>
#include <array>
#include <cassert>
#define PI acos(-1.0)

#include "MyQuaternion.h"
#include "MyFunctions.h"
using namespace std;

// Abkuerzungen fuer Datentypen:
typedef std::array<double,4> Vec4d;

// for seed of random number generator in C++11
std::random_device rd;
std::mt19937 mt(rd());
std::uniform_real_distribution<double> zufall(-1.,1.); //C++11 documentation
//http://www.cplusplus.com/reference/random/uniform_real_distribution/

//Hilfsfunktion fuer random_vec4d:
void zufall_in_einheitskreis(double &a, double &b, double &s){
	do{
		a = zufall(mt);
		b = zufall(mt);
		s = (a*a+b*b);
	}while(s>=1.);
}

// Algorithm 4 of Marsaglia paper, The Annals of Math. Stat. 1972,645-6
// random point on a surface
// hier: Methode 4: point on unit 4d-sphere
//
void random_vec4d(Vec4d &Q){
	double v1,v2,v3,v4,s1,s2;
	zufall_in_einheitskreis(v1,v2,s1);
	zufall_in_einheitskreis(v3,v4,s2);
	//
	const double tmp = sqrt(max(0.,(1.-s1))/s2);
	Q[0]= v1;
	Q[1]= v2;
	Q[2]= v3*tmp;
	Q[3]= v4*tmp;
}


// Aufgabe 3.2.A:
double get_theta(const MyQuaternion &Q){
	// einfügen..
	double tmp;
	double a= acos(Q[3])*180.0/PI;
	//double b =asin(sqrt(pow(Q[0],2.)+pow(Q[1],2.)+pow(Q[2],2.)))*180.0/PI;
	double b =Q[0]*Q[1]*Q[2];
	if (a<=90 && a!=0)
	{
		 if(b<0)
			 {tmp =360. -a;}
		 else if(b>0)
			 {tmp =a;}
	}
	else if(a>90 && a!= 180)
	{
		if(b>0)
		{tmp = a;}
		else if(b<0)
		{tmp =360. -a;}
	}
	else
	{
		tmp = a;
	}

	return tmp;

}

//Aufgabe 3.2.B:
double get_theta_cubic(const MyQuaternion &Q){
	// einfügen..
	MyQuaternion tmp,tmp2,tmp3;

	double a,b,c,d,x,y,z,s;


	for(auto i=0;i<4;++i){
		tmp[i]=abs(Q[i]);
	}
	if (tmp[0]>=tmp[1]){
		a=tmp[0];
		b=tmp[1];
	}else{
		a=tmp[1];
		b=tmp[0];
	}
	if(tmp[2]>=tmp[3]){
		c=tmp[2];
		d=tmp[3];
	}else{
		c=tmp[3];
		d=tmp[2];
	}


	if(a>=c){
		tmp[3]=a;
		if(b>=c){
			tmp[2]=b;
			tmp[1]=c;
			tmp[0]=d;
		}else{
			tmp[2]=c;
			if(b>=d){
				tmp[1]=b;
				tmp[0]=d;
			}else{
				tmp[1]=d;
				tmp[0]=b;
			}
		}
	}else{
		tmp[3]=c;
		if(d>=a){
			tmp[2]=d;
			tmp[1]=a;
			tmp[0]=b;
		}else{
			tmp[2]=a;
			if(b>=d){
				tmp[1]=b;
				tmp[0]=d;
			}else{
				tmp[1]=d;
				tmp[0]=b;
			}
		}
	}


	tmp2[0]=(tmp[0]-tmp[1])/sqrt(2.);
	tmp2[1]=(tmp[0]+tmp[1])/sqrt(2.);
	tmp2[2]=(tmp[2]-tmp[3])/sqrt(2.);
	tmp2[3]=(tmp[2]+tmp[3])/sqrt(2.);


	tmp3[0]=(tmp[0]-tmp[1]+tmp[2]-tmp[3])/2.;
	tmp3[1]=(tmp[0]+tmp[1]-tmp[2]-tmp[3])/2.;
	tmp3[2]=(-tmp[0]+tmp[1]+tmp[2]-tmp[3])/2.;
	tmp3[3]=(tmp[0]+tmp[1]+tmp[2]+tmp[3])/2.;
	
	

	x=get_theta(tmp);
	y=get_theta(tmp2);
	z=get_theta(tmp3);


	if(x<=y&&x<=z) s=x;
	else if(y<=z&&y<=x) s=y;
	else s=z;

	return s;



}


//

int main(){
	//generate data:
	Vec4d tmp;
	int nmax;

	do{
		cout<<"Anzahl der Zufallsorientierungen eingeben:";
		cin>>nmax;
	}while(nmax<1);

	std::vector<MyQuaternion> QL(nmax);

	//random Initialisierung:
	/*....some code
	 *
	 */

	for (auto i =0 ;i < nmax; ++i)
	{
		random_vec4d(tmp);
		for(auto j=0 ; j< 4;j++)
			QL[i][j]=tmp[j];
	}




	//AUFGABE 3:

	//TEIL A)
	cout<<"Aufgabe A:"<<endl;
	/*some code; calls
	 *
	 */
	//aufgabe_bearbeiten("random",QL,get_theta);

	ofstream Datei;

	Datei.open("ergebnis_random.dat",ios::out | ios::trunc);

	for (auto i =0 ;i < nmax; ++i)
		{
			//MyQuaternion outme;
			for(auto j=0 ; j< nmax;++j)
			{
					if(i!=j)
					{
						MyQuaternion outme;
						for(auto k = 0 ;k<3;++k)
						{
							outme[k]=-QL[j][k];
						}
						outme[3]=QL[j][3];
						Datei<<get_theta(QL[i]*outme)<<endl;
					}

			}

		}
	Datei.close();






	//TEIL B)
	cout<<"Aufgabe B:"<<endl;
	/*some code; calls
	 *
	 */
	// aufgabe_bearbeiten("cube",QL,get_theta_cubic);
	Datei.open("ergebnis_cube.dat",ios::out | ios::trunc);

		for (auto i =0 ;i < nmax; ++i)
			{
				//MyQuaternion outme;
				for(auto j=0 ; j< nmax;++j)
				{
						if(i!=j)
						{
							MyQuaternion outme;
							for(auto k = 0 ;k<3;++k)
							{
								outme[k]=-QL[j][k];
							}
							outme[3]=QL[j][3];
							Datei<<get_theta_cubic(QL[i]*outme)<<endl;
						}

				}

			}
		Datei.close();


	cout<<"DONE"<<endl;

	return 0;
}

