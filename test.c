#include <stdio.h>
#include <libft.h>

char **g_envv;

char ** init_envv()
{
	return(ft_strsplit("hello how are you", ' '));
}

char *return_index()
{
	return(g_envv[1]);
}

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

	// t_vector v;
	// ft_vector_init(&v, 50);
	// ft_vector_append(&v, "hello");
	// ft_vector_append(&v, "");
	// ft_vector_append(&v, "goodbye");



	// char *data = ft_strdup("$TERMi~$LESS");
	// char *envv_token = ft_strtok(data, "$");

	// char *end = find_next_any(data, "\0");

	// while(envv_token)
	// {
	// 	ft_vector_append(&v, envv_token);
	// 	envv_token = ft_strtok(NULL, "$");
	// }
	// printf("%s\n", v.data);

	char *var;

	g_envv = init_envv();
	var = return_index();

	free(var);
	var = NULL;
	var = ft_strdup("new thing");
	printf("%s", g_envv[1]);
}

/* 
	Char list 
	!, #
*/
