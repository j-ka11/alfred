#include "Database.h"

using namespace Alfred;

std::unordered_map<Keyable*, Valuable*> *Database::data;

Database::Database() {
	data = new std::unordered_map<Keyable*, Valuable*>();
}

Database::~Database() {
	delete data;
}

bool Database::push(Keyable* key, Valuable* value) {
	return data->emplace(key, value).second;
}
