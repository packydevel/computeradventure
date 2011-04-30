//A namespace can containt whatever object.
//A namespace definition can continue on multiple Header File.
//A namespace can be nested in another namespace
namespace SimpleNamespace {
int i;

class SimpleClass {
};

//Nested namespace
namespace NestedNamespace {
int i;
}
}

//Alias for External namespace
namespace sn = SimpleNamespace;

//Alias for Nested namespace
namespace nn = SimpleNamespace::NestedNamespace;
