#include "../so_long.h"

void	free_img(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img.karin_tour);
	if (game->img.balls)
		mlx_destroy_image(game->mlx, game->img.balls);
	if (game->img.goku)
		mlx_destroy_image(game->mlx, game->img.goku);
	if (game->img.sky)
		mlx_destroy_image(game->mlx, game->img.sky);
	if (game->img.mountain)
		mlx_destroy_image(game->mlx, game->img.mountain);
	if (game->img.on_tour)
		mlx_destroy_image(game->mlx, game->img.on_tour);
	mlx_destroy_display(game->mlx);
	free_map(game);
	free(game->mlx);
	exit(0);
}

void	ft_exit(char *s, t_game *game)
{
	ft_printf("Error\nSomething is wrong!\n%s\n", s);
	if (game->map[0])
		free_map(game);
	exit(0);
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

void	free_map_floodfill(t_game *game)
{
	int	i;

	i = 0;
	while (game->map_floodfill[i])
	{
		free(game->map_floodfill[i]);
		i++;
	}
	free(game->map_floodfill);
}

int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free_img(game);
	free_map(game);
	exit (0);
}
