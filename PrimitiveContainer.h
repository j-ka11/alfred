#pragma once

#include <stdlib.h>
#include <string>
#include "Container.h"

namespace Alfred {

	class PrimitiveContainer : public Container {
	public:
		PrimitiveContainer();
		PrimitiveContainer(int data);
		PrimitiveContainer(std::string data);

		bool getData(int& data);
		bool getData(std::string& data);
	private:
		int dataSizeInBytes;
		void* dataptr;
	};

}
