# EECS 334 Report

## Output: PPM

PPM means Portable Pixmap Format. The file will always starts with P3 and this means that the colors are in ASCII, then the number of columns and number of rows. Then the bottom `255` means that this is the max color. Then what follows is the RGB triplets. 

Here is a small example. This is just the first color and the metadata of the file.

```
P3
256 256
255
18 255 63
```