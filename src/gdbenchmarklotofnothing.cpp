    #include "gdbenchmarklotofnothing.h"
    
    using namespace godot;

    void GDBenchmarkLotOfNothing::_bind_methods() {}
        
    void GDBenchmarkLotOfNothing::_benchmark()
    {
        int i = 0;
        for (int x=0; x < this->CICLES; x++) { i += 1; }
        UtilityFunctions::print(vformat("--- GDExtension ha fatto niente per %d volte", i));        
    }
    
    String GDBenchmarkLotOfNothing::_log_message()
    {
        return "Molto di niente in GDExtension --> %d usec";
    }
    