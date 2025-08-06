# custom-random

[Russian documentation](README.ru.md)

## Author
[jrius](https://vk.com/s.fridom) | [t.me/dcapybarov](https://t.me/dcapybarov)

## Description

This module extends the standard random function with seed control support.  
Developed for compiler version 3.10.8.

Uses Linear Congruential Generator (LCG) algorithm:
```
Xn+1 = (a * Xn + c) mod m

where:
  a = 214013
  c = 2531011
  m = 2^31
```

## Usage

### Main Function

```pawn
// Standard generation
new value = random(100);

// Generation with custom seed
new value = random(100, .seed = 12345);
```

### Additional Functions

- **SeedRandom(seed)**  
  Sets the initial value for the generator.

- **RandomEx(...)**  
  Takes multiple values and seed (last argument).  
  Returns the sum of random values for each argument.

## Examples

```pawn
// 1. Standard generation
new rand = random(100); // 0-100

// 2. With custom seed
new rand = random(50, .seed = 12345);

// 3. Multiple generation
new sum = RandomEx(10, 20, 30, 12345);
```

## Why?

The original random number generator on the server was discovered to be predictable when seed is known.  
This module provides an alternative method for random number generation.
