#include "tutorial.h"
#include "key_macos.h"
#include <math.h>

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == KEY_ESCAPE)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	return (0);
}
int	render(t_data *data)
{
	if (data->win_ptr != NULL)
    {
        int x=310;
        int y=180;
        while(x<=330)
        {
            mlx_pixel_put(data->mlx_ptr,data->win_ptr,x,180,0xFFFFFF);
            x++;
        }
        while(y<=200)
        {
            mlx_pixel_put(data->mlx_ptr,data->win_ptr,320,y,0xFFFFFF);
            y++;
        }
    }
	return (0);
}

int main(void)
{
    t_data data;
    data.mlx_ptr = mlx_init();
    data.win_ptr = mlx_new_window(data.mlx_ptr, 640, 360, "Tutorial");
    mlx_loop_hook(data.mlx_ptr,&render,&data);
    mlx_hook(data.win_ptr,KEYPRESS,KEYPRESSMASK,&handle_keypress,&data);
    mlx_loop(data.mlx_ptr);
    free(data.mlx_ptr);
}
