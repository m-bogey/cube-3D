/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebriere <ebriere@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 21:35:10 by ebriere           #+#    #+#             */
/*   Updated: 2024/10/16 21:35:11 by ebriere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

int			is_whitespace(int c);
int			str_is_only_white_space(char *str);
char		**store_file_in_tab(int fd, char *file);
int			parse_input(t_cube *cube, char **argv);
int			store_map_info(t_cube *cube, char **file_info);
int			check_if_reach_map(char *str);
int			is_multiple_path(char *str);
char		**store_map(char **file);
int			check_map(char **map, t_player *pos);
int			check_wall(char **map);
int			check_wall_corner(char **map, size_t map_height);
int			check_map_info(t_tab *details);
long long	convert_rgb_to_hexa(char *str);

#endif
