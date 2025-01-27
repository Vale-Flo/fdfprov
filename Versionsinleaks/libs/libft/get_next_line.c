/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflores <vflores@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:46:51 by vflores           #+#    #+#             */
/*   Updated: 2025/01/14 16:49:15 by vflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//STRCHR
// static char	*ft_strchr(const char *s, int c)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i])
// 	{
// 		if (s[i] == (unsigned char)c)
// 			return ((char *)&s[i]);
// 		i++;
// 	}
// 	if ((unsigned char)c == '\0')
// 		return ((char *)&s[i]);
// 	return (0);
// }

//NEXT_LINE
// es para obtener la linea siguiente en si.
// Es decir, lo q sobra al avanzar con tu buffer
// Al guardar la proxima linea, se puede utilizar en el main
// al iterar y continuar leyendo lineas
// el "resto" es lo q sobra del buffer si se pasa del \n
// retornamos lo q sobra (el resto) para q quede guardado
// para la proxima linea
// (queda guardado porque usamos static)

static char	*next_line(char *line_buffer)
{
	char	*resto;
	ssize_t	i;

	i = 0;
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
	{
		i++;
	}
	if (line_buffer[i] == 0)
		return (NULL);
	resto = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - i);
	if (*resto == 0)
	{
		free (resto);
		resto = NULL;
	}
	line_buffer[i + 1] = 0;
	return (resto);
}

//FILL_LINE
// aca llenamos una linea con el buffer iterando
// para q se llene la linea hasta q se llegue al \n
static char	*fill_line(int fd, char *resto, char *buffer)
{
	ssize_t	byte_read;
	char	*tmp;

	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(resto);
			return (NULL);
		}
		else if (byte_read == 0)
			break ;
		buffer[byte_read] = 0;
		if (!resto)
			resto = ft_strdup("");
		tmp = resto;
		resto = ft_strjoin (tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (resto);
}

//GNL
char	*get_next_line(int fd)
{
	static char	*resto;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free (resto);
		resto = NULL;
		return (NULL);
	}
	buffer = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	line = fill_line(fd, resto, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	resto = next_line(line);
	return (line);
}

//ACA MI MAIN
// #include <stdio.h>
// int main()
// {
// 	int fd = open("a.txt", O_RDONLY);
// 	// char *a;

// 	// while ((a = get_next_line(fd)))
// 	// {
// 	// 	printf("%s", a);
// 	// }

// 	printf("%s", get_next_line(fd));

// 	return 0;
// }
