# Thread Safe Vector

Just a handy library I've been using across a few code bases.

## Running

Standard `Makefile` implementation of:
```shell
make clean install run
```

`clean` - Obviously, removes previous builds

`build` - Compiles everything

`run` - Does what it says on the tin


## Why no lib/so?

Maybe in the future, but I'm building this for multi-platform, so source code just made my life easier.

## Aren't you just re-inventing the wheel?

Absolutely, just not a big fan of the TBB/Boost alternatives. 
Also, this allows me to use it as a Gateway if I want to implement anything else in the future.

## What in ever-loving hell are those defines?

Madness personified in code