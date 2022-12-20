/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:27:00 by lnaidu            #+#    #+#             */
/*   Updated: 2022/12/20 18:14:51 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	A[7][7] = {
	0,0,0,0,0,0,0,
	0,1,0,0,0,0,0,
	0,1,0,0,0,0,0,
	0,1,0,1,1,1,0,
	0,1,0,1,0,1,0,
	0,1,1,1,0,1,0,
	0,0,0,0,0,0,0
};

int	path[7][7] = {
	0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,
	0,0,0,0,0,0,0
};

int	findPath(int i, int j, int n)
{
	if (i == n - 1 && j == n - 1)
	{
		path[i][j] = 1;
		return (1);
	}
	if (A[i][j] == 1)
	{
		path[i][j] = 1;
		printf("(%d;%d)\n",i, j);
		if (findPath(i, j + 1, n) == 1)
			return(1);
		if (findPath(i + 1, j, n) == 1) 
			return(1);
		path[i][j] = 0;
	}
	if (A[i][j] == 0)
	{
		path[i][j] = 1;
		printf("(%d;%d)\n",i, j);
		if (findPath(i - 1, j, n) == 1)
			return(1);
		path[i][j] = 0;
	}
	/*if (A[i][j] == 1)
	{
		path[i][j] = 1;
		printf("(%d;%d)\n",i, j);
		if (findPath(i, j - 1, n) == 1)
			return(1);
		path[i][j] = 0;
	}*/
	return (0);
}

int main()
{
	int	i;
	int	j;
	int	n;

	i = 0;
	j = 0;
	n = 6;
	findPath(1,1,n);

	/*for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if(path[i][j])
				printf("(%d, %d) --> \n", i, j);
			printf("\n");*/
	while (i < n)
	{
		while (j < n)
		{
			if(path[i][j] == 1)
				printf("(%d, %d) --> \n", i, j);
			j++;
		}
		j = 0;
		i++;
	}
	printf("***\n");

}