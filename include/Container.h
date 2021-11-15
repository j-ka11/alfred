#pragma once

#include "Keyable.h"
#include "valuable.h"

namespace Alfred {

	class Container: public Keyable, public Valuable {
	public:
		Container();
		~Container();
	};

}
