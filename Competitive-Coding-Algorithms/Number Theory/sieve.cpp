
int isPrime[1000001];

void sieve()
{
    int maxN = 1000001;
    for (int i = 0; i < maxN; i++)
        isPrime[i] = 1;

    isPrime[0] = isPrime[1] = 0;

    for (int i = 2; i * i <= maxN; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= maxN; j += i)
            {
                isPrime[j] = 0;
            }
        }
    }