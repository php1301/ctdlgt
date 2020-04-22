i = 0 min = 0 
j = i + 1 = 1, a[j]<a[min](2 < 12) => min = j = 1;
j++ = 2, a[j] > a[min](3 > 2)
j++ = 3, a[j] > a[min]()
j++ = 4, a[j] < a[min](1<2) => min = j = 4
...
Hết vòng lặp j swap(a[i],a[min])
<=> '1' 2 8 5 '12' 6 4 15
i++ = 1 min= a[1]