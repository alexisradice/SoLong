#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"

# include <stdlib.h>

typedef struct s_map
{
	char		**map;
	int			size_line;
	int			count_line;
}	t_map;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*window_ptr;
	t_map	*map;
}	t_mlx;

#endif
