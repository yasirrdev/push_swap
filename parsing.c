/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-maa <ybel-maa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:55:13 by ybel-maa          #+#    #+#             */
/*   Updated: 2026/01/14 15:06:22 by ybel-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *parse_args(int argc, char **argv)
{
    t_stack *a;
    a = stack_init();
    if (!a)
        return (NULL);
    if(argc == 2)
        parse_string(argv[1], a);
    else
        parse_multiple_args(argc, argv, a);
    return a;
}
void	parse_string(char *s, t_stack *a)
{
	char	**split;
	int		i;

	split = ft_split(s, ' ');
	if (!split || !split[0])
	{
		print_error();
		exit(1);
	}
	i = 0;
	while (split[i])
		i++;
	while (--i >= 0)
	{
		if (!is_number(split[i]) || !is_overflow(split[i]))
		{
			free_split(split);
			free_stack(a);
			print_error();
			exit(1);
		}
		stack_push_top(a, ft_atoi(split[i]));
	}
	free_split(split);
}
void parse_multiple_args(int argc, char **argv, t_stack *a)
{
    int i;
    int num;

    i = argc - 1;

    while (i > 0)
    {
        if(!is_number(argv[i]) || !is_overflow(argv[i]) || !check_duplicates(a))
        {
            free_stack(a);
            print_error();
        }
        num = ft_atoi(argv[i]);
        stack_push_top(a, num);
        i--;
    }
}