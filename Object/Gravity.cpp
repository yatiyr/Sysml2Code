/*
 * Gravity.cpp
 * Created on : 20-01-2020 09:00
 *	   Author : eren.dere
 */

#include "Gravity.h"

#include <Simulator.h>
#include <EngagementData.h>

extern Simulator *simulator;

Gravity::Gravity() {
	// TODO Auto-generated constructor stub

}

Gravity::~Gravity() {
	// TODO Auto-generated destructor stub
}

void Gravity::initialize(){
	// TODO : kullanici bu fonksiyon icinde sinif attribute 'lerini doldurmak zorundadir
	// ek olarak baska degiskenler de tanimlanabilir

	this->gravitational_force =  // TODO Elle doldurulacak;
}


void Gravity::sendEngagementData() {



}

void Gravity::act() {

	/**
	 * _local ile biten degiskenler, baglantilar kullanilarak
	 * cekilmesi gereken modullerden cekilmis degiskenlerdir
	 * kullanicinin baglantilari dusunmesine gerek kalmadan
	 * bu degiskenleri kullanmasi amaclanmistir
	 */
	Matrix DCM_be; //TODO matrislerin boyutu girilmeli
	double mass = 0;
	
	


	try {
		Connection *connection_flightMechanics_gravity = connectionMap.at("DCM_be");
		ServiceFunction *handler_flightMechanics_gravity = new ServiceFunction();
		handler_flightMechanics_gravity->Matrix_function = connection_flightMechanics_gravity->getHandler().Matrix_function;
		DCM_be = handler_flightMechanics_gravity->Matrix_function();
	} catch(std::exception &e) {}

	try {
		Connection *connection_massInertia_gravity = connectionMap.at("mass");
		ServiceFunction *handler_massInertia_gravity = new ServiceFunction();
		handler_massInertia_gravity->double_function = connection_massInertia_gravity->getHandler().double_function;
		mass = handler_massInertia_gravity->double_function();
	} catch(std::exception &e) {}



	/**
	 * TODO Kullanicinin bu satirdan sonrasini doldurmasi bekleniyor
     */
}


