//This global const can be used with external linkage.
//See how this const is used in ExternConst.cpp
extern const int CONSTANT1 = 10;

//This global const can not be used with external linkage.
//In fact by default using global const has internal linkage.
//See the compile-time error using this const in ExternConst.cpp
const int CONSTANT2 = 20;

//This static global const  has the same effect of the previous CONSTANT2.
//This const can not be used for external linkage.
//See the compile-time error using this const in ExternConst.cpp
static const int CONSTANT3 = 30;
