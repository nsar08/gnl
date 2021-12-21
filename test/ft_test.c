/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsar <marvin@42lausanne.ch>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:35:17 by nsar              #+#    #+#             */
/*   Updated: 2021/11/26 19:06:03 by nsar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE * fPointer;
	fPointer = fopen("read.txt", "r");
	char singleLine[150];

	while(!feof(fPointer))
	{
		fgets(singleLine, 150, fPointer);
		puts(singleLine);
	}
	fclose(fPointer);
	return(0);
}
