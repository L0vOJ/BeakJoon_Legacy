#include <stdio.h>
int main(){
	int smp[] ={0,1,0,3,0,5,0,7,0,9,0,0,0,0,0,0,0,0,0,0,20,0,0,0,0,0,0,0,0,0,0,31,0,0,0,0,0,0,0,0,0,0,42,0,0,0,0,0,0,0,0,0,0,53,0,0,0,0,0,0,0,0,0,0,64,0,0,0,0,0,0,0,0,0,0,75,0,0,0,0,0,0,0,0,0,0,86,0,0,0,0,0,0,0,0,0,0,97,0,0,0,0,0,0,0,0,0,0,108,0,110,0,0,0,0,0,0,0,0,0,0,121,0,0,0,0,0,0,0,0,0,0,132,0,0,0,0,0,0,0,0,0,0,143,0,0,0,0,0,0,0,0,0,0,154,0,0,0,0,0,0,0,0,0,0,165,0,0,0,0,0,0,0,0,0,0,176,0,0,0,0,0,0,0,0,0,0,187,0,0,0,0,0,0,0,0,0,0,198,0,0,0,0,0,0,0,0,0,0,209,0,211,0,0,0,0,0,0,0,0,0,0,222,0,0,0,0,0,0,0,0,0,0,233,0,0,0,0,0,0,0,0,0,0,244,0,0,0,0,0,0,0,0,0,0,255,0,0,0,0,0,0,0,0,0,0,266,0,0,0,0,0,0,0,0,0,0,277,0,0,0,0,0,0,0,0,0,0,288,0,0,0,0,0,0,0,0,0,0,299,0,0,0,0,0,0,0,0,0,0,310,0,312,0,0,0,0,0,0,0,0,0,0,323,0,0,0,0,0,0,0,0,0,0,334,0,0,0,0,0,0,0,0,0,0,345,0,0,0,0,0,0,0,0,0,0,356,0,0,0,0,0,0,0,0,0,0,367,0,0,0,0,0,0,0,0,0,0,378,0,0,0,0,0,0,0,0,0,0,389,0,0,0,0,0,0,0,0,0,0,400,0,0,0,0,0,0,0,0,0,0,411,0,413,0,0,0,0,0,0,0,0,0,0,424,0,0,0,0,0,0,0,0,0,0,435,0,0,0,0,0,0,0,0,0,0,446,0,0,0,0,0,0,0,0,0,0,457,0,0,0,0,0,0,0,0,0,0,468,0,0,0,0,0,0,0,0,0,0,479,0,0,0,0,0,0,0,0,0,0,490,0,0,0,0,0,0,0,0,0,0,501,0,0,0,0,0,0,0,0,0,0,512,0,514,0,0,0,0,0,0,0,0,0,0,525,0,0,0,0,0,0,0,0,0,0,536,0,0,0,0,0,0,0,0,0,0,547,0,0,0,0,0,0,0,0,0,0,558,0,0,0,0,0,0,0,0,0,0,569,0,0,0,0,0,0,0,0,0,0,580,0,0,0,0,0,0,0,0,0,0,591,0,0,0,0,0,0,0,0,0,0,602,0,0,0,0,0,0,0,0,0,0,613,0,615,0,0,0,0,0,0,0,0,0,0,626,0,0,0,0,0,0,0,0,0,0,637,0,0,0,0,0,0,0,0,0,0,648,0,0,0,0,0,0,0,0,0,0,659,0,0,0,0,0,0,0,0,0,0,670,0,0,0,0,0,0,0,0,0,0,681,0,0,0,0,0,0,0,0,0,0,692,0,0,0,0,0,0,0,0,0,0,703,0,0,0,0,0,0,0,0,0,0,714,0,716,0,0,0,0,0,0,0,0,0,0,727,0,0,0,0,0,0,0,0,0,0,738,0,0,0,0,0,0,0,0,0,0,749,0,0,0,0,0,0,0,0,0,0,760,0,0,0,0,0,0,0,0,0,0,771,0,0,0,0,0,0,0,0,0,0,782,0,0,0,0,0,0,0,0,0,0,793,0,0,0,0,0,0,0,0,0,0,804,0,0,0,0,0,0,0,0,0,0,815,0,817,0,0,0,0,0,0,0,0,0,0,828,0,0,0,0,0,0,0,0,0,0,839,0,0,0,0,0,0,0,0,0,0,850,0,0,0,0,0,0,0,0,0,0,861,0,0,0,0,0,0,0,0,0,0,872,0,0,0,0,0,0,0,0,0,0,883,0,0,0,0,0,0,0,0,0,0,894,0,0,0,0,0,0,0,0,0,0,905,0,0,0,0,0,0,0,0,0,0,916,0,918,0,0,0,0,0,0,0,0,0,0,929,0,0,0,0,0,0,0,0,0,0,940,0,0,0,0,0,0,0,0,0,0,951,0,0,0,0,0,0,0,0,0,0,962,0,0,0,0,0,0,0,0,0,0,973,0,0,0,0,0,0,0,0,0,0,984,0,0,0,0,0,0,0,0,0,0,995,0,0,0,0,0,0,0,0,0,0,1006,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1021,0,0,0,0,0,0,0,0,0,0,1032,0,0,0,0,0,0,0,0,0,0,1043,0,0,0,0,0,0,0,0,0,0,1054,0,0,0,0,0,0,0,0,0,0,1065,0,0,0,0,0,0,0,0,0,0,1076,0,0,0,0,0,0,0,0,0,0,1087,0,0,0,0,0,0,0,0,0,0,1098,0,0,0,0,0,0,0,0,0,0,1109,0,1111,0,0,0,0,0,0,0,0,0,0,1122,0,0,0,0,0,0,0,0,0,0,1133,0,0,0,0,0,0,0,0,0,0,1144,0,0,0,0,0,0,0,0,0,0,1155,0,0,0,0,0,0,0,0,0,0,1166,0,0,0,0,0,0,0,0,0,0,1177,0,0,0,0,0,0,0,0,0,0,1188,0,0,0,0,0,0,0,0,0,0,1199,0,0,0,0,0,0,0,0,0,0,1210,0,1212,0,0,0,0,0,0,0,0,0,0,1223,0,0,0,0,0,0,0,0,0,0,1234,0,0,0,0,0,0,0,0,0,0,1245,0,0,0,0,0,0,0,0,0,0,1256,0,0,0,0,0,0,0,0,0,0,1267,0,0,0,0,0,0,0,0,0,0,1278,0,0,0,0,0,0,0,0,0,0,1289,0,0,0,0,0,0,0,0,0,0,1300,0,0,0,0,0,0,0,0,0,0,1311,0,1313,0,0,0,0,0,0,0,0,0,0,1324,0,0,0,0,0,0,0,0,0,0,1335,0,0,0,0,0,0,0,0,0,0,1346,0,0,0,0,0,0,0,0,0,0,1357,0,0,0,0,0,0,0,0,0,0,1368,0,0,0,0,0,0,0,0,0,0,1379,0,0,0,0,0,0,0,0,0,0,1390,0,0,0,0,0,0,0,0,0,0,1401,0,0,0,0,0,0,0,0,0,0,1412,0,1414,0,0,0,0,0,0,0,0,0,0,1425,0,0,0,0,0,0,0,0,0,0,1436,0,0,0,0,0,0,0,0,0,0,1447,0,0,0,0,0,0,0,0,0,0,1458,0,0,0,0,0,0,0,0,0,0,1469,0,0,0,0,0,0,0,0,0,0,1480,0,0,0,0,0,0,0,0,0,0,1491,0,0,0,0,0,0,0,0,0,0,1502,0,0,0,0,0,0,0,0,0,0,1513,0,1515,0,0,0,0,0,0,0,0,0,0,1526,0,0,0,0,0,0,0,0,0,0,1537,0,0,0,0,0,0,0,0,0,0,1548,0,0,0,0,0,0,0,0,0,0,1559,0,0,0,0,0,0,0,0,0,0,1570,0,0,0,0,0,0,0,0,0,0,1581,0,0,0,0,0,0,0,0,0,0,1592,0,0,0,0,0,0,0,0,0,0,1603,0,0,0,0,0,0,0,0,0,0,1614,0,1616,0,0,0,0,0,0,0,0,0,0,1627,0,0,0,0,0,0,0,0,0,0,1638,0,0,0,0,0,0,0,0,0,0,1649,0,0,0,0,0,0,0,0,0,0,1660,0,0,0,0,0,0,0,0,0,0,1671,0,0,0,0,0,0,0,0,0,0,1682,0,0,0,0,0,0,0,0,0,0,1693,0,0,0,0,0,0,0,0,0,0,1704,0,0,0,0,0,0,0,0,0,0,1715,0,1717,0,0,0,0,0,0,0,0,0,0,1728,0,0,0,0,0,0,0,0,0,0,1739,0,0,0,0,0,0,0,0,0,0,1750,0,0,0,0,0,0,0,0,0,0,1761,0,0,0,0,0,0,0,0,0,0,1772,0,0,0,0,0,0,0,0,0,0,1783,0,0,0,0,0,0,0,0,0,0,1794,0,0,0,0,0,0,0,0,0,0,1805,0,0,0,0,0,0,0,0,0,0,1816,0,1818,0,0,0,0,0,0,0,0,0,0,1829,0,0,0,0,0,0,0,0,0,0,1840,0,0,0,0,0,0,0,0,0,0,1851,0,0,0,0,0,0,0,0,0,0,1862,0,0,0,0,0,0,0,0,0,0,1873,0,0,0,0,0,0,0,0,0,0,1884,0,0,0,0,0,0,0,0,0,0,1895,0,0,0,0,0,0,0,0,0,0,1906,0,0,0,0,0,0,0,0,0,0,1917,0,1919,0,0,0,0,0,0,0,0,0,0,1930,0,0,0,0,0,0,0,0,0,0,1941,0,0,0,0,0,0,0,0,0,0,1952,0,0,0,0,0,0,0,0,0,0,1963,0,0,0,0,0,0,0,0,0,0,1974,0,0,0,0,0,0,0,0,0,0,1985,0,0,0,0,0,0,0,0,0,0,1996,0,0,0,0,0,0,0,0,0,0,2007,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2022,0,0,0,0,0,0,0,0,0,0,2033,0,0,0,0,0,0,0,0,0,0,2044,0,0,0,0,0,0,0,0,0,0,2055,0,0,0,0,0,0,0,0,0,0,2066,0,0,0,0,0,0,0,0,0,0,2077,0,0,0,0,0,0,0,0,0,0,2088,0,0,0,0,0,0,0,0,0,0,2099,0,0,0,0,0,0,0,0,0,0,2110,0,2112,0,0,0,0,0,0,0,0,0,0,2123,0,0,0,0,0,0,0,0,0,0,2134,0,0,0,0,0,0,0,0,0,0,2145,0,0,0,0,0,0,0,0,0,0,2156,0,0,0,0,0,0,0,0,0,0,2167,0,0,0,0,0,0,0,0,0,0,2178,0,0,0,0,0,0,0,0,0,0,2189,0,0,0,0,0,0,0,0,0,0,2200,0,0,0,0,0,0,0,0,0,0,2211,0,2213,0,0,0,0,0,0,0,0,0,0,2224,0,0,0,0,0,0,0,0,0,0,2235,0,0,0,0,0,0,0,0,0,0,2246,0,0,0,0,0,0,0,0,0,0,2257,0,0,0,0,0,0,0,0,0,0,2268,0,0,0,0,0,0,0,0,0,0,2279,0,0,0,0,0,0,0,0,0,0,2290,0,0,0,0,0,0,0,0,0,0,2301,0,0,0,0,0,0,0,0,0,0,2312,0,2314,0,0,0,0,0,0,0,0,0,0,2325,0,0,0,0,0,0,0,0,0,0,2336,0,0,0,0,0,0,0,0,0,0,2347,0,0,0,0,0,0,0,0,0,0,2358,0,0,0,0,0,0,0,0,0,0,2369,0,0,0,0,0,0,0,0,0,0,2380,0,0,0,0,0,0,0,0,0,0,2391,0,0,0,0,0,0,0,0,0,0,2402,0,0,0,0,0,0,0,0,0,0,2413,0,2415,0,0,0,0,0,0,0,0,0,0,2426,0,0,0,0,0,0,0,0,0,0,2437,0,0,0,0,0,0,0,0,0,0,2448,0,0,0,0,0,0,0,0,0,0,2459,0,0,0,0,0,0,0,0,0,0,2470,0,0,0,0,0,0,0,0,0,0,2481,0,0,0,0,0,0,0,0,0,0,2492,0,0,0,0,0,0,0,0,0,0,2503,0,0,0,0,0,0,0,0,0,0,2514,0,2516,0,0,0,0,0,0,0,0,0,0,2527,0,0,0,0,0,0,0,0,0,0,2538,0,0,0,0,0,0,0,0,0,0,2549,0,0,0,0,0,0,0,0,0,0,2560,0,0,0,0,0,0,0,0,0,0,2571,0,0,0,0,0,0,0,0,0,0,2582,0,0,0,0,0,0,0,0,0,0,2593,0,0,0,0,0,0,0,0,0,0,2604,0,0,0,0,0,0,0,0,0,0,2615,0,2617,0,0,0,0,0,0,0,0,0,0,2628,0,0,0,0,0,0,0,0,0,0,2639,0,0,0,0,0,0,0,0,0,0,2650,0,0,0,0,0,0,0,0,0,0,2661,0,0,0,0,0,0,0,0,0,0,2672,0,0,0,0,0,0,0,0,0,0,2683,0,0,0,0,0,0,0,0,0,0,2694,0,0,0,0,0,0,0,0,0,0,2705,0,0,0,0,0,0,0,0,0,0,2716,0,2718,0,0,0,0,0,0,0,0,0,0,2729,0,0,0,0,0,0,0,0,0,0,2740,0,0,0,0,0,0,0,0,0,0,2751,0,0,0,0,0,0,0,0,0,0,2762,0,0,0,0,0,0,0,0,0,0,2773,0,0,0,0,0,0,0,0,0,0,2784,0,0,0,0,0,0,0,0,0,0,2795,0,0,0,0,0,0,0,0,0,0,2806,0,0,0,0,0,0,0,0,0,0,2817,0,2819,0,0,0,0,0,0,0,0,0,0,2830,0,0,0,0,0,0,0,0,0,0,2841,0,0,0,0,0,0,0,0,0,0,2852,0,0,0,0,0,0,0,0,0,0,2863,0,0,0,0,0,0,0,0,0,0,2874,0,0,0,0,0,0,0,0,0,0,2885,0,0,0,0,0,0,0,0,0,0,2896,0,0,0,0,0,0,0,0,0,0,2907,0,0,0,0,0,0,0,0,0,0,2918,0,2920,0,0,0,0,0,0,0,0,0,0,2931,0,0,0,0,0,0,0,0,0,0,2942,0,0,0,0,0,0,0,0,0,0,2953,0,0,0,0,0,0,0,0,0,0,2964,0,0,0,0,0,0,0,0,0,0,2975,0,0,0,0,0,0,0,0,0,0,2986,0,0,0,0,0,0,0,0,0,0,2997,0,0,0,0,0,0,0,0,0,0,3008,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3023,0,0,0,0,0,0,0,0,0,0,3034,0,0,0,0,0,0,0,0,0,0,3045,0,0,0,0,0,0,0,0,0,0,3056,0,0,0,0,0,0,0,0,0,0,3067,0,0,0,0,0,0,0,0,0,0,3078,0,0,0,0,0,0,0,0,0,0,3089,0,0,0,0,0,0,0,0,0,0,3100,0,0,0,0,0,0,0,0,0,0,3111,0,3113,0,0,0,0,0,0,0,0,0,0,3124,0,0,0,0,0,0,0,0,0,0,3135,0,0,0,0,0,0,0,0,0,0,3146,0,0,0,0,0,0,0,0,0,0,3157,0,0,0,0,0,0,0,0,0,0,3168,0,0,0,0,0,0,0,0,0,0,3179,0,0,0,0,0,0,0,0,0,0,3190,0,0,0,0,0,0,0,0,0,0,3201,0,0,0,0,0,0,0,0,0,0,3212,0,3214,0,0,0,0,0,0,0,0,0,0,3225,0,0,0,0,0,0,0,0,0,0,3236,0,0,0,0,0,0,0,0,0,0,3247,0,0,0,0,0,0,0,0,0,0,3258,0,0,0,0,0,0,0,0,0,0,3269,0,0,0,0,0,0,0,0,0,0,3280,0,0,0,0,0,0,0,0,0,0,3291,0,0,0,0,0,0,0,0,0,0,3302,0,0,0,0,0,0,0,0,0,0,3313,0,3315,0,0,0,0,0,0,0,0,0,0,3326,0,0,0,0,0,0,0,0,0,0,3337,0,0,0,0,0,0,0,0,0,0,3348,0,0,0,0,0,0,0,0,0,0,3359,0,0,0,0,0,0,0,0,0,0,3370,0,0,0,0,0,0,0,0,0,0,3381,0,0,0,0,0,0,0,0,0,0,3392,0,0,0,0,0,0,0,0,0,0,3403,0,0,0,0,0,0,0,0,0,0,3414,0,3416,0,0,0,0,0,0,0,0,0,0,3427,0,0,0,0,0,0,0,0,0,0,3438,0,0,0,0,0,0,0,0,0,0,3449,0,0,0,0,0,0,0,0,0,0,3460,0,0,0,0,0,0,0,0,0,0,3471,0,0,0,0,0,0,0,0,0,0,3482,0,0,0,0,0,0,0,0,0,0,3493,0,0,0,0,0,0,0,0,0,0,3504,0,0,0,0,0,0,0,0,0,0,3515,0,3517,0,0,0,0,0,0,0,0,0,0,3528,0,0,0,0,0,0,0,0,0,0,3539,0,0,0,0,0,0,0,0,0,0,3550,0,0,0,0,0,0,0,0,0,0,3561,0,0,0,0,0,0,0,0,0,0,3572,0,0,0,0,0,0,0,0,0,0,3583,0,0,0,0,0,0,0,0,0,0,3594,0,0,0,0,0,0,0,0,0,0,3605,0,0,0,0,0,0,0,0,0,0,3616,0,3618,0,0,0,0,0,0,0,0,0,0,3629,0,0,0,0,0,0,0,0,0,0,3640,0,0,0,0,0,0,0,0,0,0,3651,0,0,0,0,0,0,0,0,0,0,3662,0,0,0,0,0,0,0,0,0,0,3673,0,0,0,0,0,0,0,0,0,0,3684,0,0,0,0,0,0,0,0,0,0,3695,0,0,0,0,0,0,0,0,0,0,3706,0,0,0,0,0,0,0,0,0,0,3717,0,3719,0,0,0,0,0,0,0,0,0,0,3730,0,0,0,0,0,0,0,0,0,0,3741,0,0,0,0,0,0,0,0,0,0,3752,0,0,0,0,0,0,0,0,0,0,3763,0,0,0,0,0,0,0,0,0,0,3774,0,0,0,0,0,0,0,0,0,0,3785,0,0,0,0,0,0,0,0,0,0,3796,0,0,0,0,0,0,0,0,0,0,3807,0,0,0,0,0,0,0,0,0,0,3818,0,3820,0,0,0,0,0,0,0,0,0,0,3831,0,0,0,0,0,0,0,0,0,0,3842,0,0,0,0,0,0,0,0,0,0,3853,0,0,0,0,0,0,0,0,0,0,3864,0,0,0,0,0,0,0,0,0,0,3875,0,0,0,0,0,0,0,0,0,0,3886,0,0,0,0,0,0,0,0,0,0,3897,0,0,0,0,0,0,0,0,0,0,3908,0,0,0,0,0,0,0,0,0,0,3919,0,3921,0,0,0,0,0,0,0,0,0,0,3932,0,0,0,0,0,0,0,0,0,0,3943,0,0,0,0,0,0,0,0,0,0,3954,0,0,0,0,0,0,0,0,0,0,3965,0,0,0,0,0,0,0,0,0,0,3976,0,0,0,0,0,0,0,0,0,0,3987,0,0,0,0,0,0,0,0,0,0,3998,0,0,0,0,0,0,0,0,0,0,4009,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4024,0,0,0,0,0,0,0,0,0,0,4035,0,0,0,0,0,0,0,0,0,0,4046,0,0,0,0,0,0,0,0,0,0,4057,0,0,0,0,0,0,0,0,0,0,4068,0,0,0,0,0,0,0,0,0,0,4079,0,0,0,0,0,0,0,0,0,0,4090,0,0,0,0,0,0,0,0,0,0,4101,0,0,0,0,0,0,0,0,0,0,4112,0,4114,0,0,0,0,0,0,0,0,0,0,4125,0,0,0,0,0,0,0,0,0,0,4136,0,0,0,0,0,0,0,0,0,0,4147,0,0,0,0,0,0,0,0,0,0,4158,0,0,0,0,0,0,0,0,0,0,4169,0,0,0,0,0,0,0,0,0,0,4180,0,0,0,0,0,0,0,0,0,0,4191,0,0,0,0,0,0,0,0,0,0,4202,0,0,0,0,0,0,0,0,0,0,4213,0,4215,0,0,0,0,0,0,0,0,0,0,4226,0,0,0,0,0,0,0,0,0,0,4237,0,0,0,0,0,0,0,0,0,0,4248,0,0,0,0,0,0,0,0,0,0,4259,0,0,0,0,0,0,0,0,0,0,4270,0,0,0,0,0,0,0,0,0,0,4281,0,0,0,0,0,0,0,0,0,0,4292,0,0,0,0,0,0,0,0,0,0,4303,0,0,0,0,0,0,0,0,0,0,4314,0,4316,0,0,0,0,0,0,0,0,0,0,4327,0,0,0,0,0,0,0,0,0,0,4338,0,0,0,0,0,0,0,0,0,0,4349,0,0,0,0,0,0,0,0,0,0,4360,0,0,0,0,0,0,0,0,0,0,4371,0,0,0,0,0,0,0,0,0,0,4382,0,0,0,0,0,0,0,0,0,0,4393,0,0,0,0,0,0,0,0,0,0,4404,0,0,0,0,0,0,0,0,0,0,4415,0,4417,0,0,0,0,0,0,0,0,0,0,4428,0,0,0,0,0,0,0,0,0,0,4439,0,0,0,0,0,0,0,0,0,0,4450,0,0,0,0,0,0,0,0,0,0,4461,0,0,0,0,0,0,0,0,0,0,4472,0,0,0,0,0,0,0,0,0,0,4483,0,0,0,0,0,0,0,0,0,0,4494,0,0,0,0,0,0,0,0,0,0,4505,0,0,0,0,0,0,0,0,0,0,4516,0,4518,0,0,0,0,0,0,0,0,0,0,4529,0,0,0,0,0,0,0,0,0,0,4540,0,0,0,0,0,0,0,0,0,0,4551,0,0,0,0,0,0,0,0,0,0,4562,0,0,0,0,0,0,0,0,0,0,4573,0,0,0,0,0,0,0,0,0,0,4584,0,0,0,0,0,0,0,0,0,0,4595,0,0,0,0,0,0,0,0,0,0,4606,0,0,0,0,0,0,0,0,0,0,4617,0,4619,0,0,0,0,0,0,0,0,0,0,4630,0,0,0,0,0,0,0,0,0,0,4641,0,0,0,0,0,0,0,0,0,0,4652,0,0,0,0,0,0,0,0,0,0,4663,0,0,0,0,0,0,0,0,0,0,4674,0,0,0,0,0,0,0,0,0,0,4685,0,0,0,0,0,0,0,0,0,0,4696,0,0,0,0,0,0,0,0,0,0,4707,0,0,0,0,0,0,0,0,0,0,4718,0,4720,0,0,0,0,0,0,0,0,0,0,4731,0,0,0,0,0,0,0,0,0,0,4742,0,0,0,0,0,0,0,0,0,0,4753,0,0,0,0,0,0,0,0,0,0,4764,0,0,0,0,0,0,0,0,0,0,4775,0,0,0,0,0,0,0,0,0,0,4786,0,0,0,0,0,0,0,0,0,0,4797,0,0,0,0,0,0,0,0,0,0,4808,0,0,0,0,0,0,0,0,0,0,4819,0,4821,0,0,0,0,0,0,0,0,0,0,4832,0,0,0,0,0,0,0,0,0,0,4843,0,0,0,0,0,0,0,0,0,0,4854,0,0,0,0,0,0,0,0,0,0,4865,0,0,0,0,0,0,0,0,0,0,4876,0,0,0,0,0,0,0,0,0,0,4887,0,0,0,0,0,0,0,0,0,0,4898,0,0,0,0,0,0,0,0,0,0,4909,0,0,0,0,0,0,0,0,0,0,4920,0,4922,0,0,0,0,0,0,0,0,0,0,4933,0,0,0,0,0,0,0,0,0,0,4944,0,0,0,0,0,0,0,0,0,0,4955,0,0,0,0,0,0,0,0,0,0,4966,0,0,0,0,0,0,0,0,0,0,4977,0,0,0,0,0,0,0,0,0,0,4988,0,0,0,0,0,0,0,0,0,0,4999,0,0,0,0,0,0,0,0,0,0,5010,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5025,0,0,0,0,0,0,0,0,0,0,5036,0,0,0,0,0,0,0,0,0,0,5047,0,0,0,0,0,0,0,0,0,0,5058,0,0,0,0,0,0,0,0,0,0,5069,0,0,0,0,0,0,0,0,0,0,5080,0,0,0,0,0,0,0,0,0,0,5091,0,0,0,0,0,0,0,0,0,0,5102,0,0,0,0,0,0,0,0,0,0,5113,0,5115,0,0,0,0,0,0,0,0,0,0,5126,0,0,0,0,0,0,0,0,0,0,5137,0,0,0,0,0,0,0,0,0,0,5148,0,0,0,0,0,0,0,0,0,0,5159,0,0,0,0,0,0,0,0,0,0,5170,0,0,0,0,0,0,0,0,0,0,5181,0,0,0,0,0,0,0,0,0,0,5192,0,0,0,0,0,0,0,0,0,0,5203,0,0,0,0,0,0,0,0,0,0,5214,0,5216,0,0,0,0,0,0,0,0,0,0,5227,0,0,0,0,0,0,0,0,0,0,5238,0,0,0,0,0,0,0,0,0,0,5249,0,0,0,0,0,0,0,0,0,0,5260,0,0,0,0,0,0,0,0,0,0,5271,0,0,0,0,0,0,0,0,0,0,5282,0,0,0,0,0,0,0,0,0,0,5293,0,0,0,0,0,0,0,0,0,0,5304,0,0,0,0,0,0,0,0,0,0,5315,0,5317,0,0,0,0,0,0,0,0,0,0,5328,0,0,0,0,0,0,0,0,0,0,5339,0,0,0,0,0,0,0,0,0,0,5350,0,0,0,0,0,0,0,0,0,0,5361,0,0,0,0,0,0,0,0,0,0,5372,0,0,0,0,0,0,0,0,0,0,5383,0,0,0,0,0,0,0,0,0,0,5394,0,0,0,0,0,0,0,0,0,0,5405,0,0,0,0,0,0,0,0,0,0,5416,0,5418,0,0,0,0,0,0,0,0,0,0,5429,0,0,0,0,0,0,0,0,0,0,5440,0,0,0,0,0,0,0,0,0,0,5451,0,0,0,0,0,0,0,0,0,0,5462,0,0,0,0,0,0,0,0,0,0,5473,0,0,0,0,0,0,0,0,0,0,5484,0,0,0,0,0,0,0,0,0,0,5495,0,0,0,0,0,0,0,0,0,0,5506,0,0,0,0,0,0,0,0,0,0,5517,0,5519,0,0,0,0,0,0,0,0,0,0,5530,0,0,0,0,0,0,0,0,0,0,5541,0,0,0,0,0,0,0,0,0,0,5552,0,0,0,0,0,0,0,0,0,0,5563,0,0,0,0,0,0,0,0,0,0,5574,0,0,0,0,0,0,0,0,0,0,5585,0,0,0,0,0,0,0,0,0,0,5596,0,0,0,0,0,0,0,0,0,0,5607,0,0,0,0,0,0,0,0,0,0,5618,0,5620,0,0,0,0,0,0,0,0,0,0,5631,0,0,0,0,0,0,0,0,0,0,5642,0,0,0,0,0,0,0,0,0,0,5653,0,0,0,0,0,0,0,0,0,0,5664,0,0,0,0,0,0,0,0,0,0,5675,0,0,0,0,0,0,0,0,0,0,5686,0,0,0,0,0,0,0,0,0,0,5697,0,0,0,0,0,0,0,0,0,0,5708,0,0,0,0,0,0,0,0,0,0,5719,0,5721,0,0,0,0,0,0,0,0,0,0,5732,0,0,0,0,0,0,0,0,0,0,5743,0,0,0,0,0,0,0,0,0,0,5754,0,0,0,0,0,0,0,0,0,0,5765,0,0,0,0,0,0,0,0,0,0,5776,0,0,0,0,0,0,0,0,0,0,5787,0,0,0,0,0,0,0,0,0,0,5798,0,0,0,0,0,0,0,0,0,0,5809,0,0,0,0,0,0,0,0,0,0,5820,0,5822,0,0,0,0,0,0,0,0,0,0,5833,0,0,0,0,0,0,0,0,0,0,5844,0,0,0,0,0,0,0,0,0,0,5855,0,0,0,0,0,0,0,0,0,0,5866,0,0,0,0,0,0,0,0,0,0,5877,0,0,0,0,0,0,0,0,0,0,5888,0,0,0,0,0,0,0,0,0,0,5899,0,0,0,0,0,0,0,0,0,0,5910,0,0,0,0,0,0,0,0,0,0,5921,0,5923,0,0,0,0,0,0,0,0,0,0,5934,0,0,0,0,0,0,0,0,0,0,5945,0,0,0,0,0,0,0,0,0,0,5956,0,0,0,0,0,0,0,0,0,0,5967,0,0,0,0,0,0,0,0,0,0,5978,0,0,0,0,0,0,0,0,0,0,5989,0,0,0,0,0,0,0,0,0,0,6000,0,0,0,0,0,0,0,0,0,0,6011,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6026,0,0,0,0,0,0,0,0,0,0,6037,0,0,0,0,0,0,0,0,0,0,6048,0,0,0,0,0,0,0,0,0,0,6059,0,0,0,0,0,0,0,0,0,0,6070,0,0,0,0,0,0,0,0,0,0,6081,0,0,0,0,0,0,0,0,0,0,6092,0,0,0,0,0,0,0,0,0,0,6103,0,0,0,0,0,0,0,0,0,0,6114,0,6116,0,0,0,0,0,0,0,0,0,0,6127,0,0,0,0,0,0,0,0,0,0,6138,0,0,0,0,0,0,0,0,0,0,6149,0,0,0,0,0,0,0,0,0,0,6160,0,0,0,0,0,0,0,0,0,0,6171,0,0,0,0,0,0,0,0,0,0,6182,0,0,0,0,0,0,0,0,0,0,6193,0,0,0,0,0,0,0,0,0,0,6204,0,0,0,0,0,0,0,0,0,0,6215,0,6217,0,0,0,0,0,0,0,0,0,0,6228,0,0,0,0,0,0,0,0,0,0,6239,0,0,0,0,0,0,0,0,0,0,6250,0,0,0,0,0,0,0,0,0,0,6261,0,0,0,0,0,0,0,0,0,0,6272,0,0,0,0,0,0,0,0,0,0,6283,0,0,0,0,0,0,0,0,0,0,6294,0,0,0,0,0,0,0,0,0,0,6305,0,0,0,0,0,0,0,0,0,0,6316,0,6318,0,0,0,0,0,0,0,0,0,0,6329,0,0,0,0,0,0,0,0,0,0,6340,0,0,0,0,0,0,0,0,0,0,6351,0,0,0,0,0,0,0,0,0,0,6362,0,0,0,0,0,0,0,0,0,0,6373,0,0,0,0,0,0,0,0,0,0,6384,0,0,0,0,0,0,0,0,0,0,6395,0,0,0,0,0,0,0,0,0,0,6406,0,0,0,0,0,0,0,0,0,0,6417,0,6419,0,0,0,0,0,0,0,0,0,0,6430,0,0,0,0,0,0,0,0,0,0,6441,0,0,0,0,0,0,0,0,0,0,6452,0,0,0,0,0,0,0,0,0,0,6463,0,0,0,0,0,0,0,0,0,0,6474,0,0,0,0,0,0,0,0,0,0,6485,0,0,0,0,0,0,0,0,0,0,6496,0,0,0,0,0,0,0,0,0,0,6507,0,0,0,0,0,0,0,0,0,0,6518,0,6520,0,0,0,0,0,0,0,0,0,0,6531,0,0,0,0,0,0,0,0,0,0,6542,0,0,0,0,0,0,0,0,0,0,6553,0,0,0,0,0,0,0,0,0,0,6564,0,0,0,0,0,0,0,0,0,0,6575,0,0,0,0,0,0,0,0,0,0,6586,0,0,0,0,0,0,0,0,0,0,6597,0,0,0,0,0,0,0,0,0,0,6608,0,0,0,0,0,0,0,0,0,0,6619,0,6621,0,0,0,0,0,0,0,0,0,0,6632,0,0,0,0,0,0,0,0,0,0,6643,0,0,0,0,0,0,0,0,0,0,6654,0,0,0,0,0,0,0,0,0,0,6665,0,0,0,0,0,0,0,0,0,0,6676,0,0,0,0,0,0,0,0,0,0,6687,0,0,0,0,0,0,0,0,0,0,6698,0,0,0,0,0,0,0,0,0,0,6709,0,0,0,0,0,0,0,0,0,0,6720,0,6722,0,0,0,0,0,0,0,0,0,0,6733,0,0,0,0,0,0,0,0,0,0,6744,0,0,0,0,0,0,0,0,0,0,6755,0,0,0,0,0,0,0,0,0,0,6766,0,0,0,0,0,0,0,0,0,0,6777,0,0,0,0,0,0,0,0,0,0,6788,0,0,0,0,0,0,0,0,0,0,6799,0,0,0,0,0,0,0,0,0,0,6810,0,0,0,0,0,0,0,0,0,0,6821,0,6823,0,0,0,0,0,0,0,0,0,0,6834,0,0,0,0,0,0,0,0,0,0,6845,0,0,0,0,0,0,0,0,0,0,6856,0,0,0,0,0,0,0,0,0,0,6867,0,0,0,0,0,0,0,0,0,0,6878,0,0,0,0,0,0,0,0,0,0,6889,0,0,0,0,0,0,0,0,0,0,6900,0,0,0,0,0,0,0,0,0,0,6911,0,0,0,0,0,0,0,0,0,0,6922,0,6924,0,0,0,0,0,0,0,0,0,0,6935,0,0,0,0,0,0,0,0,0,0,6946,0,0,0,0,0,0,0,0,0,0,6957,0,0,0,0,0,0,0,0,0,0,6968,0,0,0,0,0,0,0,0,0,0,6979,0,0,0,0,0,0,0,0,0,0,6990,0,0,0,0,0,0,0,0,0,0,7001,0,0,0,0,0,0,0,0,0,0,7012,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7027,0,0,0,0,0,0,0,0,0,0,7038,0,0,0,0,0,0,0,0,0,0,7049,0,0,0,0,0,0,0,0,0,0,7060,0,0,0,0,0,0,0,0,0,0,7071,0,0,0,0,0,0,0,0,0,0,7082,0,0,0,0,0,0,0,0,0,0,7093,0,0,0,0,0,0,0,0,0,0,7104,0,0,0,0,0,0,0,0,0,0,7115,0,7117,0,0,0,0,0,0,0,0,0,0,7128,0,0,0,0,0,0,0,0,0,0,7139,0,0,0,0,0,0,0,0,0,0,7150,0,0,0,0,0,0,0,0,0,0,7161,0,0,0,0,0,0,0,0,0,0,7172,0,0,0,0,0,0,0,0,0,0,7183,0,0,0,0,0,0,0,0,0,0,7194,0,0,0,0,0,0,0,0,0,0,7205,0,0,0,0,0,0,0,0,0,0,7216,0,7218,0,0,0,0,0,0,0,0,0,0,7229,0,0,0,0,0,0,0,0,0,0,7240,0,0,0,0,0,0,0,0,0,0,7251,0,0,0,0,0,0,0,0,0,0,7262,0,0,0,0,0,0,0,0,0,0,7273,0,0,0,0,0,0,0,0,0,0,7284,0,0,0,0,0,0,0,0,0,0,7295,0,0,0,0,0,0,0,0,0,0,7306,0,0,0,0,0,0,0,0,0,0,7317,0,7319,0,0,0,0,0,0,0,0,0,0,7330,0,0,0,0,0,0,0,0,0,0,7341,0,0,0,0,0,0,0,0,0,0,7352,0,0,0,0,0,0,0,0,0,0,7363,0,0,0,0,0,0,0,0,0,0,7374,0,0,0,0,0,0,0,0,0,0,7385,0,0,0,0,0,0,0,0,0,0,7396,0,0,0,0,0,0,0,0,0,0,7407,0,0,0,0,0,0,0,0,0,0,7418,0,7420,0,0,0,0,0,0,0,0,0,0,7431,0,0,0,0,0,0,0,0,0,0,7442,0,0,0,0,0,0,0,0,0,0,7453,0,0,0,0,0,0,0,0,0,0,7464,0,0,0,0,0,0,0,0,0,0,7475,0,0,0,0,0,0,0,0,0,0,7486,0,0,0,0,0,0,0,0,0,0,7497,0,0,0,0,0,0,0,0,0,0,7508,0,0,0,0,0,0,0,0,0,0,7519,0,7521,0,0,0,0,0,0,0,0,0,0,7532,0,0,0,0,0,0,0,0,0,0,7543,0,0,0,0,0,0,0,0,0,0,7554,0,0,0,0,0,0,0,0,0,0,7565,0,0,0,0,0,0,0,0,0,0,7576,0,0,0,0,0,0,0,0,0,0,7587,0,0,0,0,0,0,0,0,0,0,7598,0,0,0,0,0,0,0,0,0,0,7609,0,0,0,0,0,0,0,0,0,0,7620,0,7622,0,0,0,0,0,0,0,0,0,0,7633,0,0,0,0,0,0,0,0,0,0,7644,0,0,0,0,0,0,0,0,0,0,7655,0,0,0,0,0,0,0,0,0,0,7666,0,0,0,0,0,0,0,0,0,0,7677,0,0,0,0,0,0,0,0,0,0,7688,0,0,0,0,0,0,0,0,0,0,7699,0,0,0,0,0,0,0,0,0,0,7710,0,0,0,0,0,0,0,0,0,0,7721,0,7723,0,0,0,0,0,0,0,0,0,0,7734,0,0,0,0,0,0,0,0,0,0,7745,0,0,0,0,0,0,0,0,0,0,7756,0,0,0,0,0,0,0,0,0,0,7767,0,0,0,0,0,0,0,0,0,0,7778,0,0,0,0,0,0,0,0,0,0,7789,0,0,0,0,0,0,0,0,0,0,7800,0,0,0,0,0,0,0,0,0,0,7811,0,0,0,0,0,0,0,0,0,0,7822,0,7824,0,0,0,0,0,0,0,0,0,0,7835,0,0,0,0,0,0,0,0,0,0,7846,0,0,0,0,0,0,0,0,0,0,7857,0,0,0,0,0,0,0,0,0,0,7868,0,0,0,0,0,0,0,0,0,0,7879,0,0,0,0,0,0,0,0,0,0,7890,0,0,0,0,0,0,0,0,0,0,7901,0,0,0,0,0,0,0,0,0,0,7912,0,0,0,0,0,0,0,0,0,0,7923,0,7925,0,0,0,0,0,0,0,0,0,0,7936,0,0,0,0,0,0,0,0,0,0,7947,0,0,0,0,0,0,0,0,0,0,7958,0,0,0,0,0,0,0,0,0,0,7969,0,0,0,0,0,0,0,0,0,0,7980,0,0,0,0,0,0,0,0,0,0,7991,0,0,0,0,0,0,0,0,0,0,8002,0,0,0,0,0,0,0,0,0,0,8013,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8028,0,0,0,0,0,0,0,0,0,0,8039,0,0,0,0,0,0,0,0,0,0,8050,0,0,0,0,0,0,0,0,0,0,8061,0,0,0,0,0,0,0,0,0,0,8072,0,0,0,0,0,0,0,0,0,0,8083,0,0,0,0,0,0,0,0,0,0,8094,0,0,0,0,0,0,0,0,0,0,8105,0,0,0,0,0,0,0,0,0,0,8116,0,8118,0,0,0,0,0,0,0,0,0,0,8129,0,0,0,0,0,0,0,0,0,0,8140,0,0,0,0,0,0,0,0,0,0,8151,0,0,0,0,0,0,0,0,0,0,8162,0,0,0,0,0,0,0,0,0,0,8173,0,0,0,0,0,0,0,0,0,0,8184,0,0,0,0,0,0,0,0,0,0,8195,0,0,0,0,0,0,0,0,0,0,8206,0,0,0,0,0,0,0,0,0,0,8217,0,8219,0,0,0,0,0,0,0,0,0,0,8230,0,0,0,0,0,0,0,0,0,0,8241,0,0,0,0,0,0,0,0,0,0,8252,0,0,0,0,0,0,0,0,0,0,8263,0,0,0,0,0,0,0,0,0,0,8274,0,0,0,0,0,0,0,0,0,0,8285,0,0,0,0,0,0,0,0,0,0,8296,0,0,0,0,0,0,0,0,0,0,8307,0,0,0,0,0,0,0,0,0,0,8318,0,8320,0,0,0,0,0,0,0,0,0,0,8331,0,0,0,0,0,0,0,0,0,0,8342,0,0,0,0,0,0,0,0,0,0,8353,0,0,0,0,0,0,0,0,0,0,8364,0,0,0,0,0,0,0,0,0,0,8375,0,0,0,0,0,0,0,0,0,0,8386,0,0,0,0,0,0,0,0,0,0,8397,0,0,0,0,0,0,0,0,0,0,8408,0,0,0,0,0,0,0,0,0,0,8419,0,8421,0,0,0,0,0,0,0,0,0,0,8432,0,0,0,0,0,0,0,0,0,0,8443,0,0,0,0,0,0,0,0,0,0,8454,0,0,0,0,0,0,0,0,0,0,8465,0,0,0,0,0,0,0,0,0,0,8476,0,0,0,0,0,0,0,0,0,0,8487,0,0,0,0,0,0,0,0,0,0,8498,0,0,0,0,0,0,0,0,0,0,8509,0,0,0,0,0,0,0,0,0,0,8520,0,8522,0,0,0,0,0,0,0,0,0,0,8533,0,0,0,0,0,0,0,0,0,0,8544,0,0,0,0,0,0,0,0,0,0,8555,0,0,0,0,0,0,0,0,0,0,8566,0,0,0,0,0,0,0,0,0,0,8577,0,0,0,0,0,0,0,0,0,0,8588,0,0,0,0,0,0,0,0,0,0,8599,0,0,0,0,0,0,0,0,0,0,8610,0,0,0,0,0,0,0,0,0,0,8621,0,8623,0,0,0,0,0,0,0,0,0,0,8634,0,0,0,0,0,0,0,0,0,0,8645,0,0,0,0,0,0,0,0,0,0,8656,0,0,0,0,0,0,0,0,0,0,8667,0,0,0,0,0,0,0,0,0,0,8678,0,0,0,0,0,0,0,0,0,0,8689,0,0,0,0,0,0,0,0,0,0,8700,0,0,0,0,0,0,0,0,0,0,8711,0,0,0,0,0,0,0,0,0,0,8722,0,8724,0,0,0,0,0,0,0,0,0,0,8735,0,0,0,0,0,0,0,0,0,0,8746,0,0,0,0,0,0,0,0,0,0,8757,0,0,0,0,0,0,0,0,0,0,8768,0,0,0,0,0,0,0,0,0,0,8779,0,0,0,0,0,0,0,0,0,0,8790,0,0,0,0,0,0,0,0,0,0,8801,0,0,0,0,0,0,0,0,0,0,8812,0,0,0,0,0,0,0,0,0,0,8823,0,8825,0,0,0,0,0,0,0,0,0,0,8836,0,0,0,0,0,0,0,0,0,0,8847,0,0,0,0,0,0,0,0,0,0,8858,0,0,0,0,0,0,0,0,0,0,8869,0,0,0,0,0,0,0,0,0,0,8880,0,0,0,0,0,0,0,0,0,0,8891,0,0,0,0,0,0,0,0,0,0,8902,0,0,0,0,0,0,0,0,0,0,8913,0,0,0,0,0,0,0,0,0,0,8924,0,8926,0,0,0,0,0,0,0,0,0,0,8937,0,0,0,0,0,0,0,0,0,0,8948,0,0,0,0,0,0,0,0,0,0,8959,0,0,0,0,0,0,0,0,0,0,8970,0,0,0,0,0,0,0,0,0,0,8981,0,0,0,0,0,0,0,0,0,0,8992,0,0,0,0,0,0,0,0,0,0,9003,0,0,0,0,0,0,0,0,0,0,9014,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9029,0,0,0,0,0,0,0,0,0,0,9040,0,0,0,0,0,0,0,0,0,0,9051,0,0,0,0,0,0,0,0,0,0,9062,0,0,0,0,0,0,0,0,0,0,9073,0,0,0,0,0,0,0,0,0,0,9084,0,0,0,0,0,0,0,0,0,0,9095,0,0,0,0,0,0,0,0,0,0,9106,0,0,0,0,0,0,0,0,0,0,9117,0,9119,0,0,0,0,0,0,0,0,0,0,9130,0,0,0,0,0,0,0,0,0,0,9141,0,0,0,0,0,0,0,0,0,0,9152,0,0,0,0,0,0,0,0,0,0,9163,0,0,0,0,0,0,0,0,0,0,9174,0,0,0,0,0,0,0,0,0,0,9185,0,0,0,0,0,0,0,0,0,0,9196,0,0,0,0,0,0,0,0,0,0,9207,0,0,0,0,0,0,0,0,0,0,9218,0,9220,0,0,0,0,0,0,0,0,0,0,9231,0,0,0,0,0,0,0,0,0,0,9242,0,0,0,0,0,0,0,0,0,0,9253,0,0,0,0,0,0,0,0,0,0,9264,0,0,0,0,0,0,0,0,0,0,9275,0,0,0,0,0,0,0,0,0,0,9286,0,0,0,0,0,0,0,0,0,0,9297,0,0,0,0,0,0,0,0,0,0,9308,0,0,0,0,0,0,0,0,0,0,9319,0,9321,0,0,0,0,0,0,0,0,0,0,9332,0,0,0,0,0,0,0,0,0,0,9343,0,0,0,0,0,0,0,0,0,0,9354,0,0,0,0,0,0,0,0,0,0,9365,0,0,0,0,0,0,0,0,0,0,9376,0,0,0,0,0,0,0,0,0,0,9387,0,0,0,0,0,0,0,0,0,0,9398,0,0,0,0,0,0,0,0,0,0,9409,0,0,0,0,0,0,0,0,0,0,9420,0,9422,0,0,0,0,0,0,0,0,0,0,9433,0,0,0,0,0,0,0,0,0,0,9444,0,0,0,0,0,0,0,0,0,0,9455,0,0,0,0,0,0,0,0,0,0,9466,0,0,0,0,0,0,0,0,0,0,9477,0,0,0,0,0,0,0,0,0,0,9488,0,0,0,0,0,0,0,0,0,0,9499,0,0,0,0,0,0,0,0,0,0,9510,0,0,0,0,0,0,0,0,0,0,9521,0,9523,0,0,0,0,0,0,0,0,0,0,9534,0,0,0,0,0,0,0,0,0,0,9545,0,0,0,0,0,0,0,0,0,0,9556,0,0,0,0,0,0,0,0,0,0,9567,0,0,0,0,0,0,0,0,0,0,9578,0,0,0,0,0,0,0,0,0,0,9589,0,0,0,0,0,0,0,0,0,0,9600,0,0,0,0,0,0,0,0,0,0,9611,0,0,0,0,0,0,0,0,0,0,9622,0,9624,0,0,0,0,0,0,0,0,0,0,9635,0,0,0,0,0,0,0,0,0,0,9646,0,0,0,0,0,0,0,0,0,0,9657,0,0,0,0,0,0,0,0,0,0,9668,0,0,0,0,0,0,0,0,0,0,9679,0,0,0,0,0,0,0,0,0,0,9690,0,0,0,0,0,0,0,0,0,0,9701,0,0,0,0,0,0,0,0,0,0,9712,0,0,0,0,0,0,0,0,0,0,9723,0,9725,0,0,0,0,0,0,0,0,0,0,9736,0,0,0,0,0,0,0,0,0,0,9747,0,0,0,0,0,0,0,0,0,0,9758,0,0,0,0,0,0,0,0,0,0,9769,0,0,0,0,0,0,0,0,0,0,9780,0,0,0,0,0,0,0,0,0,0,9791,0,0,0,0,0,0,0,0,0,0,9802,0,0,0,0,0,0,0,0,0,0,9813,0,0,0,0,0,0,0,0,0,0,9824,0,9826,0,0,0,0,0,0,0,0,0,0,9837,0,0,0,0,0,0,0,0,0,0,9848,0,0,0,0,0,0,0,0,0,0,9859,0,0,0,0,0,0,0,0,0,0,9870,0,0,0,0,0,0,0,0,0,0,9881,0,0,0,0,0,0,0,0,0,0,9892,0,0,0,0,0,0,0,0,0,0,9903,0,0,0,0,0,0,0,0,0,0,9914,0,0,0,0,0,0,0,0,0,0,9925,0,9927,0,0,0,0,0,0,0,0,0,0,9938,0,0,0,0,0,0,0,0,0,0,9949,0,0,0,0,0,0,0,0,0,0,9960,0,0,0,0,0,0,0,0,0,0,9971,0,0,0,0,0,0,0,0,0,0,9982,0,0,0,0,0,0,0,0,0,0,9993,0,0,0,0,0,0};
	for(int a=0;a<sizeof(smp)/4;a++){
		if(smp[a]==0){
			continue;
		}
		else{
			printf("%d,",smp[a]);
		}
	}
}