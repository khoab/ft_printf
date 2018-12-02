# ft_printf
Because I'm tired of using putstr, putnbr, ...

This project aim to getting familar with C, know how to va_arg, va_start, ... and the most important thing is create my own version of printf to use while I'm studying @ 42SiliconValley.

<b>What is my printf name?</b>
<br />I will call my printf is ft_printf from now for the whole project.

<b>What can b_printf does?</b>
<br />For now, ft_printf only handle:

<br />• Manage the following conversions: csp
<br />• Manage the following conversions: diouxX with the following flags: hh, h, l and ll.
<br />• Manage the following conversion: f with the following flags: l and L.
<br />• Manage %%
<br />• Manage the flags #0-+ and space
<br />• Manage the minimum field-width
<br />• Manage the precision.

<br />All the other case and feature couldn't be handle on purpose.

<b>How long did i take from me to finish ft_printf?</b>
<br /> 1 weeks and 6 days, from scratch.

<b> What is some Norme for my ft_printf?</b>
<br /><b>1></b> Each function is limited @ 25 lines/ft (Not include function declaration and open-close bracket.
<br /><b>2></b> Maximum is 5 function/file. No more than 5 function will be accepted.
<br /><b>3></b> Only: While-loop, If-Else if/else statement will be accepted. All of the other condition or loop is terminated.
<br /><b>4></b> Only allow to use: <stdarg.h>, and those function: write, malloc, free. All the other lib or function that not declare is terminated. If you want to use any function other than these, write it your own and add it to your own Libft. 
## Compiling

Make sure to edit the `Makefile` to point to
[libft](https://github.com/khoab/libft). Run `make` to compile the
library. Use it like you would use the `printf` function (Only handle those case listed above for now):

```c
size_t  i;

i = 42;
ft_printf("value: %d\n", i);

// value: 42
```

## License
`ft_printf` is under the **GNU General Public License 3.0**.
