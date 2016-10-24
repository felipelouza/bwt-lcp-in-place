#bwt-lcp-inplace

This code is an implementation of \[1\], which modifies the in-place Burrows-Wheeler transform (BWT) algorithm by Crochemore et al. \[2\] to also compute the longest common prefix (LCP) array.

#run:

To run a test type:

```sh
make compile
make run DIR=dataset INPUT=input.txt
```

#references:

[1] Louza, F. A., & Telles, G. P.: Computing the BWT and the LCP Array in Constant Space. In Proc. IWOCA, pp 312-320, http://link.springer.com/chapter/10.1007/978-3-319-29516-9\_26  

[2] Crochemore, M., Grossi, R., Karkkainen, J., Landau, G.M.: Computing the burrows–wheeler transform in place and in small space. Journal of Discrete Algorithms 32(0) (2015) 44 – 52 StringMasters 2012 & 2013 Special Issue (Volume 2).

