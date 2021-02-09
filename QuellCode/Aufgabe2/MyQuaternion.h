/*
 * MyQuaternion.h
 *
 *  Created on: 2019年12月13日
 *      Author: Yunze Han
 */

#ifndef MYQUATERNION_H_
#define MYQUATERNION_H_
#include <vector>
#include<cstdlib>



class MyQuaternion {
public:
	//Konstruktor: MyQuaternion()
	MyQuaternion();

	//Kopierkonstruktor: MyQuaternion(Q)
	MyQuaternion(const MyQuaternion &Q);

	//Konstruktor mit 4 Argumenten MyQuaternion(𝑒1, 𝑒2, 𝑒3, 𝑒4)
	MyQuaternion(const double& e1,const double& e2, const double& e3, const double& e4);

	//Destructor
	~MyQuaternion();

	//Addition: operator+(QB)
	const MyQuaternion operator+ (const MyQuaternion & QB) const;

	//Subtraktion: operator-(QB)
	const MyQuaternion operator- (const MyQuaternion & QB) const;

	//Zugriff auf Komponenten (Setter/Getter): operator[]
	double & operator[] ( std::size_t const n );

	//Zugriff lesend (Getter): operator[] const
	const double & operator[] ( std::size_t const n ) const;

	//Kopieroperator: operator=(Q_rhs)
	MyQuaternion & operator= ( const MyQuaternion & Q_rhs );

	//Zuweisungsoperator mit Skalar als Argument (operator=(skalar))
	MyQuaternion & operator= ( const double& c );

	//conj() const;  =>  gibt konjugierte Quaternion _𝑸A zurück
	const MyQuaternion conj();

	//Berechnung des Produkts zweier Quaternionen: operator*(QB)
	MyQuaternion  operator* (const MyQuaternion& QB) const;

	//Skalierung aller Komponenten einer Quaternion mit einem Skalar: operator*(Skalar)
	MyQuaternion  operator* (const double& f) const;

private:

	double * dataPtr;


};

#endif /* MYQUATERNION_H_ */
