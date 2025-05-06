extends GDBenchmarkWork
class_name BenchmarkLotOfNothing

const CICLES = 5000000

func _benchmark() -> void:
	var i: int = 0;
	for x in range(CICLES):
		i += 1
	print("--- GDScript ha fatto niente per " + str(i) + " volte")	
	
func _log_message() -> String:
	return "Molto di niente in GDScript --> %d usec"
