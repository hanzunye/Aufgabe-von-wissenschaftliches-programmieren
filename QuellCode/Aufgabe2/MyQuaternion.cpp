/*
 * MyQuaternion.cpp
 *
 *  Created on: 2019年12月13日
 *      Author: Yunze Han
 */

#include "MyQuaternion.h"
#include<iostream>
#include <cstddef>
#include <cassert>
using namespace std;

//Konstruktor: MyQuaternion()
MyQuaternion::MyQuaternion() {

	this->dataPtr = new double[4];

}

//Kopierkonstruktor: MyQuaternion(Q)
MyQuaternion::MyQuaternion(const MyQuaternion &Q) {
	this->dataPtr = new double[4];
	for (size_t i =0;i < 4;++i)
		this->dataPtr[i] = Q[i];

}

//Konstruktor mit 4 Argumenten MyQuaternion(𝑒1, 𝑒2, 𝑒3, 𝑒4)
MyQuaternion::MyQuaternion(const double& e1,const double& e2, const double& e3, const double& e4){
	this->dataPtr = new double[4];
	this->dataPtr[0] = e1;
	this->dataPtr[1] = e2;
	this->dataPtr[2] = e3;
	this->dataPtr[3] = e4;
}
//Destructor
MyQuaternion::~MyQuaternion(){
	delete [] this-> dataPtr;
}

//Addition: operator+(QB)
const MyQuaternion MyQuaternion::operator+(const MyQuaternion & QB) const{
	MyQuaternion tmp;
	for (size_t i =0;i < 4;++i)
		tmp.dataPtr[i] = this->dataPtr[i]+QB.dataPtr[i];
	return tmp;

}

//Subtraktion: operator-(QB)
const MyQuaternion MyQuaternion::operator-(const MyQuaternion & QB) const{
	MyQuaternion tmp;
	for (size_t i =0;i < 4;++i)
		tmp.dataPtr[i] = this->dataPtr[i]-QB.dataPtr[i];
	return tmp;
}

//Zugriff auf Komponenten (Setter/Getter): operator[]
double & MyQuaternion::operator[]( size_t const n ){
	assert(n<4);
	return this ->dataPtr[n];
}

//Zugriff lesend (Getter): operator[] const
const double& MyQuaternion::operator[]( std::size_t const n ) const {
	assert(n<4);
	return this->dataPtr[n];
}

//Kopieroperator: operator=(Q_rhs)
MyQuaternion& MyQuaternion::operator= (const MyQuaternion & Q_rhs){
	for(size_t i=0; i<4; ++i)
		this->dataPtr[i]= Q_rhs.dataPtr[i];
	return *this;
}

//Zuweisungsoperator mit Skalar als Argument (operator=(skalar))
MyQuaternion& MyQuaternion::operator= (const double& c){
	for(size_t i=0; i<4; ++i)
		this->dataPtr[i]= c;
	return *this;
}

//conj() const;  =>  gibt konjugierte Quaternion _𝑸A zurück
const MyQuaternion MyQuaternion::conj(){
	MyQuaternion tmp;
	for(size_t i=0; i <3; ++i)
		tmp.dataPtr[i]=-this->dataPtr[i];
	tmp[3]=this->dataPtr[3];
	return tmp;
}

//Berechnung des Produkts zweier Quaternionen: operator*(QB)
MyQuaternion MyQuaternion::operator* (const MyQuaternion& QA) const{
	MyQuaternion tmp;
	tmp[0]= this->dataPtr[0]*QA[3]+this->dataPtr[3]*QA[0]-this->dataPtr[1]*QA[2]+this->dataPtr[2]*QA[1];
	tmp[1]= this->dataPtr[1]*QA[3]+this->dataPtr[3]*QA[1]-this->dataPtr[2]*QA[0]+this->dataPtr[0]*QA[2];
	tmp[2]= this->dataPtr[2]*QA[3]+this->dataPtr[3]*QA[2]-this->dataPtr[0]*QA[1]+this->dataPtr[1]*QA[0];
	tmp[3]= this->dataPtr[3]*QA[3]-this->dataPtr[0]*QA[0]-this->dataPtr[1]*QA[1]-this->dataPtr[2]*QA[2];
	return tmp;
}

//Skalierung aller Komponenten einer Quaternion mit einem Skalar: operator*(Skalar)
MyQuaternion MyQuaternion::operator* (const double& f) const{
	MyQuaternion tmp;
	for(size_t i=0; i<4;++i)
		tmp.dataPtr[i]= (this->dataPtr[i])*f;
	return tmp;
}

