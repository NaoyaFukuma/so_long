/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 10:36:25 by nfukuma           #+#    #+#             */
/*   Updated: 2022/09/17 02:09:25 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*new_mem;

	if (count == 0 || size == 0)
		return (ft_calloc(1, 1));
	if (__SIZE_MAX__ / count < size)
		return (NULL);
	new_mem = malloc(count * size);
	if (new_mem == NULL)
		return (NULL);
	ft_bzero(new_mem, count * size);
	return ((void *)new_mem);
}
