extends Node3D
class_name Benckmark

const CAMERA_POSITION = Vector3(15,15,15)

@onready var camera: Camera3D = $Camera3D

var works = []



func _ready() -> void:
	_set_camera()
	_prepare_works_array()
	_start_next_work()
	
	
func _prepare_works_array() -> void:	
	# Aggiungeremo le varie classi per il benchmark qui
	works.append(BenchmarkLotOfNothing.new())
	works.append(GDBenchmarkLotOfNothing.new())
	works.append(Benchmark1000Cubes.new())
	works.append(GDBenchmark1000Cubes.new())
	works.append(BenchmarkPromisedLand.new())
	works.append(GDBenchmarkPromisedLand.new())
			
	for work in works:		
		add_child(work)
		work.job_ended.connect(_work_ended)
	
	
func _start_next_work() -> void:
	if works.size() > 0:		
		var work = works.pop_front() as GDBenchmarkWork
		work.run()				
	else:
		print("Benchmark finito!")
		

func _work_ended(message: String) -> void:
	print(message)
	_start_next_work();
	
	
func _set_camera() -> void:
	camera.position = CAMERA_POSITION
	camera.look_at(Vector3.ZERO)
	
