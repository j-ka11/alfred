#pragma once

#include <vector>
#include "Container.h"

namespace Alfred {

    class Blob : public Container {
    public:
        Blob();
        ~Blob();
    private:
        std::vector<Container> *members;
    };
}