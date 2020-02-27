/*
 * FlightMechanics.cpp
 * Created on : 20-01-2020 09:00
 *	   Author : eren.dere
 */

#include "FlightMechanics.h"

#include <Simulator.h>
#include <EngagementData.h>

extern Simulator *simulator;

FlightMechanics::FlightMechanics() {
	// TODO Auto-generated constructor stub

}

FlightMechanics::~FlightMechanics() {
	// TODO Auto-generated destructor stub
}

void FlightMechanics::initialize(){
	// TODO : kullanici bu fonksiyon icinde sinif attribute 'lerini doldurmak zorundadir
	// ek olarak baska degiskenler de tanimlanabilir

	this->alpha =  // TODO Elle doldurulacak;
	this->beta =  // TODO Elle doldurulacak;
	this->vel_BE_B =  // TODO Elle doldurulacak;
	this->om_BI_B =  // TODO Elle doldurulacak;
	this->boost_coast =  // TODO Elle doldurulacak;
	this->DCM_be =  // TODO Elle doldurulacak;
	this->pos_BE_B =  // TODO Elle doldurulacak;
	this->euler_angles =  // TODO Elle doldurulacak;
	this->a_BE_B =  // TODO Elle doldurulacak;
	this->DCM_bf =  // TODO Elle doldurulacak;
	this->DCM_bi =  // TODO Elle doldurulacak;
	this->DCM_if =  // TODO Elle doldurulacak;
	this->DCM_ef =  // TODO Elle doldurulacak;
	this->DCM =  // TODO Elle doldurulacak;
	this->LLA =  // TODO Elle doldurulacak;
	this->pos_BI_B =  // TODO Elle doldurulacak;
	this->om_BI_B_dot =  // TODO Elle doldurulacak;
	this->quat_BE =  // TODO Elle doldurulacak;
	this->quat_BE_dot =  // TODO Elle doldurulacak;
	this->speed =  // TODO Elle doldurulacak;
	this->force_B =  // TODO Elle doldurulacak;
	this->moment_B =  // TODO Elle doldurulacak;
}


void FlightMechanics::sendEngagementData() {



}

void FlightMechanics::act() {

	/**
	 * _local ile biten degiskenler, baglantilar kullanilarak
	 * cekilmesi gereken modullerden cekilmis degiskenlerdir
	 * kullanicinin baglantilari dusunmesine gerek kalmadan
	 * bu degiskenleri kullanmasi amaclanmistir
	 */
	Matrix aero_moment; //TODO matrislerin boyutu girilmeli
	Matrix gravitational_force; //TODO matrislerin boyutu girilmeli
	Matrix prop_moment; //TODO matrislerin boyutu girilmeli
	double mass = 0;
	Matrix aero_force; //TODO matrislerin boyutu girilmeli
	Matrix inertia_dot; //TODO matrislerin boyutu girilmeli
	Matrix inertia; //TODO matrislerin boyutu girilmeli
	Matrix prop_force; //TODO matrislerin boyutu girilmeli
	
	


	try {
		Connection *connection_aerodynamics_flightMechanics = connectionMap.at("aero_moment");
		ServiceFunction *handler_aerodynamics_flightMechanics = new ServiceFunction();
		handler_aerodynamics_flightMechanics->Matrix_function = connection_aerodynamics_flightMechanics->getHandler().Matrix_function;
		aero_moment = handler_aerodynamics_flightMechanics->Matrix_function();
	} catch(std::exception &e) {}

	try {
		Connection *connection_gravity_flightMechanics = connectionMap.at("gravitational_force");
		ServiceFunction *handler_gravity_flightMechanics = new ServiceFunction();
		handler_gravity_flightMechanics->Matrix_function = connection_gravity_flightMechanics->getHandler().Matrix_function;
		gravitational_force = handler_gravity_flightMechanics->Matrix_function();
	} catch(std::exception &e) {}

	try {
		Connection *connection_propulsion_flightMechanics = connectionMap.at("prop_moment");
		ServiceFunction *handler_propulsion_flightMechanics = new ServiceFunction();
		handler_propulsion_flightMechanics->Matrix_function = connection_propulsion_flightMechanics->getHandler().Matrix_function;
		prop_moment = handler_propulsion_flightMechanics->Matrix_function();
	} catch(std::exception &e) {}

	try {
		Connection *connection_massInertia_flightMechanics = connectionMap.at("mass");
		ServiceFunction *handler_massInertia_flightMechanics = new ServiceFunction();
		handler_massInertia_flightMechanics->double_function = connection_massInertia_flightMechanics->getHandler().double_function;
		mass = handler_massInertia_flightMechanics->double_function();
	} catch(std::exception &e) {}

	try {
		Connection *connection_aerodynamics_flightMechanics = connectionMap.at("aero_force");
		ServiceFunction *handler_aerodynamics_flightMechanics = new ServiceFunction();
		handler_aerodynamics_flightMechanics->Matrix_function = connection_aerodynamics_flightMechanics->getHandler().Matrix_function;
		aero_force = handler_aerodynamics_flightMechanics->Matrix_function();
	} catch(std::exception &e) {}

	try {
		Connection *connection_massInertia_flightMechanics = connectionMap.at("inertia_dot");
		ServiceFunction *handler_massInertia_flightMechanics = new ServiceFunction();
		handler_massInertia_flightMechanics->Matrix_function = connection_massInertia_flightMechanics->getHandler().Matrix_function;
		inertia_dot = handler_massInertia_flightMechanics->Matrix_function();
	} catch(std::exception &e) {}

	try {
		Connection *connection_massInertia_flightMechanics = connectionMap.at("inertia");
		ServiceFunction *handler_massInertia_flightMechanics = new ServiceFunction();
		handler_massInertia_flightMechanics->Matrix_function = connection_massInertia_flightMechanics->getHandler().Matrix_function;
		inertia = handler_massInertia_flightMechanics->Matrix_function();
	} catch(std::exception &e) {}

	try {
		Connection *connection_propulsion_flightMechanics = connectionMap.at("prop_force");
		ServiceFunction *handler_propulsion_flightMechanics = new ServiceFunction();
		handler_propulsion_flightMechanics->Matrix_function = connection_propulsion_flightMechanics->getHandler().Matrix_function;
		prop_force = handler_propulsion_flightMechanics->Matrix_function();
	} catch(std::exception &e) {}



	/**
	 * TODO Kullanicinin bu satirdan sonrasini doldurmasi bekleniyor
     */
}


