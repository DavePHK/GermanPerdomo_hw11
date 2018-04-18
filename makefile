pos.png: GP_graph.py tray.txt
	python GP_graph.py

tray.txt: GP_gravity_out
	./GP_gravity_out > tray.txt

GP_gravity_out: GP_gravity.cpp
	c++ GP_gravity.cpp -o GP_gravity_out
