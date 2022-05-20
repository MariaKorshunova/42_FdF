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

## Step 1. Parsing maps and error management

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
- [X] Define value in color use BitShifting
- [X] Check maps colors in case where one value altitude for all maps points

## Step 3. Include MinilibX

- [X] Connection login to the graphical server
- [X] Create a pointer to the window 
- [X] Initialize the image
- [X] Calculate the memory offset using the line length set by mlx_get_data_addr
- [X] Put image to window
- [X] Memory leak protection for minilibx fubctions
- [X] Destroy image for protect memory leaks

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

## Step 4. Draw a line

- [X] Draw a line of a define colore
- [X] Draw a line with a gradient of colors

* Bresenham's line algorithm - https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
* Xiaolin Wu's line algorithm - https://en.wikipedia.org/wiki/Xiaolin_Wu%27s_line_algorithm


		void	ft_line(t_img *img, t_coord p0, t_coord p1, int color)
		{
			int		error;
			int		d_error;
			t_coord	step;
			t_coord	diff;

			ft_define_step_diff(&p0, &p1, &step, &diff);
			error = diff.x + diff.y;
			while ((p0.x != p1.x) || (p0.y != p1.y))
			{
				ft_mlx_pixel_put_img(img, p0.x, p0.y, color);
				d_error = 2 * error;
				if (d_error >= diff.y && p0.x != p1.x)
				{
					error += diff.y;
					p0.x += step.x;
				}
				if (d_error <= diff.x && p0.y != p1.y)
				{
					error += diff.x;
					p0.y += step.y;
				}
			}
			ft_mlx_pixel_put_img(img, p1.x, p1.y, color);
		}


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

## Step 5. Draw map in 2d-representation

- [X] Define zoom depending on map size
- [X] Fixed segmentation fault in case out-of-bounds image
- [X] Align map to the center of image
- [X] Connect map points (x, y) with lines

The loop algorithm for connectiom points:

	0 -> 0 -> 0 -> 0 -> 0
	|    |    |    |    |
	0 -> 0 -> 0 -> 0 -> 0
	|    |    |    |    |
	0 -> 0 -> 0 -> 0 -> 0
	|    |    |    |    |
	0 -> 0 -> 0 -> 0 -> 0
	|    |    |    |    |
	0 -> 0 -> 0 -> 0 -> 0

## Step 6. Isometric transformatiom
	
- [X] Function multiply 2 matriсes 3 * 3
- [X] Define matrix rotate x
- [X] Define matrix rotate y
- [X] Define matrix rotate z
- [X] Rotate map in isometric proection: 1) rotate; 2) scale; 3) translation.
- [X] Zoom in case large altitude changes

Useful source:
* https://habr.com/ru/post/497808/
* https://ru.wikipedia.org/wiki/Матрица_перехода
* https://ru.wikipedia.org/wiki/Матрица_поворота


## Step 7. Graphic management

- [X] Your program has to display the image in a window
- [X] Pressing ESC must close the window and quit the program in a clean way
- [X] Clicking on the cross on the window’s frame must close the window and quit the program in a clean way

	void mlx_hook(mlx_win_list_t *win_ptr, int x_event, int x_mask, int (*f)(), void *param)

## Step 8. Bonus part
- [ ] Include one extra projection (such as parallel or conic)!
- [ ] Zoom in and out.
- [ ] Translate your model.
- [ ] Rotate your model.
- [ ] Text tips