#include <stdio.h>
#include <libft.h>


int main () {

	// int len = 5;
	// char **args = (char **)malloc(sizeof(char *) * (len + 1));
	// char *val = ft_strdup("hello");
	// int i = 0;
	// for (i = 0; i < len; i++)
	// {
	// 	args[i] = ft_strdup("boom");
	// }
	// free(args[3]);
	// args[3] = "";
	// for (i = 0; i < len; i++)
	// 	printf("%s\n", args[i]);
	// const char *blah = "%";
	// printf("%s", blah);

	t_vector v;
	ft_vector_init(&v, 50);
	ft_vector_append(&v, "hello");
	ft_vector_append(&v, "");
	ft_vector_append(&v, "goodbye");
	printf("%s\n", v.data);

}

/* 
	Char list 
	!, #
*/
