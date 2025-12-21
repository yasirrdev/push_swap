/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-maa <ybel-maa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:55:13 by ybel-maa          #+#    #+#             */
/*   Updated: 2025/12/19 15:06:14 by ybel-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(char *s)
{
	int	i;

	i = 0;
	if (!s[i])
		return (0);
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	is_overflow(char *s)
{
	long	num;
	int		sign;
	int		i;

	num = 0;
	sign = 1;
	i = 0;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i])
	{
		num = num * 10 + (s[i] - '0');
		if ((sign == 1 && num > 2147483647) || (sign == -1 && -num <
				-2147483648))
			return (0);
		i++;
	}
	return (1);
}

int	check_duplicates(t_stack *a)
{
	t_node	*i;
	t_node	*j;

	i = a->top;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->value == j->value)
				return (0);
			j = j->next;
		}
		i = i->next;
	}
	return (1);
}
int is_sorted(t_stack *a)
{
    t_node *current;

    current = a->top;
    while (current && current->next)
    {
        if (current->value > current->next->value)
            return (0);
        current = current->next;
    }
    return (1);
}
