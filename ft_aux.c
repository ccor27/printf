#include "ft_prtinf.h"

void ft_add_to_list(char *str, t_list **list)
{
	t_list	*node;

	node = ft_lstnew(str);
	if (!node)
		free(node);//?
	ft_lstadd_back(list, node);
}
char *free_and_return_null(char *ptr)
{
    if (ptr)
        free(ptr);
    return (NULL);
}
