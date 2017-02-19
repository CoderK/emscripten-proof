# emscripten-proof
A prototype that verifies the availability of emscripten.

## Getting Started

Please refer to [Getting Started](https://kripken.github.io/emscripten-site/docs/getting_started/index.html) on official website

## Trouble shooting

### Python Path Error

If you get the error below:
```
env: python2: No such file or directory
```
This is because by emscripten not finding the path of python.

It can be solved by creating a symbolic link to the actual path of Python.

```
sudo ln -sf /usr/bin/python2.7 /usr/local/bin/python2
```

### EMConfig Error

If you get the error below:

```n
Traceback (most recent call last):
  File "/Users/KimCoding/Library/emsdk_portable/emscripten/1.35.0/emcc", line 28, in <module>
    from tools import shared, jsrun, system_libs
  File "/Users/KimCoding/Library/emsdk_portable/emscripten/1.35.0/tools/shared.py", line 205, in <module>
    raise Exception('File ' + EM_CONFIG + ' passed to --em-config does not exist!')
Exception: File /Users/KimCoding/.emscripten passed to --em-config does not exist!
```
./emsdk_env.sh assumes that you have already registered a path named EM_CONFIG. 

This problem can be solved by setting the environment variable manually.

```
EM_CONFIG= emcc
```

For more information, please see the [link](https://github.com/kripken/emscripten/issues/4416).