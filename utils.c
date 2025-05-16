#include "ft_prtinf.h"

int	ft_add_to_list(char *str, t_list **list)
{
	t_list	*node;

	node = ft_lstnew(str);
	if (!node)
		return(0);//error, free memory
	ft_lstadd_back(list, node);
	return(1);
}
/*char	*free_and_return_null(char *ptr)
{
	if (ptr)
		free(ptr);
}*/
int ft_print_list(t_list *list)
{
	int count;

	count = 0;
	while(list)
	{
		count+=ft_strlen(list->content);
		ft_putstr_fd(list->content,1);
		list = list->next;
	}
	return(count);
}
int	ft_is_valid_specifier(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%');
}
