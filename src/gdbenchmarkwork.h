#ifndef GDBENCKMARKWORK_H
#define GDBENCKMARKWORK_H

#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/core/binder_common.hpp>
#include <godot_cpp/core/gdvirtual.gen.inc>

namespace godot
{

	class GDBenchmarkWork : public Node3D
	{
		GDCLASS(GDBenchmarkWork, Node3D)

	protected:
		static void _bind_methods();
		uint64_t _benchmark_execute();		

	public:
		GDBenchmarkWork();
		~GDBenchmarkWork();
		
		void run();		
		
		virtual void _benchmark();		
		virtual String _log_message();					

		GDVIRTUAL0(_benchmark);		
		GDVIRTUAL0R(String, _log_message);
		
	};

}

#endif
