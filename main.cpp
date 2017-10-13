#include <cstdlib>
#include <iostream> 
#include <string>

using namespace std;
#define className(x) #x
#define NUMBER_OF_WHEELS 4 
#define NUMBER_OF_LIGHTS 10

class Engine 
{
public:
    //creates an engine with a size parameter
    Engine(string size){this->size = size;};
    //checks the block size parameter to see if it matches any pre-set sizes then returns a value
    double getBlockSize(){if(size == "Big Block"){return BigBlock;}
    else if(size == "Medium Block"){return MediumBlock;} else{return SmallBlock;}};
private:
    string size;
    //pre-set block sizes
    double BigBlock = 1.0;
    double MediumBlock = .5;
    double SmallBlock = .1;
};

class Wheel {
public:
    //creates a wheel with a size parameter
    Wheel(string size){this->wheelSize = size;};
    //returns the wheel size
    string getWheelSize(){return wheelSize;};
private:
    string wheelSize;
};

class Chassis {
public:
    //creates a chassis with a type parameter
    Chassis(string type){this->type = type;};
    //returns the chassis type
    string getChassisType(){return type;};
private:
    string type; 
};

class Light {
public:
    //creates a light with a light parameter
    Light(string type){this->type = type;};
    //checks the type parameter to see if it matches any pre-set types then returns a value
    string getLightType(){if(type == "Head Light"){return headLightType;}
                   else if(type == "Brake Light"){return brakeLightType;}
                   else if(type == "Left Rear Turn"){return turningRearSignalType;}
                   else if(type == "Right Rear Turn"){return turningRearSignalType;}
                   else if(type == "Left Front Turn"){return turningFrontSignalType;}
                   else if(type == "Right Front Turn"){return turningFrontSignalType;}
                   else{return otherLightType;}};
private:
    string type;
    //pre-set types
    string headLightType = "Type 1";
    string brakeLightType = "Type 2";
    string turningRearSignalType = "Type 3";
    string turningFrontSignalType = "Type 4";
    string otherLightType = "Type 5";
};

class Body {
public:
    //creates a body with a color parameter
    Body(string color){this->color = color;};
    //returns the color
    string getBodyColor(){return color;};
private:
    string color;
};

class Car {
public:
    //constructor that requires every part of a car
    Car(Engine engine, Chassis chassis, Body body, Wheel wheels[], Light lights[]){
    
    //accepts all of the value returning methods for above car parts
    setPrintStrings(
            engine.getBlockSize(), chassis.getChassisType(), body.getBodyColor(),
            wheels[0].getWheelSize(), wheels[1].getWheelSize(), wheels[2].getWheelSize(), wheels[3].getWheelSize(),
            lights[0].getLightType(), lights[1].getLightType(), lights[2].getLightType(), lights[3].getLightType(),
            lights[4].getLightType(), lights[5].getLightType(), lights[6].getLightType(), lights[7].getLightType(),
            lights[8].getLightType(), lights[9].getLightType());};
    
    //prints all of the local strings
    void print(){       
        cout << "Engine: " << engineSize << endl;
        for(int  i= 0; i < 4; i++){cout << "Wheel: " << WheelSizes[i] << endl;}
        cout << "Chassis: " << chassisType << endl;
        for(int  i= 0; i < 10; i++){cout << "Light: " << LightTypes[i] << endl;} 
        cout << "Body: " << bodyColor << endl;};
     
    //gets the strings from th value returning methods and sets them to local strings
    void setPrintStrings(
        double engine, string chassis, string body, 
        
        string wheelOne, string wheelTwo, string wheelThree, string wheelFour, 
        
        string lightOne, string lightTwo, string lightThree, string lightFour, string lightFive, 
        string lightSix, string lightSeven, string lightEight, string lightNine, string lightTen){ 
        
        engineSize = engine; chassisType = chassis; bodyColor = body;
        
        //puts all the wheels back into an array
        WheelSizes[0] = wheelOne; WheelSizes[1] = wheelTwo; WheelSizes[2] = wheelThree; WheelSizes[3] = wheelFour;
        
        //puts all of the lights into a light array
        LightTypes[0] = lightOne; LightTypes[1] = lightTwo; LightTypes[2] = lightThree; LightTypes[3] = lightFour; LightTypes[4] = lightFive; 
        LightTypes[5] = lightSix; LightTypes[6] = lightSeven; LightTypes[7] = lightEight; LightTypes[8] = lightNine; LightTypes[9] = lightTen;};
        
private:    
    double engineSize;
    string chassisType;
    string bodyColor;
    string WheelSizes[4];
    string LightTypes[10];
};

int main(int argc, char** argv) {

    Engine engine("Big Block");

    Chassis chassis("Normal");

    Body body("Slate Mist Blue");

    Light lights[] ={
        Light("Head Light"), Light("Head Light"), Light("Brake Light"),
        Light("Brake Light"), Light("Left Rear Turn"), Light("Right Rear Turn"),
        Light("Left Front Turn"), Light("Right Front Turn"), Light("Reverse Light"),
        Light("License Plate Light")
    };

    Wheel wheels[] ={
        Wheel("16inches"), Wheel("16inches"),
        Wheel("16inches"), Wheel("16inches")
    };

    
    Car car(engine, chassis, body, wheels, lights);
    
    car.print();

    return 0;
}
