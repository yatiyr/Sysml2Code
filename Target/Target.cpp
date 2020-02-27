/*
 * Target.cpp
 *
 * Created on : 20-01-2020 09:00
 *	   Author : eren.dere
 */

#include "Target.h"
#include <Utils.h>
#include <Simulator.h>

extern Simulator *simulator;

Target::Target() {

}

Target::~Target() {
	// TODO Auto-generated destructor stub
}


void Target::createModules() {

/**
 * TODO: Ek kodlar buraya yazilabilir
 */

	/**
	 * Bu kisimda sadece moduller tanitiliyor.
	 * Sirasi onemli degil.
	 */
	posInfo = new VehicleMechanics();
	posInfo->setName("posInfo");
	posInfo->setLaunchTime(this->getLaunchTime());
	posInfo->setExitSimulationTime(this->getExitSimulationTime());
	simulator->getEngagement()->registerModule(posInfo);



	/**
	 * 	Connect agents and modules
	 * 	Burada Connectionlar belirleniyor
	 */

	ServiceFunction *handler;
	Connection *conn;




	/**
	 * Run daki Siralama Gecerli
	 * Bu kisimda sadece Run daki siralamalar yapiliyor
	 */
	addEntity(posInfo);



	posInfo->initialize();

}
