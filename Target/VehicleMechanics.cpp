/*
 * VehicleMechanics.cpp
 * Created on : 20-01-2020 09:00
 *	   Author : eren.dere
 */

#include "VehicleMechanics.h"

#include <Simulator.h>
#include <EngagementData.h>

extern Simulator *simulator;

VehicleMechanics::VehicleMechanics() {
	// TODO Auto-generated constructor stub

}

VehicleMechanics::~VehicleMechanics() {
	// TODO Auto-generated destructor stub
}

void VehicleMechanics::initialize(){
	// TODO : kullanici bu fonksiyon icinde sinif attribute 'lerini doldurmak zorundadir
	// ek olarak baska degiskenler de tanimlanabilir

	this->xyz =  // TODO Elle doldurulacak;
}


void VehicleMechanics::sendEngagementData() {

	simulator->getEngagement()->setEngagementDataMap(this,xyz, this->getName() + "_xyz",EngagementServiceType::POSITION);


}

void VehicleMechanics::act() {

	/**
	 * _local ile biten degiskenler, baglantilar kullanilarak
	 * cekilmesi gereken modullerden cekilmis degiskenlerdir
	 * kullanicinin baglantilari dusunmesine gerek kalmadan
	 * bu degiskenleri kullanmasi amaclanmistir
	 */
	
	




	/**
	 * TODO Kullanicinin bu satirdan sonrasini doldurmasi bekleniyor
     */
}


