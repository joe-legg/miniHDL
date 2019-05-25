# miniHDL
The compiler for a mini hardware description language that compiles to Verilog.

### ! WARNING !
This is my first compiler so expect to find lots of bugs and badly written code.
Also, it is incomplete. I am currently working on a rewrite.

## Compiling
To compile miniHDL from source you will need the following programs.
- [lemon--](https://github.com/ksherlock/lemonxx) - A fork of the [lemon](https://www.hwaci.com/sw/lemon/) parser generator.
- [flex](https://github.com/westes/flex) - A lexer generator.
- [Clang++](https://clang.llvm.org/)

First clone the repository.
```bash
$ git clone "https://github.com/CoffeeTurtle1/miniHDL"
$ cd miniHDL/
```

Then run the following command to build it.
```bash
$ ./build.sh
```

Optionally you can copy the minihdl binary from the `bin/` folder into
`/usr/bin`.
```bash
$ sudo cp bin/minihdl /usr/bin
```

## A miniHDL Tutorial
miniHDL is made up of modules whitch are made up of boolean expressions. Here is
an example module.
```
mod moduleName inp a, out b;
    b <- a xor true;
end
```
To compile the code run the following command.
```
$ minihdl -o Verilog.v filename.minihdl
```
This will generate the Verilog code for `filename.minihdl`. To test the code
you will need to write a test bench in Verilog.

How does it work? The first line tells the compiler to create a module with the
name `moduleName` and two ports `inp a`, this is an input, and `out b`, this is
an output.
```
mod moduleName inp a, out b;
```
The second line connects the output `b` to the expression `a xor true`.
```
b <- a xor true;
```
And finally, the last line ends the module definition.

Here is a list of operations you can use in an expression.

| Operation | Type             | Example  |
|-----------|------------------|----------|
| xor       | Binary operation | a xor b  |
| and       | Binary Operation | a and b  |
| or        | Binary Operation | a or b   |
| not       | Unary Operation  | not true |

Brackets are also supported.
```
not(true and true);
```

Module instantiation.
```
moduleName instanceName port1, port2;
```

### Features Currently Not Implemented
```
wire testWire;

testWire <- a xor b;
c <- testWire or true;
```
When statement.
```
when binaryExpression;
    a <- b xor not c;
end
```
When, else.
```
when binaryExpression;
    a <- b xor not c;
else
    a <- not b;
end
```
