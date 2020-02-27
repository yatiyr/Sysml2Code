																																																									/*
 * Aerodynamics.cpp
 * Created on : 20-01-2020 09:00
 *	   Author : eren.dere
 */

#include "Aerodynamics.h"

#include <Simulator.h>
#include <EngagementData.h>

extern Simulator *simulator;

Aerodynamics::Aerodynamics() {
	// TODO Auto-generated constructor stub

}

Aerodynamics::~Aerodynamics() {
	// TODO Auto-generated destructor stub
}

void Aerodynamics::initialize(){
	// TODO : kullanici bu fonksiyon icinde sinif attribute 'lerini doldurmak zorundadir
	// ek olarak baska degiskenler de tanimlanabilir

	this->aero_force =  // TODO Elle doldurulacak;
	this->aero_moment =  // TODO Elle doldurulacak;
}


void Aerodynamics::sendEngagementData() {



}

void Aerodynamics::act() {


	bool boost_coast = 0;
	Matrix vel_BE_B; //TODO matrislerin boyutu girilmeli
	double beta = 0;
	double alpha = 0;
	Matrix xcg; //TODO matrislerin boyutu girilmeli
	Matrix om_BI_B; //TODO matrislerin boyutu girilmeli
	
	


	try {
		Connection *connection_flightMechanics_aerodynamics = connectionMap.at("boost_coast");
		ServiceFunction *handler_flightMechanics_aerodynamics = new ServiceFunction();
		handler_flightMechanics_aerodynamics->bool_function = connection_flightMechanics_aerodynamics->getHandler().bool_function;
		boost_coast = handler_flightMechanics_aerodynamics->bool_function();
	} catch(std::exception &e) {}

	try {
		Connection *connection_flightMechanics_aerodynamics = connectionMap.at("vel_BE_B");
		ServiceFunction *handler_flightMechanics_aerodynamics = new ServiceFunction();
		handler_flightMechanics_aerodynamics->Matrix_function = connection_flightMechanics_aerodynamics->getHandler().Matrix_function;
		vel_BE_B = handler_flightMechanics_aerodynamics->Matrix_function();
	} catch(std::exception &e) {}

	try {
		Connection *connection_flightMechanics_aerodynamics = connectionMap.at("beta");
		ServiceFunction *handler_flightMechanics_aerodynamics = new ServiceFunction();
		handler_flightMechanics_aerodynamics->double_function = connection_flightMechanics_aerodynamics->getHandler().double_function;
		beta = handler_flightMechanics_aerodynamics->double_function();
	} catch(std::exception &e) {}

	try {
		Connection *connection_flightMechanics_aerodynamics = connectionMap.at("alpha");
		ServiceFunction *handler_flightMechanics_aerodynamics = new ServiceFunction();
		handler_flightMechanics_aerodynamics->double_function = connection_flightMechanics_aerodynamics->getHandler().double_function;
		alpha = handler_flightMechanics_aerodynamics->double_function();
	} catch(std::exception &e) {}

	try {
		Connection *connection_massInertia_aerodynamics = connectionMap.at("xcg");
		ServiceFunction *handler_massInertia_aerodynamics = new ServiceFunction();
		handler_massInertia_aerodynamics->Matrix_function = connection_massInertia_aerodynamics->getHandler().Matrix_function;
		xcg = handler_massInertia_aerodynamics->Matrix_function();
	} catch(std::exception &e) {}

	try {
		Connection *connection_flightMechanics_aerodynamics = connectionMap.at("om_BI_B");
		ServiceFunction *handler_flightMechanics_aerodynamics = new ServiceFunction();
		handler_flightMechanics_aerodynamics->Matrix_function = connection_flightMechanics_aerodynamics->getHandler().Matrix_function;
		om_BI_B = handler_flightMechanics_aerodynamics->Matrix_function();
	} catch(std::exception &e) {}



	/**
	 * TODO Kullanicinin bu satirdan sonrasini doldurmasi bekleniyor
     */
}


