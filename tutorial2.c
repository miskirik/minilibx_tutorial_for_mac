#include "tutorial.h"
#include "key_macos.h"
#include <math.h>

typedef struct s_data{
	void	*mlx_ptr;
	void	*win_ptr;
}				m_data;


int main(void)
{
	m_data mdata;
	char a[]="muhamemt";
	char *p=a;
	mdata.mlx_ptr=mlx_init();
	mdata.win_ptr=mlx_new_window(mdata.mlx_ptr,1920,1080,"Hello World");
	mlx_string_put(mdata.mlx_ptr,mdata.win_ptr,5,5,0x00FF0000,p);
	mlx_pixel_put(mdata.mlx_ptr,mdata.win_ptr,5,5,0x00FF0000);
	mlx_loop(mdata.mlx_ptr);
}
