/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgacic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 09:05:29 by dgacic            #+#    #+#             */
/*   Updated: 2022/08/22 09:05:38 by dgacic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//shoutout to diego

#include <stdio.h>
#include <unistd.h>

static const char	g_min_int[] = {50, 49, 52, 55, 52, 56, 51, 54, 52, 56};

int		check_negative(int n);
int		int_digits(int n);
void	fill_arr_null(char n_char[]);
void	fill_array(char n_char[], int n, int size);

void	ft_putnbr(int nb)
{
	int		is_negative;
	int		nbr_of_digits;
	char	n_char[10];
	char	minus_sign;

	minus_sign = 45;
	fill_arr_null(n_char);
	is_negative = check_negative(nb);
	if (is_negative)
	{
		write(1, &minus_sign, 1);
		if (nb == -2147483648)
		{
			write(1, &g_min_int, 10);
			return ;
		}
		else
		{
			nb = nb * -1;
		}
	}
	nbr_of_digits = int_digits(nb);
	fill_array(n_char, nb, nbr_of_digits);
	write(1, n_char, nbr_of_digits);
}

int	check_negative(int n)
{
	if (n < 0)
	{
		return (1);
	}
	return (0);
}

int	int_digits(int n)
{
	int	nbr_of_digits;
	int	actual;

	nbr_of_digits = 1;
	actual = n;
	while (actual >= 10)
	{
		nbr_of_digits++;
		actual = actual / 10;
	}
	return (nbr_of_digits);
}

void	fill_arr_null(char n_char[])
{
	n_char[0] = 0;
	n_char[1] = 0;
	n_char[2] = 0;
	n_char[3] = 0;
	n_char[4] = 0;
	n_char[5] = 0;
	n_char[6] = 0;
	n_char[7] = 0;
	n_char[8] = 0;
	n_char[9] = 0;
}

void	fill_array(char n_char[], int n, int size)
{
	int	actual;
	int	counter;

	actual = n;
	counter = size;
	while (counter > 0)
	{
		counter--;
		n_char[counter] = (actual % 10) + 48;
		actual = actual / 10;
	}
}
