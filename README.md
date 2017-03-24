# bwt-lcp-inplace

This code is an implementation of \[1, 2\], which modifies the in-place Burrows-Wheeler transform (BWT) algorithm by Crochemore et al. \[3\] to also compute the longest common prefix (LCP) array.

# Run:

To run a test type:

```sh
make compile
make run DIR=dataset INPUT=input.txt
```

# References

\[1\] Louza, F. A., & Telles, G. P.: Computing the BWT and the LCP Array in Constant Space. In Proc. IWOCA, pp 312-320, 2015, [SpringerLink](http://link.springer.com/chapter/10.1007/978-3-319-29516-9_26)

\[2\] Louza, F. A., & Gagie, T., Telles, G. P.: Burrows-Wheeler transform and LCP array construction in constant space. JDA: 42: 14-22 (2017), [Elsevier](http://www.sciencedirect.com/science/article/pii/S1570866716300508)

\[3\] Crochemore, M., Grossi, R., Karkkainen, J., Landau, G.M.: Computing the burrows–wheeler transform in place and in small space. Journal of Discrete Algorithms 32(0) (2015) 44 – 52 StringMasters 2012 & 2013 Special Issue (Volume 2).

