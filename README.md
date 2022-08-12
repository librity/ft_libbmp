<h3 align="center">42 São Paulo - ft_libbmp</h3>

<div align="center">

[![Norminette v3](https://github.com/librity/ft_libbmp/actions/workflows/norminette_v3.yml/badge.svg)](https://github.com/librity/ft_libbmp/actions/workflows/norminette_v3.yml)
![42 São Paulo](https://img.shields.io/badge/42-SP-1E2952)
![License](https://img.shields.io/github/license/librity/ft_libbmp?color=yellow)
![Code size in bytes](https://img.shields.io/github/languages/code-size/librity/ft_libbmp?color=blue)
![Lines of code](https://img.shields.io/tokei/lines/github/librity/ft_libbmp?color=blueviolet)
![Top language](https://img.shields.io/github/languages/top/librity/ft_libbmp?color=ff69b4)
![Last commit](https://img.shields.io/github/last-commit/librity/ft_libbmp?color=orange)

</div>

<p align="center"> A a bitmap library integrated with 42's <a href="https://github.com/42Paris/minilibx-linux">MinilibX</a>.
  <br>
</p>

---

## 📜 Table of Contents

- [About](#about)
- [Getting Started](#getting_started)
- [Notes](#notes)
- [42 São Paulo](#ft_sp)
- [Resources](#resources)

## 🧐 About <a name = "about"></a>

This is a bitmap library that lets you create, draw to
and save an int buffer or [MinilibX](https://github.com/42Paris/minilibx-linux)
image as a `.bmp` file.

It also helps you create switch between different representations of colors
like `int` and individual red, green, blue and transparency `char`s.

I've used it in the following projects:

- https://github.com/librity/ft_fractol
- https://github.com/librity/ft_minirt

## 🏁 Getting Started <a name = "getting_started"></a>

### ⚙️ Prerequisites

All you need is a C compiler (`gcc` or `clang`).
The make rule opens the example file with
[`ffplay`](https://ffmpeg.org/download.html),
so it's nice to have.

### 🖥️ Installing

Clone the repo and build with `make`:

```bash
$ git clone https://github.com/librity/ft_libbmp.git
$ cd ft_libbmp
$ make example
```

The image of a beautiful gradient should open in a new window.

## 📝 Notes <a name = "notes"></a>

I know you can write the magic bits as a `short` using `# pragma pack(push, 1)`.
I didn't do it for two reasons:

1. I'm getting the norminette error: `Unrecognized preprocessor statement`
2. It's clearer this way.

## 🛸 42 São Paulo <a name = "ft_sp"></a>

Part of the larger [42 Network](https://www.42.fr/42-network/),
[42 São Paulo](https://www.42sp.org.br/) is a software engineering school
that offers a healthy alternative to traditional education:

- It doesn't have any teachers and classes.
- Students learn by cooperating
  and correcting each other's work (peer-to-peer learning).
- Its focus is as much on social skills as it is on technical skills.
- It's completely free to anyone that passes its selection process -
  [**The Piscine**](https://42.fr/en/admissions/42-piscine/)

It's an amazing school, and I'm grateful for the opportunity.

## 📚 Resources <a name = "resources"></a>

- https://en.wikipedia.org/wiki/BMP_file_format
- https://stackoverflow.com/questions/11004868/creating-a-bmp-file-bitmap-in-c
- https://elcharolin.wordpress.com/2018/11/28/read-and-write-bmp-files-in-c-c/
- https://engineering.purdue.edu/ece264/17au/hw/HW15

### C Compiler packing

- https://en.wikipedia.org/wiki/Data_structure_alignment
- https://stackoverflow.com/questions/3285035/when-writing-struct-to-a-file-too-many-bytes-are-written
- https://stackoverflow.com/questions/3318410/pragma-pack-effect
