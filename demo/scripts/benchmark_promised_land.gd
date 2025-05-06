extends GDBenchmarkWork
class_name  BenchmarkPromisedLand

func _benchmark() -> void:
	var mesh_instance: MeshInstance3D = MeshInstance3D.new()
	var array_mesh: ArrayMesh = ArrayMesh.new()
	var fast_noise: FastNoiseLite = FastNoiseLite.new()
	
	var surface_array = []
	var verts = PackedVector3Array()	
	var normals = PackedVector3Array()
	var indices = PackedInt32Array()
	
	var subdivision: int = 500	
	var zoom: int = 150
	var height_factor: float = 15.0
	
	var material: StandardMaterial3D = StandardMaterial3D.new()
	material.albedo_color = Color.ORANGE_RED	
	
	surface_array.resize(Mesh.ARRAY_MAX)
	verts.resize(subdivision * subdivision)
	normals.resize(subdivision * subdivision)
	indices.resize(6 * (subdivision -1 ) * (subdivision -1))


	
	# Creazione dei punti
	for y in subdivision:
		for x in subdivision:
			var i:int = x + (y * subdivision)
			var perc: Vector2 = Vector2(x,y) / (subdivision -1)
			var point: Vector3 = zoom * (2.0 * Vector3.RIGHT * (perc.x -0.5) \
									  + 2.0 * Vector3.BACK * (perc.y - 0.5))
			point.y += height_factor * fast_noise.get_noise_3d(point.x, point.y, point.z)
			verts[i] = point	
	
	# Creazione indici
	var triangle_index : int = 0	
	for y in subdivision:
		for x in subdivision:
			var i:int = x + (y * subdivision)
			if (x != subdivision -1 ) and (y != subdivision -1 ):
				indices[triangle_index + 0] = i + subdivision + 1
				indices[triangle_index + 1] = i + subdivision 
				indices[triangle_index + 2] = i 
				
				indices[triangle_index + 3] = i + 1
				indices[triangle_index + 4] = i + subdivision + 1
				indices[triangle_index + 5] = i 
				
				triangle_index += 6
	
	# Creazione normali
	for a in range(0, indices.size(),3):
		var ab: Vector3 = verts[indices[a + 1]] - verts[indices[a]]
		var bc: Vector3 = verts[indices[a + 2]] - verts[indices[a + 1]]
		var ca: Vector3 = verts[indices[a]] - verts[indices[a + 2]]
		
		var x_ab_bc :Vector3 = -ab.cross(bc)
		var x_bc_ca :Vector3 = -bc.cross(ca)
		var x_ca_ab: Vector3 = -ca.cross(ab)
		
		var sum_normal: Vector3 = x_ab_bc + x_bc_ca + x_ca_ab
		
		normals[indices[a]] += sum_normal
		normals[indices[a + 1]] += sum_normal
		normals[indices[a + 2]] += sum_normal
		
	for n in normals.size():
		normals[n] = normals[n].normalized()
	
	
	surface_array[Mesh.ARRAY_VERTEX] = verts
	surface_array[Mesh.ARRAY_INDEX] = indices
	surface_array[Mesh.ARRAY_NORMAL] = normals	
	
	array_mesh.add_surface_from_arrays(Mesh.PRIMITIVE_TRIANGLES, surface_array)
	mesh_instance.mesh = array_mesh		
	mesh_instance.set_surface_override_material(0, material)		
	add_child(mesh_instance)
	
	print("--- GDScript ha generato un piano di " + str(subdivision * subdivision) + " punti")		
	# mesh_instance.queue_free()
	
	
func _log_message() -> String:
	return "Terra promessa in GDScript --> %d usec."
