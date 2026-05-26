// comparado con LagrangeInterpolation1 esto tarda mas (incluso siendo un solo testcase):
struct Lagrange {
    const ll MOD;
 
    // Constructor para definir el MOD específico del problema
    Lagrange(ll mod = 1e9 + 7) : MOD(mod) {}
 
    /**
     * @brief Interpolación de Lagrange en O(K) para puntos equiespaciados x = 0, 1, 2, ..., K
     * @param y Vector con los valores evaluados y[i] = f(i). Su tamaño define el grado máximo.
     * @param n El punto gigante (coordenada x) que queremos evaluar (relativo al inicio 0).
     * @return El valor de f(n) % MOD.
     */
    ll interpolate(const vector<ll>& y, ll n) const {
        int K = (int)y.size() - 1; // El grado máximo del polinomio es K
        
        // Si n ya está dentro de los puntos evaluados, devolvemos la respuesta directa
        if (n >= 0 && n <= K) {
            return (y[n] % MOD + MOD) % MOD;
        }
 
        // 1. Precomputar Factoriales
        vector<ll> fact(K + 1, 1), invFact(K + 1, 1);
        for (int i = 1; i <= K; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }
        invFact[K] = modInverse(fact[K]);
        for (int i = K - 1; i >= 0; i--) {
            invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
        }
 
        // 2. Precomputar Productos Prefijos y Sufijos de (n - j)
        vector<ll> pref(K + 1, 1), suff(K + 1, 1);
        
        ll current_val = (n % MOD + MOD) % MOD;
        pref[0] = current_val;
        for (int i = 1; i <= K; i++) {
            current_val = ((n - i) % MOD + MOD) % MOD;
            pref[i] = (pref[i - 1] * current_val) % MOD;
        }
 
        current_val = ((n - K) % MOD + MOD) % MOD;
        suff[K] = current_val;
        for (int i = K - 1; i >= 0; i--) {
            current_val = ((n - i) % MOD + MOD) % MOD;
            suff[i] = (suff[i + 1] * current_val) % MOD;
        }
 
        // 3. Calcular la sumatoria de Lagrange
        ll total_sum = 0;
        for (int i = 0; i <= K; i++) {
            // Numerador: producto de todos (n - j) excepto j = i
            ll num = 1;
            if (i > 0) num = (num * pref[i - 1]) % MOD;
            if (i < K) num = (num * suff[i + 1]) % MOD;
 
            // Denominador: i! * (K - i)! con el signo alternante
            ll den_inv = (invFact[i] * invFact[K - i]) % MOD;
 
            // Ajustar el signo alternante implícito en (-1)^(K - i)
            if ((K - i) % 2 == 1) {
                den_inv = (MOD - den_inv) % MOD;
            }
 
            // Combinar el término actual
            ll term = (y[i] % MOD + MOD) % MOD;
            term = (term * num) % MOD;
            term = (term * den_inv) % MOD;
 
            total_sum = (total_sum + term) % MOD;
        }
 
        return total_sum;
    }
 
private:
    ll power(ll base, ll exp) const {
        ll res = 1;
        base %= MOD;
        if (base < 0) base += MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }
 
    ll modInverse(ll n) const {
        return power(n, MOD - 2);
    }
}lag(1e9+7);
