#include "gdbenchmark1000cubes.h"
#include <godot_cpp/classes/mesh_instance3d.hpp>
#include <godot_cpp/classes/mesh.hpp>
#include <godot_cpp/classes/box_mesh.hpp>

    
using namespace godot;

void GDBenchmark1000Cubes::_bind_methods() {}
    
void GDBenchmark1000Cubes::_benchmark()
{
   Array *cubes = memnew(Array);
   for(int x=0; x < CUBES_PER_SIDE; x++)
        for(int y=0; y < CUBES_PER_SIDE; y++)
            for(int z=0; z < CUBES_PER_SIDE; z++) {
                MeshInstance3D *mesh_instance = memnew(MeshInstance3D);
                Mesh *mesh = memnew(BoxMesh);
                BoxMesh *box = Object::cast_to<BoxMesh>(mesh);                
                box->set_size(Vector3(1.0f, 1.0f, 1.0f));
                add_child(mesh_instance);
                cubes->append(mesh_instance);
                mesh_instance->set_position(Vector3(x, y, z) * DISTANCE_FACTOR);
                mesh_instance->set_mesh(mesh);
            }

    UtilityFunctions::print(vformat("--- GDExtension ha generato %d cubi", cubes->size()));            

    for(int i=0; i<cubes->size(); i++) {
        MeshInstance3D *cube = Object::cast_to<MeshInstance3D>(cubes->get(i));
        cube->queue_free();
    }        
    memdelete(cubes);
}

String GDBenchmark1000Cubes::_log_message()
{
    return "1000 Cubi su GDExtension --> %d usec.";
}
