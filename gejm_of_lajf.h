#pragma once

class gejm_of_lajf
{
public:
	gejm_of_lajf();
	void next_generation();
	void draw();
private:
	static const unsigned int ROWS{ 20U };
	static const unsigned int COLUMNS{ 40U };
	bool my_generation[ROWS][COLUMNS];
	bool my_next_generation[ROWS][COLUMNS];
	bool random();
	bool cell_occupied(int i, int j);
	int neighbours_number(int i, int j);
};

