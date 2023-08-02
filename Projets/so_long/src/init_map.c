#include "../so_long.h"

void	put_images(t_game *game)
{
	int	len;

	len = 64;
	game->img.mountain = mlx_xpm_file_to_image(game->mlx, MOUNTAIN, &len, &len);
	game->img.goku = mlx_xpm_file_to_image(game->mlx, GOKU, &len, &len);
	game->img.sky = mlx_xpm_file_to_image(game->mlx, SKY, &len, &len);
	game->img.house = mlx_xpm_file_to_image(game->mlx, HOUSE, &len, &len);
	game->img.balls = mlx_xpm_file_to_image(game->mlx, BALLS, &len, &len);
	game->img.shenron = mlx_xpm_file_to_image(game->mlx, SHENRON, &len, &len);
}

void	put_map(int x, int y, char c, t_game *game)
{
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.mountain, x * 64, y * 64);
	if (c == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.sky, x * 64, y * 64);
	if (c == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.goku, x * 64, y * 64);
	if (c == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.house, x * 64, y * 64);
	if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.balls, x * 64, y * 64);
	if (c == 'B')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.shenron, x * 64, y * 64);
}

int	collectible_counter(t_game *game)
{
	int	x;
	int	y;
	int	c;

	x = 0;
	y = 0;
	c = 0;
	while (x < game->line)
	{
		while (y < game->col)
		{
			if (game->map[x][y] == 'C')
			{
				c++;
			}
			y++;
		}
		y = 0;
		x++;
	}
	return (c);
}

void	player_position(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < game->line)
	{
		while (y < game->col)
		{
			if (game->map[x][y] == 'P')
			{
				game->player_x = y;
				game->player_y = x;
			}
			y++;
		}
		y = 0;
		x++;
	}
}
