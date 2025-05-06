#include "gbbenchmarkpromisedland.h"
#include <godot_cpp/classes/mesh_instance3d.hpp>
#include <godot_cpp/classes/array_mesh.hpp>
#include <godot_cpp/classes/fast_noise_lite.hpp>
#include <godot_cpp/classes/standard_material3d.hpp>
#include <godot_cpp/classes/mesh.hpp>
#include <godot_cpp/templates/vector.hpp>
    
using namespace godot;

void GDBenchmarkPromisedLand::_bind_methods() {}
    
void GDBenchmarkPromisedLand::_benchmark()
{
    MeshInstance3D *mesh_instance = memnew(MeshInstance3D);
    ArrayMesh *array_mesh = memnew(ArrayMesh);
    FastNoiseLite *fast_noise = memnew(FastNoiseLite);

    Array surface_array;
    PackedVector3Array verts;
    PackedVector3Array normals;
    PackedInt32Array indices;

    int subdivisions = 500;
    int zoom = 150;
    float height_factor = 15.0f;

    StandardMaterial3D *material = memnew(StandardMaterial3D);
    material->set_albedo(Color("ORANGE_RED"));

    // Generazione arrays per ArrayMesh

    surface_array.resize(Mesh::ARRAY_MAX);
    verts.resize(subdivisions * subdivisions);
    normals.resize(subdivisions * subdivisions);
    indices.resize(6 * (subdivisions - 1) * (subdivisions - 1));

    // Creazione dei punti
    for(int y = 0; y < subdivisions; y++)
        for(int x = 0; x < subdivisions; x++) {
            int i = x + (y * subdivisions);
            Vector2 perc = Vector2(x, y) / (subdivisions -1);
            Vector3 point = zoom * (2.0f * Vector3(1.0f, 0.0f, 0.0f) * (perc.x - 0.5f) + 
                                    2.0f * Vector3(0.0f, 0.0f, 1.0f) * (perc.y - 0.5f));
            point.y += height_factor * fast_noise->get_noise_3d(point.x, point.y, point.z);
            verts[i] = point;
        }

    // Creazione indici
    int triangle_index = 0;    
    for(int y = 0; y < subdivisions; y++)
        for(int x = 0; x < subdivisions; x++) {
            int i = x + (y * subdivisions);
            if ((x != subdivisions -1) && (y != subdivisions -1)) {
                indices[triangle_index + 0] = i + subdivisions + 1;
                indices[triangle_index + 1] = i + subdivisions;
                indices[triangle_index + 2] = i;

                indices[triangle_index + 3] = i + 1;
                indices[triangle_index + 4] = i + subdivisions + 1;                
                indices[triangle_index + 5] = i;

                triangle_index += 6;
            }
        }

    // Creazione normali
    for(int a=0; a < indices.size(); a += 3 ) {
        Vector3 ab = verts[indices[a + 1]] - verts[indices[a]];
        Vector3 bc = verts[indices[a + 2]] - verts[indices[a + 1]];
        Vector3 ca = verts[indices[a]] - verts[indices[a + 2]];

        Vector3 x_ab_bc = -ab.cross(bc);
        Vector3 x_bc_ca = -bc.cross(ca);
        Vector3 x_ca_ab = -ca.cross(ab);

        Vector3 sum_normal = x_ab_bc + x_bc_ca + x_ca_ab;

        normals[indices[a]] = sum_normal;
        normals[indices[a + 1]] = sum_normal;
        normals[indices[a + 2]] = sum_normal;
    }

    for(int n=0; n<normals.size(); n++) {
        Vector3 this_normal = normals[n];        
        this_normal.normalize();
        normals[n] = this_normal;
    }


    // Passaggio dati alla mesh
    surface_array[Mesh::ARRAY_VERTEX] = verts;
    surface_array[Mesh::ARRAY_INDEX] = indices;
    surface_array[Mesh::ARRAY_NORMAL] = normals;

    array_mesh->add_surface_from_arrays(Mesh::PRIMITIVE_TRIANGLES, surface_array);
    mesh_instance->set_mesh(array_mesh);
    mesh_instance->set_surface_override_material(0, material);
    add_child(mesh_instance);

    
    UtilityFunctions::print(vformat("--- GDExtension ha generato un piano di %d punti", 
                                    subdivisions * subdivisions));   
                                    
    mesh_instance->queue_free();                                    
}

String GDBenchmarkPromisedLand::_log_message()
{
    return "Terra promessa in GDExtension --> %d usec.";
}
