#include "asm.h"

int g_cur_line;
int g_cur_col;

int main(int ac, char **av)
{
	int	flag;
	int	index;

	if (ac == 1)
		faq();
	index = 1;
	while (index < ac)
	{
		flag = av[1][0] == "-" ? get_flag(av[index++]) : 0;
		if (index == ac)
			error("file not specified", 0);
		pricess(av[index], flag);
		++index;
	}
	return (0);
}