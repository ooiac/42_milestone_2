# Milestone 2 — push_swap, minitalk, fract-ol

Three C projects with different constraints: a sorting algorithm that can only use stack instructions, a client/server protocol built from Unix signals, and an interactive fractal viewer using MiniLibX.

## push_swap

Source: [`push_swap/`](push_swap/)

`push_swap` takes a sequence of integers in stack A and prints instructions that sort them in ascending order. Stack B starts empty. It isn't supposed to print the sorted array: the output is a program of stack operations that a checker can replay.

| Instruction | Effect |
| --- | --- |
| `sa`, `sb`, `ss` | Swap the top two elements of A, B, or both. |
| `pa`, `pb` | Move the top element from one stack to the other. |
| `ra`, `rb`, `rr` | Rotate a stack upward (top element goes to bottom). |
| `rra`, `rrb`, `rrr` | Reverse-rotate (bottom element goes to top). |

The challenge is not only reaching the correct order, but using a low number of operations. The implementation sorts three elements directly. For larger inputs, it moves candidates to B, computes a target node and movement cost, and chooses a cheap move. When both stacks need to rotate in the same direction, it can rotate them together; after moving values back into A, it brings the minimum to the top. This is why the code has `get_cheapest`, target-node initialization, and combined-rotation helpers. Input parsing also matters: invalid integers, overflow, or duplicate values must be rejected before sorting.

```sh
cd push_swap
make
./push_swap 4 1 3 2
./push_swap $(shuf -i 1-100 -n 100) | wc -l
```

The second command counts how many moves the algorithm printed. To validate correctness, feed those moves to a compatible `checker` binary when available. Repeated values are not valid `push_swap` input, so a sample containing duplicates would be misleading.

The source is split between stack operations, validation, and sort routines such as `sort_three`, `sort_stacks`, and the A-to-B/B-to-A transfer logic. The build links the project's copies of libft and ft_printf.

## minitalk

Source: [`minitalk/`](minitalk/)

Two processes send text without a socket or pipe. The server prints its PID; the client takes that PID and a message, then sends each character one bit at a time using user-defined signals.

```text
client                             server
character -> 8 bits
  0 -> SIGUSR1  ---------------->  receive bit 0
  1 -> SIGUSR2  ---------------->  receive bit 1
  ...                             collect 8 bits -> character
                                  write the character
```

The client uses `kill(pid, signal)` to deliver a signal to the server. The server's signal handler reconstructs bytes by shifting and combining their bits. Bit order must match on both sides. The message also needs a terminator so the server can tell when it is complete.

Ordinary Unix signals are not a queued byte stream. Sending them too quickly can cause missed information, so synchronization is a real part of the project. The **bonus** uses acknowledgments from the server: the client waits for confirmation rather than only relying on a delay between signals.

```sh
cd minitalk
make
./server
# In another terminal, replace the PID with the one printed by the server:
./client 12345 "hello"

make bonus
./server_bonus
# In another terminal:
./client_bonus 12345 "hello"
```

The bonus executables have different names from the mandatory ones. Testing should include long strings, consecutive messages, non-ASCII text if supported by the implementation, and an invalid PID. Signal handlers also have restrictions on which functions are safe to call.

## fract-ol

Source: [`fract-ol/`](fract-ol/)

An interactive Mandelbrot/Julia viewer. It turns each screen coordinate into a complex number, iterates a formula, and chooses the pixel color according to how quickly the sequence escapes.

### The mathematics

Both sets use the iteration

\[
z_{n+1} = z_n^2 + c
\]

For the **Mandelbrot set**, each pixel supplies `c` and iteration starts at `z = 0`. For a **Julia set**, each pixel supplies the initial `z` while `c` is fixed. Once the magnitude of `z` exceeds 2, the point is known to escape. The program uses a maximum iteration count to decide when to stop checking a pixel; it cannot prove that every non-escaping point is in the set.

For `z = x + yi`, squaring gives real and imaginary parts that can be calculated without a complex-number library:

```text
next_x = x*x - y*y + c_real
next_y = 2*x*y     + c_imag
```

### Rendering and controls

Pixels are mapped to a region of the complex plane. Zooming changes that mapping, not the fractal equation. A mouse-centered zoom also adjusts the offsets so the point below the cursor stays in roughly the same place. The project uses MiniLibX, with event handlers for zooming, movement, and closing the window.

```sh
cd fract-ol
make
./fractol mandelbrot
./fractol julia -0.4 0.6

# Bonus build (uses the same executable name):
make bonus
```

The Makefile expects the bundled `minilibx-linux` and X11 development libraries, and links the math library with `-lm`. It has separate `src/` and `src_bonus/` implementations. Use the mouse wheel to zoom and the keyboard controls to move or change the view according to the version you're running.

These projects touch different parts of Unix programming, but the main pattern is the same: the constraints determine the design. In `push_swap` it's the instruction set; in `minitalk` it's signal delivery; in `fract-ol` it's the mapping between coordinates and an interactive renderer.
