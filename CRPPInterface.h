#ifndef CRPPINTERFACE_H
#define CRPPINTERFACE_H
#include "Interface.h"
// Class for interface of previously registered patient in the hospital
class CRPPInterface : public Interface {
    public:
    CRPPInterface() {}
    CRPPInterface(Hospital* hospital1) {this->hospital = hospital1;}
    void writeOnFile();

};

#endif