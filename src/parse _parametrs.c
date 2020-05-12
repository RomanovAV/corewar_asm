#include "asm.h"

// static void		get_parameter(t_opcode_param *param, char *line)
// {

// }

t_opcode_param	*parse_parameter(char *line)
{
	t_opcode_param *param;

	param = NULL;
	if (*line)
	{
		if (!(param = (t_opcode_param *)malloc(sizeof(t_opcode_param))))
			error(strerror(errno), 0);
		param->value = 0;
		param->link = NULL;
		get_parameter(param, line);
	}
	return (param);
}