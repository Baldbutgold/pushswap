#include "push_swap.h"

t_list  *init_stack(int ac, char **av)
{
    t_list  *stack;
    int     i;
    int     num;

    stack = NULL;
    i = 1;
    while (i < ac)
    {
        // Make sure atoi properly handles "0" as a valid input
        // Check if the argument is valid (only digits, or '-' followed by digits)
        if (!is_valid_number(av[i]))
            return (error_free_stack(&stack));
            
        num = ft_atoi(av[i]);
        
        // Check for duplicates (be careful not to consider 0 as "no value")
        if (is_duplicate(stack, num))
            return (error_free_stack(&stack));
            
        // Add the number to the stack
        if (!add_to_stack(&stack, num))
            return (error_free_stack(&stack));
            
        i++;
    }
    
    // Assign ranks to the stack elements
    assign_ranks(stack);
    
    return (stack);
}

// Helper function to validate number strings
int is_valid_number(char *str)
{
    int i;
    
    i = 0;
    // Handle negative sign
    if (str[0] == '-')
        i++;
    
    // Check for empty string or just a '-'
    if (!str[i])
        return (0);
        
    // Ensure all characters are digits
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    
    // Validate the number is within integer range (prevent overflow)
    if (ft_atoi_overflow_check(str) != 0)
        return (0);
        
    return (1);
}

// Check for duplicate values
int is_duplicate(t_list *stack, int num)
{
    t_list *temp;
    
    temp = stack;
    while (temp)
    {
        if (temp->content == num)
            return (1);
        temp = temp->next;
    }
    return (0);
}