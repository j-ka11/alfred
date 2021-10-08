#pragma once

#include "Keyable.h"
#include "valuable.h"

namespace Alfred {

	class Container: public Keyable, Valuable {
	public:
		Container();
		~Container();
	};

}
