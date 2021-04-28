#include "SDL.h"
#include "window.h"
#include "utils.h"
#include <iostream>
#include <Windows.h>
#include <chrono>
#include "3ddef.h"
#include "shape.h"
#include "ray.h"

using namespace std::chrono;



int main(int argc, char* argv[]) 
{
	Window window("george", 100, 100, 500, 500, NULL);
	window.ClearTexture();
	window.LockTexture();

	camera cam{ 110.0, window.texture, window.Width(), window.Height(), vec3{}, dir3{} };
	int width = window.Width();
	int height = window.Height();


	auto start = high_resolution_clock::now();
	for (int x = 0; x < width -1; x++) {
		for (int y = 0; y < height -1; y++) {
			window.texture[height * y + x] = castray(cam.camerarays[x][y], cam);
		}
	}

	auto end = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(end - start);

	std::cout << duration.count() << " done";



	window.UnlockTexture();
	window.DrawTexture();

	Sleep(10000);
	return 0;
}