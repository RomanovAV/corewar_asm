#include "asm.h"

int g_cur_col;

static t_opcode_type	get_opcode_type(char **line)
{
	static const char	*types[17] = {NULL, "live", "ld", "st", "add", "sub",
									"and", "or", "xor", "zjmp", "ldi", "sti",
									"fork", "lld", "lldi", "lfork", "aff"};
	size_t				size;
	int					i;

	i = 17;
	while (--i)
	{
		size = ft_strlen(types[i]);
		if (ft_strnequ(*line, types[i], size))
			break ;
	}
	if (i == crw_undef_code)
		error("Lexical error: invalid instruction", 1);
	*line += size;
	g_cur_col += size;
	return (i);
}

void					parse_opcode(t_opcode *opcode, char *line)
{
	int i;

	skip_whitespaces(&line);
	if (!*line)
		return ;
	opcode->type = get_opcode_type(&line);
	i = 0;
	while (i < 3)
	{
		skip_whitespaces(&line);
		if ((opcode->param[i] = parse_parameter(line)))
		{
			opcode->param_code |= opcode->param[i]->type << ((3 - i) * 2);
			skip_to_separator(&line);
			skip_whitespaces(&line);
			if (*line && (*line++ != SEPARATOR_CHAR || i == 2))
				error("Syntax error: wrong parameters", 1);
		}
		++i;
	}
	if (!validate_parameters(opcode->type, opcode->param_code))
		error("Syntax error: wrong parameters types", 1);
}