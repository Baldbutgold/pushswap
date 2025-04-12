# Why Radix Sort Shows "Static" Behavior

## Deterministic Nature
- Radix sort performs a fixed number of operations for a given input size
- It doesn't adapt to the actual disorder of the data

## For 100 Numbers:
- With ranks 0-99, we need log₂(100) ≈ 7 bits
- Always performs exactly 7 passes through the entire stack
- Each pass requires approximately 100 operations
- This results in ~700 operations regardless of initial order

## Optimization Possibilities:

1. **Bit count optimization**
   ```c
   // Modify get_max_bits to count only necessary bits
   int get_max_bits(t_list *stack)
   {
       int max_rank = ft_lstsize(stack) - 1;
       int max_bits = 0;
       
       while (max_rank > 0)
       {
           max_rank >>= 1;
           max_bits++;
       }
       return (max_bits);
   }
   ```

2. **Early termination check**
   ```c
   // Add this check in the radix_sort function
   if (is_sorted(*stack_a))
       return;
   ```

3. **Hybrid approach**
   - Use different algorithms based on stack characteristics
   - Consider insertion sort for nearly sorted segments
