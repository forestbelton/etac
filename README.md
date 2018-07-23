etac
====

Dependencies
------------

These C libraries need to be present for linking:

* `termbox`
* `lua`

Build
-----

```bash
$ make clean && make
```

Usage
-----

```bash
$ ./etac
```

Docker build
------------

```bash
$ docker build -t etac .
$ docker run -it etac /bin/sh
# ./etac
```

**NOTE:** `docker run -it etac` does not yet work. For more information, please see issue [#1](https://github.com/forestbelton/etac/issues/1).
