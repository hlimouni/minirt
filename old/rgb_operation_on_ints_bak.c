/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_operation_on_ints_bak.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 22:44:15 by hlimouni          #+#    #+#             */
/*   Updated: 2020/03/11 22:44:36 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

unsigned char	*rgbsf_div(int rgb)
{
	unsigned char	*uc;

	uc = (unsigned char *)(&rgb);
	return (uc);
}

int	rgb_prod(int color1, int color2)
{
	unsigned char	*prod;
	unsigned char	*rgb1;
	unsigned char	*rgb2;
	float			r;
	float			g;
	float			b;
	int				*ret;

	prod = (unsigned char *)malloc(sizeof(unsigned char) * 3);
	rgb1 = (unsigned char *)(&color1);
	rgb2 = (unsigned char *)(&color2);
	// printf("sphere color [0] ==> %02x \n", rgb2[0]);
	// printf("sphere color [1] ==> %02x \n", rgb2[1]);
	// printf("sphere color [2] ==> %02x \n", rgb2[2]);
	prod[0] = (((r = (float)rgb1[0] * (float)rgb2[0]) > 255.0)
			? 255 : (unsigned char)r);
	//  printf("r ==> %f\n", r);
	//  printf("the [0] byte of the prod ==> %02x \n", prod[0]);
	prod[1] = (((g = (float)rgb1[1] * (float)rgb2[1]) > 255.0)
			? 255 : (unsigned char)g);
	//  printf("g ==> %f\n", g);
	//  printf("the [1] byte of the prod ==> %02x \n", prod[1]);
	prod[2] = (((b = (float)rgb1[2] * (float)rgb2[2]) > 255.0)
			? 255 : (unsigned char)b);
	// prod[3] = (((rgb1[3] * rgb2[3]) > 0xff) ? 0xff : (rgb1[3] * rgb2[3]));
	// prod[2] = (((rgb1[2] * rgb2[2]) > 0xff) ? 0xff : (rgb1[2] * rgb2[2]));
	ret = (int *)(prod);
	// printf("the final prod is %#08x\n", *ret);
	// rgb2 = (unsigned char *)ret;
	// printf("final prod color [0] ==> %02x \n", rgb2[0]);
	// printf("final prod color [1] ==> %02x \n", rgb2[1]);
	// printf("final prod color [2] ==> %02x \n", rgb2[2]);
	return (*ret);
}

int	rgb_const_div(float cst, int rgb)
{
	unsigned char	*rgb_tab;
	float			rf;
	float			gf;
	float			bf;
	int				r;
	int				g;
	int				b;
	int				color;

	color = 0;
	rgb_tab = (unsigned char *)(&rgb);
	if ((bf = (float)rgb_tab[0] / cst) > 255.0)
		bf = 255.0;
	b = (int)bf;
	printf("div bf => %f\n", bf);
	printf("B => %#02x\n", b);
	if ((gf = (float)rgb_tab[1] / cst) > 255.0)
		gf = 255.0;
	g = (int)gf;
	printf("div gf => %f\n", gf);
	printf("G => %#02x\n", g);
	if ((rf = (float)rgb_tab[2] / cst) > 255.0)
		rf = 255.0;
	r = (int)rf;
	printf("div rf => %f\n", rf);
	printf("R => %#02x\n", r);
	color = (r << 16 | g << 8 | b);
	printf("the product * 0.5 is %#08x\n", color);
	return (color);
}

int	rgb_sum(int color1, int color2)
{
	unsigned char	*prod;
	unsigned char	*rgb1;
	unsigned char	*rgb2;
	int				*ret;
	float			r,g,b;

	prod = (unsigned char *)malloc(sizeof(unsigned char) * 3);
	rgb1 = (unsigned char *)(&color1);
	rgb2 = (unsigned char *)(&color2);
	prod[0] = (((r = (float)rgb1[0] + (float)rgb2[0]) > 255.0)
			? 255 : (unsigned char)r);
	prod[1] = (((g = (float)rgb1[1] + (float)rgb2[1]) > 255.0)
			? 255 : (unsigned char)g);
	prod[2] = (((b = (float)rgb1[2] + (float)rgb2[2]) > 255.0)
			? 255 : (unsigned char)b);
	ret = (int *)(prod);
	return (*ret);
}

int	rgb_const_prod(float cst, int rgb)
{
	unsigned char	*rgb_tab;
	float			rf;
	float			gf;
	float			bf;
	int				r;
	int				g;
	int				b;
	int				color;

	color = 0;
	rgb_tab = (unsigned char *)(&rgb);
	if ((bf = (float)rgb_tab[0] * cst) > 255.0)
		bf = 255.0;
	b = (int)bf;
	printf("bf => %f\n", bf);
	printf("B => %#02x\n", b);
	if ((gf = (float)rgb_tab[1] * cst) > 255.0)
		gf = 255.0;
	g = (int)gf;
	printf("gf => %f\n", gf);
	printf("G => %#02x\n", g);
	if ((rf = (float)rgb_tab[2] * cst) > 255.0)
		rf = 255.0;
	r = (int)rf;
	printf("rf => %f\n", rf);
	printf("R => %#02x\n", r);
	color = (r << 16 | g << 8 | b);
	printf("the product * 0.5 is %#08x\n", color);
	return (color);
}