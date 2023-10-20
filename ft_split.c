#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

static size_t   count_words(const char *str, char c)
{
    size_t  in_word;
    size_t  i;
    size_t  words;

    in_word = 0;
    i = 0;
    words = 0;
    while (str[i] != '\0')
    {
        if (str[i] == c)
        {
            in_word = 0;
        }
        else if (!in_word)
        {
            in_word = 1;
            words++;
        }
        i++;
    }
    return (words);
}

char    **ft_split(char const *s, char c)
{
    int     i;
    int     j;
    int     k;
    int     start;
    int     num_words;
    char    **words;

    i = 0;
    j = 0;
    k = 0;
    start = 0;
    num_words = count_words(s, c);
    words = (char **)malloc((num_words + 1) * sizeof(char *));
    if (words == NULL)
        return (NULL);
    while (s[i] != '\0')
    {
        if (s[i] == c)
            i++;
        else
        {
            start = i;
            while (s[i] != '\0' && s[i] != c)
                i++;
            words[j] = (char *)malloc((i - start + 1) * sizeof(char));
            if (words[j] == NULL)
            {
                while (j > 0)
                    free(words[--j]);
                free(words);
                return (NULL);
            }
            k = 0;
            while (k < i - start)
            {
                words[j][k] = s[start + k];
                k++;
            }
            words[j][k] = '\0';
            j++;
        }
    }
    words[j] = NULL;
    return (words);
}
