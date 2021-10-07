#include "ContainerStation.h"

using namespace Alfred;

ContainerStation* ContainerStation::getInstance() {
	if (me == nullptr) {
		me = new ContainerStation();
	}
	return me;
}
