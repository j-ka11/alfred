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
		static Valuable* get(Keyable* key);
	private:
		static std::unordered_map<Keyable*, Valuable*> *data;
	};

}
