#include "gdbenchmarkwork.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/time.hpp>
#include <godot_cpp/classes/os.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/variant/variant.hpp>

using namespace godot;

// Protected
void GDBenchmarkWork::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("run"), &GDBenchmarkWork::run);             
    
    GDVIRTUAL_BIND(_benchmark);
    GDVIRTUAL_BIND(_log_message);
        
    ADD_SIGNAL(MethodInfo("job_ended", PropertyInfo(Variant::STRING, "message")));
}

uint64_t GDBenchmarkWork::_benchmark_execute()
{
    uint64_t elapsed_time = Time::get_singleton()->get_ticks_usec();
        _benchmark();
    elapsed_time = Time::get_singleton()->get_ticks_usec() - elapsed_time;    
    return elapsed_time;
}

// Public
GDBenchmarkWork::GDBenchmarkWork() {}
GDBenchmarkWork::~GDBenchmarkWork() {}

void GDBenchmarkWork::run()
{    
    uint64_t elapsed_time = _benchmark_execute();            
    String message = vformat(_log_message(), elapsed_time);        
    emit_signal("job_ended", message);    
}

void GDBenchmarkWork::_benchmark()
{
    if (!GDVIRTUAL_IS_OVERRIDDEN(_benchmark)) {
        print_line("Perde 250 msec. di tempo");
        OS::get_singleton()->delay_msec(250);
    } else {    
        GDVIRTUAL_CALL(_benchmark);    
    }
}

String GDBenchmarkWork::_log_message()
{
	if (!GDVIRTUAL_IS_OVERRIDDEN(_log_message)) {		
		return "Processo di default. %d usec.";
	} else {
        String message;
        GDVIRTUAL_CALL(_log_message, message);
        return message;
	}
}
