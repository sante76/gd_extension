#ifndef GDBENCKMARKLOTOFNOTHING_H
#define GDBENCKMARKLOTOFNOTHING_H

#include "gdbenchmarkwork.h"
#include <godot_cpp/core/binder_common.hpp>
#include <godot_cpp/core/gdvirtual.gen.inc>

namespace godot
{

	class GDBenchmarkLotOfNothing : public GDBenchmarkWork
	{
		GDCLASS(GDBenchmarkLotOfNothing, GDBenchmarkWork)

    private:
        const int CICLES = 5000000;

    protected:
		static void _bind_methods();        

	public:        		
		void _benchmark() override;	
		String _log_message() override;				
		
	};

}

#endif
