First attempt:

```
2024-10-22T01:02:30+00:00
Running ./main_bm
Run on (4 X 2200 MHz CPU s)
CPU Caches:
  L1 Data 32 KiB (x2)
  L1 Instruction 32 KiB (x2)
  L2 Unified 256 KiB (x2)
  L3 Unified 56320 KiB (x1)
Load Average: 3.30, 1.20, 0.53
--------------------------------------------------------------------------
Benchmark                                Time             CPU   Iterations
--------------------------------------------------------------------------
BM_secuencial/real_time                350 ms          349 ms            2
BM_estandar/real_time                  971 ms        0.424 ms            1
BM_estandar_reduction/real_time       78.1 ms        0.198 ms            9
BM_openmp_atomic/real_time            2871 ms         2745 ms            1
BM_openmp_reduction/real_time         84.2 ms         79.6 ms            8
BM_openmp_lock_guard/real_time       21944 ms        17612 ms            1
BM_openmp_lock_unlock/real_time      22452 ms        19287 ms            1
BM_openmp_critical/real_time         39061 ms        35292 ms            1
BM_openmp_ompatomic/real_time         3160 ms         2921 ms            1
```
