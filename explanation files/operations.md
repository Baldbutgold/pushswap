# Stack Operations Explanation

## Push Operations

### `pa` - Push A
- Takes the first (top) element from stack B and places it at the top of stack A
- If stack B is empty, nothing happens
- After execution, the element is removed from B and becomes the new head of A
- Outputs "pa" to stdout

### `pb` - Push B
- Takes the first (top) element from stack A and places it at the top of stack B
- If stack A is empty, nothing happens
- After execution, the element is removed from A and becomes the new head of B
- Outputs "pb" to stdout

## Rotate Operations (Shift Up)

### `ra` - Rotate A
- Shifts all elements in stack A up by one position
- The first (top) element becomes the last element (bottom)
- Example: [1,2,3,4] becomes [2,3,4,1]
- Does nothing if stack has 0 or 1 elements
- Outputs "ra" to stdout

### `rb` - Rotate B
- Same operation as `ra` but performed on stack B
- Outputs "rb" to stdout

## Swap Operations

### `sa` - Swap A
- Swaps the positions of the first two elements at the top of stack A
- Example: [1,2,3,4] becomes [2,1,3,4]
- Does nothing if stack has fewer than 2 elements
- Outputs "sa" to stdout

### `sb` - Swap B
- Same operation as `sa` but performed on stack B
- Outputs "sb" to stdout

## Reverse Rotate Operations (Shift Down)

### `rra` - Reverse Rotate A
- Shifts all elements in stack A down by one position
- The last element (bottom) becomes the first element (top)
- Example: [1,2,3,4] becomes [4,1,2,3]
- Does nothing if stack has 0 or 1 elements
- Outputs "rra" to stdout

### `rrb` - Reverse Rotate B
- Same operation as `rra` but performed on stack B
- Outputs "rrb" to stdout
