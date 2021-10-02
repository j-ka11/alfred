#pragma once

#include <unordered_map>
#include "Keyable.h"
#include "Valuable.h"

class Database {
public:
	Database();
private:
	static std::unordered_map<Keyable, Valuable> data;
};
