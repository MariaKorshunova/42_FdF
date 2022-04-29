# Fdf
**Status:** in progress :-)

**Grade:** not evaluated

FdF school42

Wireframe model. This project is about representing a landscape as a 3D object in which all surfaces are outlined in lines.

##	launch MacOS

	git clone https://github.com/MariaKorshunova/FdF.git
	cd FdF
	git clone https://github.com/MariaKorshunova/libft.git
	git clone https://github.com/MariaKorshunova/get_next_line.git
	make
	./fdf you_map.fdf

## Project execution steps

### Step 1. Parsing maps and error management

- [X] Invalid number of arguments: only one argument with the name of file with map.
- [X] Invalid file extension: extension of file has to ne .fdf .
- [X] Define the number of rows and columns of a map. 
- [X] Invalid map in case of the numbers of columns it the rows don't match.
- [X] Invalid map in case of empty file
- [X] Allocate memory for two-dimensional arrays for altitudes and colors.
- [X] Fill this arrays. If there isn't value for color, cell is filled by defoult.
- [X] Invalid map in case of altitude: empty string, not integer
- [X] Invalid map in case of colors: not hex RGB if not empty.

It is two ways for reading map:
- [X] Open map file at first time and define number of rows anf columns. And then open file one more time for filling arrays .
- [ ] Use lists for define columns with opening map file only once.

At this step don't forget about **leaks management**, including protection of the malloc function.

	leaks --atExit -- filename.fdf

You can check yourself at the end of this step with the **function whis prints two-dimensional arrays for altitudes and colors**:

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

## Step 2. Color definition based on altitude

- [X] Define max and min altitude value
- [X] Define value of [R, G, B] in RGB: r =  LOW_R + coeff_minimax_normalization_altitude * (HIGH_R - LOW_R)
- [ ] Define value in color use BitShifting

## Step 3. Include MinilibX

Useful source: https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html

	man /usr/share/man/man3/mlx.1

A simple example use Minilibx:

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

* 

## Step 3. Draw map in 2d-representation


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
