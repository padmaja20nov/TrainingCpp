#include <iostream>
#include <string>

using namespace std;

class Device {

protected:
string deviceName;

public:

Device (string deviceName) {
        this->deviceName = deviceName;
}

string getName () {
        return deviceName;
}

virtual void connectToCPU () = 0;

virtual ~Device () {}
};

class InputDevice : public virtual Device {

public:
InputDevice (string devName) : Device(devName) {
}

virtual void processInput() {}
virtual void connectToCPU () {}
virtual ~InputDevice(){}
};

class OutputDevice : public virtual Device {

public:
OutputDevice (string devName) : Device(devName) {
}
virtual void processOutput() {}
virtual void connectToCPU () {}
virtual ~OutputDevice() {}
};

class IODevice : public InputDevice, public OutputDevice {

public:

IODevice (string devName) : InputDevice(devName), OutputDevice(devName), Device(devName) {
}

void processInput () {
        cout << "Processing Input";
}

void processOutput () {
        cout << "Processing Output";
}

virtual void connectToCPU () {
        cout << "Connecting to CPU IO \n";
}
virtual ~IODevice(){}
};

int main () {

InputDevice* scanner = new InputDevice("Scanner");
cout << scanner->getName();

Device* printScanDev = new IODevice("PrintScan");
printScanDev->connectToCPU();

return 0;
}
