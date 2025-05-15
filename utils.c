#include "ft_prtinf.h"

void ft_handle_error(t_list **list)
{
	//free the list
	//print 0
}
int	ft_add_to_list(char *str, t_list **list)
{
	t_list	*node;

	node = ft_lstnew(str);
	if (!node)
		return(0);//error, free memory
	ft_lstadd_back(list, node);
	return(1);
}
char	*free_and_return_null(char *ptr)
{
	if (ptr)
		free(ptr);
}
void ft_print_list(t_list *list)
{
	while(list)
	{
		ft_putstr_fd(list->content,1);
		list = list->next;
	}
}
int	ft_is_valid_specifier(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%');
}
