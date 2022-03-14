# Fdf
**Status:** in progress
**Grade:** not evaluated

FdF school42

Wireframe model. This project is about representing a landscape as a 3D object
in which all surfaces are outlined in lines.

## Useful souces

https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html

## MinilibX

man /usr/share/man/man3/mlx.1

Introduction to Minilibx:

	//cc -I /usr/local/include main.c  -L /usr/local/lib/ -lmlx -framework OpenGL -framework APPKit

	void	ft_putchar(char c)
	{
		write(1, &c, 1);
	}	

	int	deal_key(void)
	{
		ft_putchar('X');
		return (0);
	}

	int	main(void)
	{
		void	*mlx_ptr;
		void	*win_ptr;

		// connection login to the graphical server
		mlx_ptr = mlx_init();
		//man /usr/share/man/man3/mlx_new_window.1
		win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx-42");
		// write 'X' in terminal when press a key in window
		mlx_key_hook(win_ptr, deal_key, (void *)0);
		mlx_loop(mlx_ptr);
	}