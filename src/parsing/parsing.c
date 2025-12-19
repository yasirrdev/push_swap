/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-maa <ybel-maa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:55:13 by ybel-maa          #+#    #+#             */
/*   Updated: 2025/12/19 13:59:58 by ybel-maa         ###   ########.fr       */
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
void parse_multiple_args(int argc, char **argv, t_stack *a)
{
    int i;
    int num;

    i = argc - 1;

    while (i > 0)
    {
        if(!is_number(argv[i]) || !is_overflow(argv[i]) || !check_duplicates(argv[i]))
        {
            free_stack(a);
            print_error();
        }
        num = ft_atoi(argv[i]);
        stack_push_top(a, num);
        i--;
    }
}

