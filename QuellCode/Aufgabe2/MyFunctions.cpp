/*
 * MyFunctions.cpp
 *
 *  Created on: 14.12.2019
 *      Author: Yunze Han
 */

#include <cmath>
#include <iostream>
#include "MyFunctions.h"
#define PI acos(-1.0)

using namespace std;

MyQuaternion quaternion_rotation(double x,double y,double z,double const theta){

  // Quellcode implememtieren
	double c =sqrt(pow(x,2.) +pow(y,2.) +pow(z,2.));
	MyQuaternion tmp;
	tmp[0]=x/c*sin(theta*PI/(180*2));
	tmp[1]=y/c*sin(theta*PI/(180*2));
	tmp[2]=z/c*sin(theta*PI/(180*2));
	tmp[3]=cos(theta*PI/(180*2));
	return tmp;
}

MyQuaternion rotateX(MyQuaternion const &X,MyQuaternion const &Q){
  // Quellcode implementieren: und auch in Aufgabe3 einfügen
	MyQuaternion tmp;
	for(auto i =0 ; i< 3;++i)
		tmp[i]=-Q[i];
	tmp[3]=Q[3];
	return Q*X*tmp;

}


/*
 *  vorgegeben:
 *
 */
void Qprint(const MyQuaternion &Q,const std::string txt=""){
	cout<<txt<<"("<<Q[0]<<","<<Q[1]<<","<<Q[2]<<","<<Q[3]<<")"<<endl;
}

