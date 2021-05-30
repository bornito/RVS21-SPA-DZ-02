#include<iostream>
#include"gejm_of_lajf.h"

using namespace std;

int main()
{
	gejm_of_lajf d_gejm{};

	bool cnt{ true };

	do // ENDLESS LOOP
	{
		d_gejm.draw();
		d_gejm.next_generation();

	} while (cnt);

	return 0;
}