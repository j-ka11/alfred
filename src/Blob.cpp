#include "Blob.h"

Alfred::Blob::Blob() {
    this->members = new std::vector<Container>();
}

Alfred::Blob::~Blob() {
    delete this->members;
}