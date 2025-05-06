#ifndef GDBENCKMARKPROMISEDLAND_H
#define GDBENCKMARKPROMISEDLAND_H

#include "gdbenchmarkwork.h"
#include <godot_cpp/core/binder_common.hpp>
#include <godot_cpp/core/gdvirtual.gen.inc>

namespace godot
{

	class GDBenchmarkPromisedLand : public GDBenchmarkWork
	{
		GDCLASS(GDBenchmarkPromisedLand, GDBenchmarkWork)

    private:

    protected:
		static void _bind_methods();        

	public:        		
		void _benchmark() override;	
		String _log_message() override;				
		
	};

}

#endif
