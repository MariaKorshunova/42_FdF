# Fdf
**Status:** in progress

**Grade:** not evaluated

FdF school42

Wireframe model. This project is about representing a landscape as a 3D object in which all surfaces are outlined in lines.

## MinilibX

Useful sources: https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html

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

## Parsing maps

## Colors

TRGB: 0xTTRRGGBB
* T - transparency
* R - red component
* G - green component
* B - blue component

RGB:
* Red - 0x00FF0000
* Green - 0x0000FF00
* Blue - 0x000000FF

## Draw a line

* Bresenham's line algorithm - https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
* Xiaolin Wu's line algorithm - https://en.wikipedia.org/wiki/Xiaolin_Wu%27s_line_algorithm


Checking draw line function with ft_asterisk:

	void	ft_asterisk(t_img *img, t_coord center, int r, int color)
	{
		t_coord	p;
		double	alpha;
		int		i;

		alpha = 0;
		i = 0;
		while (i < 12)
		{
			p.x = (int)(center.x + r * cos(alpha));
			p.y = (int)(center.y + r * sin(alpha));
			ft_line(img, center, p, color);
			alpha += M_PI / 6;
			i++;
		}
	}

## Isometric projection
	
	x = (x - y) * cos(a)

	y = (x + y) / 2 * sin(b)




## function for print two-dimensional  int array(base = dec(10) or hec(16))
	void	ft_print_int_array(int **arr, int row, int column, int base)
	{
		int	i;
		int	j;

		i = 0;
		while (i < row)
		{
			j = 0;
			while (j < column)
			{
				if (base == 10)
					printf("%2d ", arr[i][j]);
				if (base == 16)
					printf("%6x ", arr[i][j]);
				j++;
			}
			printf("\n");
			i++;
		}
	}