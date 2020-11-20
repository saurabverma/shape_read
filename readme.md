# Shapelib example

This is a simple shapelib example, as I couldn't find a ready-to-use example online.

Shapefile details can be found [here](https://en.wikipedia.org/wiki/Shapefile).
Some parts of the code are exerpt from various locations online.
Apologies if your work is not referenced here, kindly send me your link likewise.

## C

Run this code as follows
```
g++ -std=c++11 main.cpp -I/usr/local/include -lshp -g -o executable && ./executable
```
NOTE: the shapelib was installed via [latest source code](https://github.com/OSGeo/shapelib) (v1.5).

## Python

Run this code as follows
```
python read.py
```
NOTE: require installation of [`shapefile`](https://pypi.org/project/pyshp/) (and [`matplotlib`](https://pypi.org/project/matplotlib/) for viewing), via `pip`.
