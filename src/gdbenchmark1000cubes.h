#ifndef GDBENCKMARK1000CUBES_H
#define GDBENCKMARK1000CUBES_H

#include "gdbenchmarkwork.h"
#include <godot_cpp/core/binder_common.hpp>
#include <godot_cpp/core/gdvirtual.gen.inc>

namespace godot
{

	class GDBenchmark1000Cubes : public GDBenchmarkWork
	{
		GDCLASS(GDBenchmark1000Cubes, GDBenchmarkWork)

    private:
        const int CUBES_PER_SIDE = 10;
        const float DISTANCE_FACTOR = 1.2f;

    protected:
		static void _bind_methods();        

	public:        		
		void _benchmark() override;	
		String _log_message() override;				
		
	};

}

#endif
