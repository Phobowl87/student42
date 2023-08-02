#include "../so_long.h"

void	start_validations(t_game *game, int fd)
{
	ft_printf("Init validations...\n");
	check_map(game);
	valid_map(game);
	valid_path(game, fd);
}
