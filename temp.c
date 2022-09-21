void	init_mlx(t_game *game)
{
	int wid;
	int hei;
	int	x;

	x = -1;
	while (game->map[++x])
		;
	wid = ft_strlen(game->map[0]) * 30;
	hei = x * 30;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, wid, hei, "so_lunga");
	create_map(game);
	mlx_key_hook(game->win, keycode, game);
	mlx_hook(game->win, 17, 0, exit_game, game);
	mlx_loop(game->mlx);
}