<img src="https://user-images.githubusercontent.com/105823790/171860148-c0b11827-51de-42e1-8213-e1e83249b081.png" width="150" height="150">

# push_swap

The **push_swap** project is simple sorting algorithm project. You have at your disposal a set of int values, 2 stacks and a set of instructions to manipulate both stacks.

This project contains 2 programs:
- The first, named **checker**, takes integer arguments and reads instructions on the standard output. Once read, checker executes them and displays `OK` if the stack was effectively sorted. Otherwise, it displays `KO`.
- The second one called **push_swap** prints on the standard output the list of instructions (see below) needed to sort the stack.

## push_swap instructions

- **sa**: *swap a* - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
- **sb**: *swap b* - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
- **ss**: sa and sb at the same time.
- **pa**: *push a* - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
- **pb**: *push b* - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
- **ra**: *rotate a* - shift up all elements of stack a by 1. The first element becomes the last one.
- **rb**: *rotate b* - shift up all elements of stack b by 1. The first element becomes the last one.
- **rr**: ra and rb at the same time.
- **rra**: *reverse rotate a* - shift down all elements of stack a by 1. The last element becomes the first one.
- **rrb**: *reverse rotate b* - shift down all elements of stack b by 1. The last element becomes the first one.
- **rrr**: rra and rrb at the same time.



![1_LjwfAbYXsjbxtaS-bCUJ7Q](https://user-images.githubusercontent.com/105823790/169652500-fe8c0f15-35e1-4bbc-acd6-422d3b04283f.png)


[![forthebadge](https://forthebadge.com/images/badges/made-with-c.svg)](https://forthebadge.com)
