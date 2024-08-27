inline void radixsort(int *a, int n) {
    static int cnt[32768], t[200000];
    for (int i=0; i<32768; i++) cnt[i] = 0;
    for (int i=0; i<n; i++) cnt[a[i]&32767]++;
    for (int i=1; i<32768; i++) cnt[i] += cnt[i-1];
    for (int i=n-1; i>=0; i--) t[--cnt[a[i]&32767]] = a[i];
    for (int i=0; i<32768; i++) cnt[i] = 0;
    for (int i=0; i<n; i++) cnt[t[i]>>15]++;
    for (int i=1; i<32768; i++) cnt[i] += cnt[i-1];
    for (int i=n-1; i>=0; i--) a[--cnt[t[i]>>15]] = t[i];
}