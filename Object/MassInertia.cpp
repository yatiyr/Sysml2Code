/*
 * MassInertia.cpp
 * Created on : 20-01-2020 09:00
 *	   Author : eren.dere
 */

#include "MassInertia.h"

#include <Simulator.h>
#include <EngagementData.h>

extern Simulator *simulator;

MassInertia::MassInertia() {
	// TODO Auto-generated constructor stub

}

MassInertia::~MassInertia() {
	// TODO Auto-generated destructor stub
}

void MassInertia::initialize(){
	// TODO : kullanici bu fonksiyon icinde sinif attribute 'lerini doldurmak zorundadir
	// ek olarak baska degiskenler de tanimlanabilir

	this->inertia =  // TODO Elle doldurulacak;
	this->inertia_dot =  // TODO Elle doldurulacak;
	this->mass =  // TODO Elle doldurulacak;
	this->xcg =  // TODO Elle doldurulacak;
}


void MassInertia::sendEngagementData() {



}

void MassInertia::act() {

	/**
	 * _local ile biten degiskenler, baglantilar kullanilarak
	 * cekilmesi gereken modullerden cekilmis degiskenlerdir
	 * kullanicinin baglantilari dusunmesine gerek kalmadan
	 * bu degiskenleri kullanmasi amaclanmistir
	 */
	Matrix pos_BE_B; //TODO matrislerin boyutu girilmeli
	
	


	try {
		Connection *connection_flightMechanics_massInertia = connectionMap.at("pos_BE_B");
		ServiceFunction *handler_flightMechanics_massInertia = new ServiceFunction();
		handler_flightMechanics_massInertia->Matrix_function = connection_flightMechanics_massInertia->getHandler().Matrix_function;
		pos_BE_B = handler_flightMechanics_massInertia->Matrix_function();
	} catch(std::exception &e) {}



	/**
	 * TODO Kullanicinin bu satirdan sonrasini doldurmasi bekleniyor
     */
}


