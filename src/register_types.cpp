#include "register_types.h"
#include "gdbenchmarkwork.h"
#include "gdbenchmarklotofnothing.h"
#include "gdbenchmark1000cubes.h"
#include "gbbenchmarkpromisedland.h"
#include <gdextension_interface.h>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

using namespace godot;

void initialize_benchmark_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}

	GDREGISTER_RUNTIME_CLASS(GDBenchmarkWork);
	GDREGISTER_RUNTIME_CLASS(GDBenchmarkLotOfNothing);
	GDREGISTER_RUNTIME_CLASS(GDBenchmark1000Cubes);
	GDREGISTER_RUNTIME_CLASS(GDBenchmarkPromisedLand);
}

void uninitialize_benchmark_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
}

extern "C" {
// Initialization.
GDExtensionBool GDE_EXPORT benckmark_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, const GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization) {
	godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

	init_obj.register_initializer(initialize_benchmark_module);
	init_obj.register_terminator(uninitialize_benchmark_module);
	init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

	return init_obj.init();
}
}
