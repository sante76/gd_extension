#ifndef GDFAKECLASS_H
#define GDFAKECLASS_H

#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/core/binder_common.hpp>
#include <godot_cpp/core/gdvirtual.gen.inc>

namespace godot
{

    class GDFakeClass : public Node3D
    {
        GDCLASS(GDFakeClass, Node3D)

	private:
		float setter_getter_param = 0.0f;

    protected:
        static void _bind_methods();

    public:
        GDFakeClass();
        ~GDFakeClass();

        
        void setter_method(float value);
        float getter_method() const;

		virtual float _vattelappesca(int numero, int altro);

        GDVIRTUAL2R(float, _vattelappesca, int, int);	
    };

}

#endif