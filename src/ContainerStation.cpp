#include "ContainerStation.h"

using namespace Alfred;

ContainerStation* ContainerStation::me = nullptr;

ContainerStation* ContainerStation::getInstance() {
	/*if (me == nullptr) {
		me = new ContainerStation();
	}
	return me;*/
	return nullptr;
}
