int getCombi(int n, int k) 
{
   if (combi[n][k] != 0) return combi[n][k];
   if (k == 0 || k == n) return combi[n][k] = 1;
   if (k > n - k) return combi[n][k] = getCombi(n, n - k);
   return combi[n][k] = getCombi(n - 1, k) + getCombi(n - 1, k - 1);
}
