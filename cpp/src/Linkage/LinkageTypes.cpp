int globalVariable; // extern by default (external linkage)

const int FILE_SCOPE_CONSTANT = 0; // static by default (internal linkage, file scope)

extern const int GLOBAL_CONSTANT;
; // explicitly extern (external linkage)

static int fileScopeVariable; // explicitly static (internal linkage, file scope)

// the same goes for functions (but there are no const functions)
int foo(); // extern by default (external linkage)

static int bar(); // explicitly static (internal linkage, file scope)

//Anonymous namespace hides for external linkage
namespace {
int notVisibleVariable; // external linkage but becomes internal linkage
class NotVisibleClass {
}; // external linkage but become internal linkage
}

namespace QualifiedNamespace {
class VisibleClass {
}; // qualified name QualifiedNamespace::VisibleClass has external linkage
}

enum SimpleEnum {
	Up, Down
}; // extern by default (external linkage)

//Anonynous union most be static (internal linkage, file scope)
static union {
	int x;
	float y;
}; //all of the members of anonymous union become static (internal linkage, file scope)

union SimpleUnion {
	int x;
	float y;
}; // extern by default (external linkage)

typedef int Integer; // static by default (internal linkage, file scope)
