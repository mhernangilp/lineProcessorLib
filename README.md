<h1 align="center">
	📄 lineProcessorLib
</h1>

<p align="center">
	<b><i>Head, Tail and Longlines</i></b><br>
</p>

<h3 align="center">
	<a href="#%EF%B8%8F-about">About</a>
	<span> · </span>
	<a href="#%EF%B8%8F-usage">Usage</a>
	<span> · </span>
	<a href="#-testing">Testing</a>
</h3>

---

## 💡 About the project

> _In this project will have to simulate the Head and Tail commands from the Unix terminal. You
will also need to do Longlines, which gets the n bigger lines from the input._


For more detailed information, look at the [**subject of this project**](https://github.com/mhernangilp/lineProcessorLib/blob/main/es.subject.lineProcessor.pdf).


## 🛠️ Usage

### Requirements

The function is written in C language and thus needs the **`gcc` compiler** and some standard **C libraries** to run.

### Instructions

**1. Compiling**

To compile, go to the project path and run:

```shell
$ ./compila
```


## 📋 Testing

To test the program you need to use this format:

```shell
$ ./test -<function> [number of lines]
```
Here are some examples:

```shell
$ ./test -head 5
```

```shell
$ ./test -tail
```

```shell
$ ./test -longlines 7
```
