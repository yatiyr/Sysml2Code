/*
 * Propulsion.cpp
 * Created on : 20-01-2020 09:00
 *	   Author : eren.dere
 */

#include "Propulsion.h"

#include <Simulator.h>
#include <EngagementData.h>

extern Simulator *simulator;

Propulsion::Propulsion() {
	// TODO Auto-generated constructor stub

}

Propulsion::~Propulsion() {
	// TODO Auto-generated destructor stub
}

void Propulsion::initialize(){
	// TODO : kullanici bu fonksiyon icinde sinif attribute 'lerini doldurmak zorundadir
	// ek olarak baska degiskenler de tanimlanabilir

	this->prop_force =  // TODO Elle doldurulacak;
	this->prop_moment =  // TODO Elle doldurulacak;
}


void Propulsion::sendEngagementData() {



}

void Propulsion::act() {

	/**
	 * _local ile biten degiskenler, baglantilar kullanilarak
	 * cekilmesi gereken modullerden cekilmis degiskenlerdir
	 * kullanicinin baglantilari dusunmesine gerek kalmadan
	 * bu degiskenleri kullanmasi amaclanmistir
	 */
	Matrix xcg; //TODO matrislerin boyutu girilmeli
	
	


	try {
		Connection *connection_massInertia_propulsion = connectionMap.at("xcg");
		ServiceFunction *handler_massInertia_propulsion = new ServiceFunction();
		handler_massInertia_propulsion->Matrix_function = connection_massInertia_propulsion->getHandler().Matrix_function;
		xcg = handler_massInertia_propulsion->Matrix_function();
	} catch(std::exception &e) {}



	/**
	 * TODO Kullanicinin bu satirdan sonrasini doldurmasi bekleniyor
     */
}


