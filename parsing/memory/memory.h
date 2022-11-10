/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 16:18:51 by yboudoui          #+#    #+#             */
/*   Updated: 2022/11/06 16:24:22 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
# define MEMORY_H

# include <stdlib.h>
# include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
#endif
