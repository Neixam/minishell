/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:31:28 by ambouren          #+#    #+#             */
/*   Updated: 2022/10/29 16:42:12 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARBAGE_H
# define GARBAGE_H
# include "libft.h"

void		ft_garb_add(void *cnt);
void		ft_clean_entries(t_list **garb);
t_hash_set	*garbage(void);

#endif
