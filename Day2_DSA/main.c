
                          Cost      Occurances
int a = 0, b = 0;           2
for(i=0; i<n; i++){         1      initalizing 'i'
                            2      n+1
    a = a + rand();         3      n
}
for(j=0; j<m; j++){         1       initalizing 'j'
                            2       m+1

    b = b + rand();         3       m
}


2 + 1 + 2(n+1) + 3n + 1 + 2(m+1) + 3m
5m + 5n + 8
O(n+m)

d




                         Cost   Occurances
int a = 0, b = 0;           2   1
for(i=0; i<n; i++){         1
                            2   n+1

    for(j=0; j<n; j++){     1   n
                            2   n(n+1)
        a = a + j;          2   n(n)
    }
}
for(k=0; k<n; k++){         1
                            2   n+1
    b = b + k;              2   n
}

2(1) + 1 + 2(n+1) + 1(n) + 2(n(n+1)) + 2n(n) + 1 + 2(n+1) + 2n
4n^2 + 7n + 8
O(n^2)  // TIME COMPLEXITY



                             Cost    Occurances
int a = 0;                    1      1
for(i=0; i<n; i++){           1      1
                              2      n+1

    for(j=n; j>i; j--){       1      n
                              2      n(((n+1)/2)+1)

        a = a + i + j;        3      n(n+1))/2
    }
}

1 + 1 + 2(n+1) + n + 2n(((n+1)/2)+1) + 3(n+1))/2
(2n^2 + 15n + 11) / 2
O(n^2)   // TIME COMPLEXITY




