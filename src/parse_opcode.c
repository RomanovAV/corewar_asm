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

void	parse_opcode(t_opcode *opcode, char *line)
{
	int i;

	skip_whitespaces(&line);
	if (!*line)
		return ;
	opcode->type = get_opcode_type(&line);
	while (i < 3)
	{
		skip_whitespaces(&line);
		//iopcode->param[i] = parse_parameter(line);
	}
}