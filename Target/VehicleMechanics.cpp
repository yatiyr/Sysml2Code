/*
 * VehicleMechanics.cpp
 * Created on : 02-03-2020 04:01
 *	   Author : eren.dere
 */

#include "VehicleMechanics.h"

#include <Simulator.h>
#include <EngagementData.h>

extern Simulator *simulator;

VehicleMechanics::VehicleMechanics() {


}

VehicleMechanics::~VehicleMechanics() {

}

void VehicleMechanics::initialize(){
	// TODO : user must write initial values 
	// additional variables can be introduced

	this->position = Matrix(3,1); // TODO: Give value;
	this->position(0,0) = 100;
	this->position(1,0) = 70;
	this->xPos.open("targetXpos.txt");
	this->yPos.open("targetYpos.txt");
}

void VehicleMechanics::sendEngagementData() {


}

void VehicleMechanics::act() {

	// local variables coming from the connections
	
	




	/**
	 * TODO User should specify the behaviour of the module by 
	 * writing code to this part.
     */

	this->position(0,0) += 2.447513812154696;
	this->position(1,0) += 0.6952596685082872;

	this->xPos << this->position(0,0) << std::endl;
	this->yPos << this->position(1,0) << std::endl;
}

