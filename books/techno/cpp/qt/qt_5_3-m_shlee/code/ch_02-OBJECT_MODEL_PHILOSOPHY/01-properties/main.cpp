#include "MyClass.h"

int main(int argc, char** argv) {
    MyClass* pobj = new MyClass();

    pobj->setProperty("readOnly", true);
    bool bReadOnly = pobj->property("readOnly").toBool();

    return 0;
}
