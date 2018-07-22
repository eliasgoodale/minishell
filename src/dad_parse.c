/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dad_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 10:41:53 by egoodale          #+#    #+#             */
/*   Updated: 2018/07/18 13:27:00 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/dadshell.h"
/*
What do all these arguments have in common
    ** ' and " are handled in the same manner.
        when a ' is inside of a " and vise versa it is just a character
    Symbols: " denotes the start of a single argument and the following " closes it
            \ is an escape, if encountered escapes the next sequence
            example: 
                    echo hello\\\n will print an extra newline
                    echo "hello\\\n" will print hello\n
                    \->escapes->(sequence)
                    eval(sequence)
                        if sequence[0] == /
                            check next char == n, 


    right now we only have to handle " and return a 2d array of args that makes sense
    rather that a string split of the line;

    First we need to count how many args we actually have and reducing the arg string to what is actually
    meant

    any " must have a closing " and be the start of an argument including everything until the second 
    ". If there are an uneven number of quotes, ask for a dquote>


    -n  "   shit you wrote               " "more" shit "you wrote"

    we can say then that an argument is contained by its first an last character. any ' or " denotes the
    start of a new argument, and its closing ' or " is its last character.

    within each argument escape sequences should be handled automatically by the terminal interpretation of
*/

#define EXISTS_BEFORE(a, b) ((a && !b) || (a && b && a < b) ? a : b)
#define IS_Q(c) (c == '\'' || c == '\"' ? 1 : 0)

/*
size_t  get_argcount(char *line)
{
    VAR(size_t, args, 0);
    VAR(char *, openq, NULL)
    VAR(char *, closeq, NULL);
    while(*line)
    {
        openq = EXISTS_BEFORE(ft_strchr(line, '\''), ft_strchr(line, '\"'));
        line = ft_skipspace(line);
        if(*line && ((line == openq))
        {
            closeq = ft_strchr((line + 1), *line)));
            line = (closeq + 1);
            args++;
            continue;
        }
        else if(*line && !(ft_isspace(*line))
        {
            args++;
            while(*line &&)
        }            

    }
}
*/

char    *request_quote(char quote)
{
    char *line;
    ft_printf("%s", (quote == '\'' ? "squote> " : "dquote> "));
    if (get_next_line(g_dadreadfd, &line) == 1)
        return(line);
    else
        return(NULL);
}

/*
static inline void  normalize_quotes(char *line, size_t len);
{
    char    *norm;
    char    *append;
    char    *inq;
    char    *enq;

    norm = line;
    while(*line)
    {
        if (IS_Q(*line))
        {
            enq = ft_strchr((line + 1), *line);
            if(!enq)
            {
                append = request_quote(*line);
                ft_strcat(norm, append);

            }
            else if (*(enq + 1) && !ft_isspace(*(enq + 1))
                while(line < enq)
                    *(norm++) = *(line++);

            }
            else
            {
                
            }

        }
        *(norm++) = *(line++);
        }
    }
}
*/

static inline void normalize_quotes(char *opnq, char* endq)
{
    VAR(char *, shift, NULL);
    if (!(*opnq))
        return ;
    else if (!(*endq))
        ft_strcat(*opnq, request_quote(*opnq));
    else if (*(endq + 1) && !ft_isspace(*(enq + 1))
    {
        shift = ft_strchr(endq, ' ');
        shift_char_to(endq, (shift ? shift : &endq[ft_strlen(endq)]));
    }
    else
    {
        


}

char **dad_parse(char *line)
{
    char **av;
    size_t ac;

    normalize_quotes(line, ft_strlen(line));
    ac = get_argcount(line); 
}
