# 42 School — Milestone 2

Welcome to **Milestone 2** of the 42 School curriculum! This milestone covers **algorithms, inter-process communication, and graphics programming**. You'll build tools that push the boundaries of what you learned in Milestone 1.

## Overview

Milestone 2 consists of three distinct projects, each focusing on different aspects of systems and application programming:

| Project | Type | Language | Key Concepts |
|---------|------|----------|--------------|
| **Push Swap** | Algorithm | C | Sorting algorithms, stack data structures, optimization |
| **Minitalk** | IPC System | C | Signal handling, inter-process communication, bit manipulation |
| **Fract-ol** | Graphics Application | C | Real-time rendering, complex numbers, graphics library |

---

## Project 1: Push Swap

### What It Is

**Push Swap** is an algorithm design challenge where you must sort a stack of numbers using only a limited set of operations. The goal is to sort stack A while using stack B as auxiliary storage, with the constraint of minimizing the total number of operations.

### The Challenge

Given:
- Stack A with N random integers
- Stack B (initially empty)
- Only 6 allowed operations:
  - `sa`: Swap the first two elements of stack A
  - `sb`: Swap the first two elements of stack B
  - `pa`: Push the first element from B to A
  - `pb`: Push the first element from A to B
  - `ra`: Rotate stack A upward (first element goes to end)
  - `rb`: Rotate stack B upward
  - `rra`: Reverse rotate A (last element becomes first)
  - `rrb`: Reverse rotate B

Your task: Output the **minimum sequence of operations** needed to sort stack A in ascending order.

### Why It's Non-Trivial

You cannot simply print "sort this array." You must:
1. **Analyze the input** to understand its current state
2. **Choose an algorithm** that performs well on random data
3. **Implement efficient operations** that move numbers strategically
4. **Minimize the operation count** - the fewer operations, the better your score

### Typical Algorithms Used

- **Bubble sort approach**: Simple but inefficient (hundreds of operations)
- **Radix sort approach**: Sort by bit significance, much more efficient (thousands of moves for larger inputs, but scaling is better)
- **Custom heuristics**: Analyze the input and use division strategies

### Example

Input: `3 1 4 1 5`

A possible solution sequence:
```
pb
pb
pb
pb
sa
ra
pa
pa
pa
pa
```

Result: Stack A becomes `1 1 3 4 5` (sorted)

### Constraints & Scoring

- **Mandatory**: Sort any input without errors
- **Bonus**: Bonus programs for stack B operations (`rrb`, `rrra`, `rra`)
- **Score**: Based on operation count
  - Under 5,500 operations for 100 random numbers: Excellent
  - Under 700 operations: Outstanding (bonus range)

### Compilation & Usage

```bash
cd push_swap
make
./push_swap 3 1 4 1 5 9 2 6
# Output: sequence of operations

# Or test with a generated list
./push_swap $(shuf -i 1-100 -n 100)

# To see if it's correct, use the checker (if available)
# ./checker 3 1 4 1 5 < operations.txt
```

---

## Project 2: Minitalk

### What It Is

**Minitalk** is a communication system between two processes using only **Unix signals**. You build a server that receives messages from a client, where each message is transmitted bit-by-bit using signals as the transport layer.

### How Signals Work as Communication

Unix provides two user-defined signals:
- **SIGUSR1**: Signal 1 (represents bit 0)
- **SIGUSR2**: Signal 2 (represents bit 1)

The brilliance of Minitalk: Encode each character as 8 bits, then send those bits to the server using signals. The server reconstructs the character from the signals it receives.

### Architecture

```
CLIENT                          SERVER
  |                               |
  +---> Send bit 0 (SIGUSR1) ---> |
  |     (8 signals per char)       | Signal handler receives signals
  |                               | Reconstruct bits into characters
  |     Send "H" (binary)         | Display "H" on stdout
  |     01001000                   |
  +---> SIGUSR1 (0)              |
  +---> SIGUSR1 (0)              |
  +---> SIGUSR1 (0)              |
  +---> SIGUSR1 (0)              |
  +---> SIGUSR2 (1)              |
  +---> SIGUSR1 (0)              |
  +---> SIGUSR1 (0)              |
  +---> SIGUSR1 (0)              |
  |     (pause between chars)     |
  +---> ... send "e" ...         |
```

### Key Challenges

1. **Timing**: The client must wait between signals so the server can process them
2. **Synchronization**: Ensure the server has received all bits before the next character starts
3. **Binary Encoding**: Correctly convert characters to binary and reconstruct them
4. **Bit Order**: Handle Most Significant Bit (MSB) first vs. Least Significant Bit (LSB) first

### Features (with Bonus)

**Mandatory:**
- Server displays its PID on startup
- Client takes PID and message as arguments
- Server receives and displays the message
- Basic signal handling works

**Bonus Features Implemented:**
- Confirmation signals: Server sends acknowledgment back to client after each bit
- Multiple messages: Client waits for server confirmation before sending next character
- Enhanced reliability with handshaking protocol

### Example Usage

```bash
# Terminal 1: Start the server
./server
# Output: 1234  (the server's PID)

# Terminal 2: Send a message
./client 1234 "Hello, World!"
# Terminal 1 receives and displays: Hello, World!
```

### Learning Outcomes

- **Signal handling**: Using `signal()` and custom signal handlers
- **Bit manipulation**: Shifting, masking, and testing individual bits
- **Process IDs**: Working with PIDs for inter-process communication
- **Timing and concurrency**: Understanding signal delivery timing
- **System calls**: `kill()`, `pause()`, `sleep()`, `usleep()`

### Compilation & Usage

```bash
cd minitalk
make              # Build mandatory version
make bonus        # Build with bonus features
./server &        # Start server in background
./client [PID] "message"
```

---

## Project 3: Fract-ol

### What It Is

**Fract-ol** is a graphics program that renders **fractal sets in real-time**. Specifically, it visualizes the Mandelbrot set and Julia set, two of the most famous fractals in mathematics. The program uses the **MLX graphics library** (a minimal graphics library created for 42 projects) to render pixels and handle user interaction.

### What Are Fractals?

Fractals are infinitely complex mathematical objects that exhibit self-similarity at different scales. Key characteristics:
- **Self-similar**: Zooming in reveals smaller versions of the same pattern
- **Infinite detail**: No matter how much you zoom, more detail appears
- **Complex equations**: Generated by iterating simple mathematical formulas

### The Mandelbrot Set

For each pixel (representing a complex number c):
```
z = 0
repeat: z = z² + c
Stop when |z| > 2 (escapes to infinity)
Count iterations until escape
Color the pixel based on iteration count
```

Points that never escape belong to the Mandelbrot set (typically black).

### The Julia Set

Similar to Mandelbrot, but with a fixed complex constant k instead of varying c:
```
z = c (starting from pixel)
repeat: z = z² + k
Count iterations
Color based on iterations
```

Different k values produce dramatically different patterns. With Minitalk bonus, you might even send new Julia parameters!

### Features Implemented

**Mandatory:**
- Render Mandelbrot set in a window
- Zoom with mouse scroll
- Pan/move around with arrow keys or mouse
- Exit with ESC key
- Custom color schemes

**Bonus Features Implemented:**
- Multiple fractal types (Mandelbrot, Julia sets with various parameters)
- Mouse support for zooming and panning
- Real-time rendering
- Animation/color cycling effect
- Smooth zooming with depth preservation
- Multiple color palettes

### User Interaction

- **Scroll wheel**: Zoom in/out
- **Arrow keys**: Pan around
- **Mouse click**: Center zoom at that point
- **ESC**: Close the window
- **Numpad**: Switch between fractals (if bonus implemented)

### How It Works: Rendering Pipeline

```
For each pixel (x, y) on screen:
1. Convert screen coordinates to complex plane coordinates
2. Use Mandelbrot or Julia equation
3. Iterate the formula up to MAX_ITERATIONS
4. Get iteration count at escape
5. Map count to color
6. Display pixel with that color
```

### Complexity Behind the Beauty

Despite appearing magical, fractals require:
- **Complex number arithmetic**: Real and imaginary parts
- **Coordinate transformation**: Screen space to complex plane
- **Efficient iteration**: Handle thousands of pixels per frame
- **Color interpolation**: Smooth gradients between iteration counts
- **Graphics API**: Understanding MLX library functions

### Example Usage

```bash
cd fract-ol
make
./fractol mandelbrot
# Window opens showing Mandelbrot set

./fractol julia -0.4 0.6
# Window opens showing specific Julia set

# Interact with mouse and keyboard
```

### Learning Outcomes

- **Graphics programming**: Pixel manipulation and rendering
- **Complex number mathematics**: Understanding fractal equations
- **Real-time computation**: Optimizing for interactive frame rates
- **Graphics library usage**: MLX API and window management
- **Event handling**: Responding to keyboard and mouse input
- **Color theory**: Creating appealing visual palettes

---

## Comparative Difficulty & Complexity

| Project | Difficulty | Lines of Code | Key Skills | Time Estimate |
|---------|------------|---------------|-----------|--------------|
| Push Swap | Medium | 800-1500 | Algorithms, optimization | 1-2 weeks |
| Minitalk | Easy-Medium | 200-400 | Signals, bit manipulation | 3-5 days |
| Fract-ol | Medium-Hard | 1000-2000 | Graphics, math, rendering | 2-3 weeks |

---

## Curriculum Context

| Milestone | Projects | Focus |
|-----------|---------|-------|
| 0 | libft | Build foundational C library |
| 1 | ft_printf, get_next_line | I/O and string manipulation |
| **2** | **push_swap, minitalk, fract-ol** | **Algorithms, IPC, graphics** |
| 3 | minishell, philosophers | Systems programming & concurrency |
| 4 | cub3d | Advanced graphics (ray-casting 3D) |

Milestone 2 is where students transition from "learning C basics" to "building meaningful applications." Each project teaches distinct domain knowledge: algorithms, systems programming, and graphics.

---

## Key Concepts Across Projects

### Bit Manipulation (Minitalk)
- Understanding binary representation
- Bit shifting (`<<`, `>>`)
- Bit masking (`&`, `|`, `^`)
- Essential for low-level programming

### Algorithm Optimization (Push Swap)
- Measuring algorithm efficiency
- Trade-offs between simplicity and performance
- Iterative improvement and profiling
- Understanding problem constraints

### Real-Time Graphics (Fract-ol)
- Complex number arithmetic
- Coordinate transformations
- Event-driven programming
- Visual feedback and user experience

---

## Resources & References

### Push Swap
- Stack data structure basics
- Sorting algorithm analysis
- Big O notation for complexity
- Radix sort: https://en.wikipedia.org/wiki/Radix_sort

### Minitalk
- `signal(2)`: `man signal`
- `kill(2)`: `man kill`
- `pause(2)`, `usleep(3)`: `man usleep`
- Unix signal handling guide

### Fract-ol
- MLX Library documentation (provided in school)
- Complex numbers: https://en.wikipedia.org/wiki/Complex_number
- Mandelbrot set: https://en.wikipedia.org/wiki/Mandelbrot_set
- Julia set: https://en.wikipedia.org/wiki/Julia_set
- Fractal geometry mathematics

---

## Tips for Success

1. **Push Swap**: Start with a basic algorithm, get it working, then optimize. Test with various inputs (nearly sorted, reverse sorted, duplicates).

2. **Minitalk**: Get the basic signal handler working first, then add handshaking. Use `usleep()` to debug timing issues.

3. **Fract-ol**: Understand complex numbers before writing the rendering loop. Test your math in a simple program first.

4. **All Projects**: Write modular, testable code. Create helper functions and keep files focused on single responsibilities.

5. **Debugging**: Use `printf()` debugging and simple test cases before testing on edge cases.

---

## Checklist for Success

### Push Swap
- [ ] Stack initialization and parsing works
- [ ] All operations (swap, push, rotate) implemented correctly
- [ ] Sorting algorithm chosen and understood
- [ ] Basic cases (2 elements, 3 elements) work
- [ ] Larger inputs sort correctly
- [ ] Operation count is reasonable (under limits)
- [ ] Handles duplicates and negative numbers

### Minitalk
- [ ] Server starts and prints PID correctly
- [ ] Client sends characters bit-by-bit
- [ ] Server reconstructs and displays message correctly
- [ ] Timing allows reliable transmission
- [ ] Multiple messages work
- [ ] Bonus: Acknowledgment signals work
- [ ] Bonus: Works with longer messages

### Fract-ol
- [ ] Window opens and displays fractal
- [ ] Mandelbrot set renders correctly (black is set interior)
- [ ] Julia set renders with correct parameters
- [ ] Mouse scroll zooms properly
- [ ] Panning/navigation works
- [ ] Colors are visible and meaningful
- [ ] Bonus: Multiple fractals accessible
- [ ] Bonus: Smooth, interactive experience

---

**Good luck with Milestone 2! This is where systems programming meets creative problem-solving.**
