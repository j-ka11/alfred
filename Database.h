#pragma once

#include <iostream>
#include <unordered_map>
#include "Keyable.h"
#include "Valuable.h"

namespace Alfred {

	class Database {
	public:
		Database();
		~Database();

		static bool push(Keyable* key, Valuable* value);
	private:
		static std::unordered_map<Keyable*, Valuable*> *data;
	};

}
