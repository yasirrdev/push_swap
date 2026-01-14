/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-maa <ybel-maa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 14:43:09 by ybel-maa          #+#    #+#             */
/*   Updated: 2026/01/14 11:52:42 by ybel-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int *stack_to_array(t_stack *a)
{
    int *array;
    t_node *current;
    int i;

    array = (int *)malloc(sizeof(int) * a->size);
    if (!array)
        return (NULL);
    current = a->top;
    i = 0;
    while (current)
    {
        array[i++] = current->value;
        current = current->next;
    }
    return (array);
}

void bubble_sort(int *array, int size)
{
    int i;
    int tmp;
    int swapped;

    swapped = 1;
    while(swapped)
    {
        swapped = 0;
        i = 0;
        while(i < size - 1)
        {
            if(array[i] > array[i + 1])
            {
                tmp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = tmp;
                swapped = 1;
            }
            i++;
        }
    }

}

void index_stack(t_stack *a, int *arr)
{
    t_node *current;
    int i;

    current = a->top;
    while(current)
    {
        i = 0;
        while(i < a->size)
        {
            if(arr[i] == current->value)
            {
                current->value = i;
                break;
            }
            i++;
        }
        current = current->next;
    }
}
void    indexing(t_stack *a)
{
    int *array;

    array = stack_to_array(a);
    if (!array)
        return ;
    bubble_sort(array, a->size);
    index_stack(a, array);
    free(array);
}
  