#include "gdfakeclass.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/time.hpp>
#include <godot_cpp/classes/os.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/variant/variant.hpp>

using namespace godot;

// Protected
void GDFakeClass::_bind_methods()
{
    GDVIRTUAL_BIND(_vattelappesca, "numero", "altronumero");

    // Property with Setter and Getter
    ClassDB::bind_method(D_METHOD("setter_method", "value"), &GDFakeClass::setter_method);
    ClassDB::bind_method(D_METHOD("getter_method"), &GDFakeClass::getter_method);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "set_get_param"), "setter_method", "getter_method");
   
}

// Public
GDFakeClass::GDFakeClass() {}
GDFakeClass::~GDFakeClass() {}


void GDFakeClass::setter_method(float value)
{
    setter_getter_param = value;
}


float GDFakeClass::getter_method() const
{
    return setter_getter_param;
}

float GDFakeClass::_vattelappesca(int numero, int altro)
{
    if (!GDVIRTUAL_IS_OVERRIDDEN(_vattelappesca))
    {
        return 1.0f;
    }
    else
    {
        float ritorno;
        GDVIRTUAL_CALL(_vattelappesca, numero, altro, ritorno);
        return ritorno;
    }
}