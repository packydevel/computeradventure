//This global const can be used with external linkage.
//However this global const definition will generate linking
//error because exists the same const definition in another compiling
//unit (GlobalConstDefinition.cpp)
//See how this const is used in ExternConst.cpp
//extern const int CONSTANT1 = 10;
