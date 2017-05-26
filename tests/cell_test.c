#include <cell.h>
#include <ctest.h>

CTEST(cell, init_cell_1)
{
	Cell cell;
	char life_char = '0';
	char empty_char = '.';

	cell = init_cell(0, life_char, empty_char);

	ASSERT_EQUAL(cell.state, 0);
}

CTEST(cell, init_cell_2)
{
	Cell cell;

	char life_char = '0';
	char empty_char = '.';

	cell = init_cell(0, life_char, empty_char);

	ASSERT_EQUAL(cell.life_char_cell, life_char);
}

CTEST(cell, init_cell_3)
{
	Cell cell;
	char life_char = '0';
	char empty_char = '.';

	cell = init_cell(0, life_char, empty_char);

	ASSERT_EQUAL(cell.empty_char_cell, empty_char);
}

CTEST(cell, mode_cell_1)
{
	Cell cell;
	char life_char = '0';
	char empty_char = '.';

	cell = init_cell(0, life_char, empty_char);
	
	mode_cell(&cell, 1);

	ASSERT_EQUAL(cell.state, 1);
}

CTEST(cell, mode_cell_2)
{
	Cell cell;
	char life_char = '0';
	char empty_char = '.';

	cell = init_cell(0, life_char, empty_char);
	
	mode_cell(&cell, 0);

	ASSERT_EQUAL(cell.state, 0);
}