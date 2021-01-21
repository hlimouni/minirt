
t_vect				sp_lighting(t_hit *hit, t_ray *ray, t_light *light,
								t_sphere *sp)
{
	t_vect			specular_diffuse;
	t_shade_vars	shade;

	shade.normal = hit->normal;
	shade.to_light = vect_unit(vect_diff(light->l, hit->ray_obj));
	shade.difuse_cst = DIFU_C * fmax(0, vect_dot(shade.normal, shade.to_light));
	shade.diffuse = vect_const_prod(shade.difuse_cst, sp->color_vect);
	shade.view = vect_unit(vect_diff(ray->origin, hit->ray_obj));
	shade.ref_cst = 2 * vect_dot(shade.normal, shade.to_light);
	shade.reflect = vect_const_prod(shade.ref_cst, shade.normal);
	shade.reflect = vect_diff(shade.reflect, shade.to_light);
	shade.reflect = vect_unit(shade.reflect);
	shade.specular = vect_dot(shade.view, shade.reflect);
	shade.specular = SPEC_C * fmax(0, pow(shade.specular, SHINE));
	vect_dot(shade.normal, shade.to_light) < 0 ? (shade.specular = 0) : 0;
	specular_diffuse = vect_const_sum(shade.specular, shade.diffuse);
	specular_diffuse = vect_prod(light->coeff, specular_diffuse);
	return (specular_diffuse);
}

t_vect				pl_lighting(t_hit *hit, t_ray *ray, t_light *light,
								t_plane *pl)
{
	t_vect			specular_diffuse;
	t_shade_vars	shade;

	shade.normal = hit->normal;
	shade.to_light = vect_unit(vect_diff(light->l, hit->ray_obj));
	shade.difuse_cst = DIFU_C * fabs(vect_dot(shade.normal, shade.to_light));
	shade.diffuse = vect_const_prod(shade.difuse_cst, pl->color_vect);
	shade.view = vect_unit(vect_diff(ray->origin, hit->ray_obj));
	shade.ref_cst = 2 * vect_dot(shade.normal, shade.to_light);
	shade.reflect = vect_const_prod(shade.ref_cst, shade.normal);
	shade.reflect = vect_diff(shade.reflect, shade.to_light);
	shade.reflect = vect_unit(shade.reflect);
	shade.specular = vect_dot(shade.view, shade.reflect);
	shade.specular = SPEC_C * pow(shade.specular, SHINE);
	specular_diffuse = vect_const_sum(shade.specular, shade.diffuse);
	specular_diffuse = vect_prod(light->coeff, specular_diffuse);
	return (specular_diffuse);
}

t_vect				cy_lighting(t_hit *hit, t_ray *ray, t_light *light,
							t_cylinder *cy)
{
	t_vect			specular_diffuse;
	t_shade_vars	shade;

	shade.normal = hit->normal;
	shade.to_light = vect_unit(vect_diff(light->l, hit->ray_obj));
	shade.difuse_cst = DIFU_C * fmax(0, vect_dot(shade.normal, shade.to_light));
	shade.diffuse = vect_const_prod(shade.difuse_cst, cy->color_vect);
	shade.view = vect_unit(vect_diff(ray->origin, hit->ray_obj));
	shade.ref_cst = 2 * vect_dot(shade.normal, shade.to_light);
	shade.reflect = vect_const_prod(shade.ref_cst, shade.normal);
	shade.reflect = vect_diff(shade.reflect, shade.to_light);
	shade.reflect = vect_unit(shade.reflect);
	shade.specular = vect_dot(shade.view, shade.reflect);
	shade.specular = SPEC_C * fmax(0, pow(shade.specular, SHINE));
	vect_dot(shade.normal, shade.to_light) < 0 ? (shade.specular = 0) : 0;
	specular_diffuse = vect_const_sum(shade.specular, shade.diffuse);
	specular_diffuse = vect_prod(light->coeff, specular_diffuse);
	return (specular_diffuse);
}
