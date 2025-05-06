extends GDBenchmarkWork
class_name Benchmark1000Cubes

const CUBES_PER_SIDE = 10
const DISTANCE_FACTOR = 1.2

func _benchmark() -> void:
	var cubes: Array = []
	
	for x in range(CUBES_PER_SIDE):
		for y in range(CUBES_PER_SIDE):
			for z in range(CUBES_PER_SIDE):
				var mesh_instance = MeshInstance3D.new()
				var mesh: Mesh = BoxMesh.new()
				mesh.size = Vector3.ONE				
				add_child(mesh_instance)
				cubes.append(mesh_instance)				
				mesh_instance.position = Vector3 (x, y, z) * DISTANCE_FACTOR;
				mesh_instance.mesh = mesh

	print("--- GDScript ha generato " + str(cubes.size()) + " cubi")	

	for cube in cubes:
		cube.queue_free()						
	
func _log_message() -> String:
	return "1000 Cubi su GDScript --> %d usec."
