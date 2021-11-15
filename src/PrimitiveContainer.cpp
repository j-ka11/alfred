#include "PrimitiveContainer.h"
#include <iostream>

using namespace Alfred;

PrimitiveContainer::PrimitiveContainer() {
	this->dataSizeInBytes = -1;
}

PrimitiveContainer::PrimitiveContainer(int data) {
	this->isANumber = true;
	this->dataSizeInBytes = sizeof(int);
	this->dataptr = malloc(this->dataSizeInBytes);
	*(int*)dataptr = data;
}

PrimitiveContainer::PrimitiveContainer(std::string data) {
	this->isANumber = false;
	this->dataSizeInBytes = data.size();
	this->dataptr = malloc(this->dataSizeInBytes);
	char* tempptr = (char*)this->dataptr;
	for (int i = 0; i < this->dataSizeInBytes; i++) {
		*tempptr = data.at(i);
		tempptr++;
	}
}

bool PrimitiveContainer::getData(int& data) {
	if (!this->isANumber) {
		return false;
	}
	if (this->dataSizeInBytes != sizeof(int)) {
		return false;
	}

	data = *(int*)this->dataptr;
	return true;
}

bool PrimitiveContainer::getData(std::string& data) {
	if (this->isANumber) {
		return false;
	}
	if (this->dataSizeInBytes < 1) {
		return false;
	}

	char* tempptr = (char*)malloc(this->dataSizeInBytes);
	char* movingptr = tempptr;
	for (int i = 0; i < this->dataSizeInBytes; i++) {
		*movingptr = *(((char*)this->dataptr) + i);
		movingptr++;
	}
	data.assign(tempptr, this->dataSizeInBytes);
	free(tempptr);
	return true;
}
