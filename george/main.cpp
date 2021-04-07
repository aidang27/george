#include "SDL.h"
#include "window.h"
#include "utils.h"
#include <iostream>
#include <Windows.h>
#include <chrono>
#include "3ddef.h"
#include "shape.h"

using namespace std::chrono;



int main(int argc, char* argv[]) 
{
	Window window("george", 100, 100, 500, 500, NULL);
	
	window.LockTexture();

	camera cam{ 90.0, pos{}, ang{}};
	sphere sph{ 20, pos{0, 50, 0}, ang{} };

	int height = window.Height();
	for (int w = 0; w < window.Width(); w++) {
		for (int h = 0; h < window.Height(); h++) {
			//window.texture[h * height + w] = Colour{ 0,0,0,0 };

		}
	}


	window.UnlockTexture();
	window.DrawTexture();

	Sleep(10000);
	return 0;
}