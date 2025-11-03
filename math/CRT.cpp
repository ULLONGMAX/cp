ll gcd(ll a, ll b, ll& x, ll& y) { // extended euclidean algorithm
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  ll x1, y1;
  ll d = gcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}

ll mod_inv(ll a, ll m){ // the inverse of a modulo m
  ll x, y;
  ll g = gcd(a, m, x, y);
  if (g != 1) {
    //cout << "No solution!";
    return -1;
  }
  else {
    x = (x % m + m) % m;
    return x; // the inverse of a modulo m is x
  }
}

/*

CRT CAN SOLVE A SYSTEM OF CONGRUENCIES THAT HAS THE FOLLOWING FORM:

x = a_1 (mod m_1)
x = a_2 (mod m_2)
...
x = a_k (mod m_k)

where m_i are pairwise coprime.

THEOREM: the system of equations has ONE AND EXACTLY ONE SOLUTION modulo M=m_1*m_2*...*m_k
THEOREM: if m_i are NOT pairwise coprime, we can factor all m_i's and solve the equations with CRT.
        So for example if m_3 = 12 = 2^2 * 3.
        We do the same for all m_i.
        LEMMA: x = a_i (mod m_i) is equivalent to the set of congruencies {x = a_i (mod p1^pw1), x = a_i (mod p2^pw2) ...}.
              for example as m_3 = 2^2 * 3 so x = a_3 (mod m_3) is equivalent to the set of congruencies {x=a_3(mod 2^2), x=a_3(mod 3)}.
        We represent all equations using the Lemma.
        Then we just solve with CRT the set of congruencies taking ONLY THE HIGHEST POWERS FOR EACH PRIME NUMBER.
        THEOREM: the system of all equations (including the not max prime powers) has ONE AND EXACTLY ONE SOLUTION MOD M=LCM(m_1,...,m_k).
*/
struct Congruence {
  long long a, m;
};

long long chinese_remainder_theorem(vector<Congruence> const& congruences) {
  long long M = 1;
  for (auto const& congruence : congruences) {
    M *= congruence.m;
  }

  long long solution = 0;
  for (auto const& congruence : congruences) {
    long long a_i = congruence.a;
    long long M_i = M / congruence.m;
    long long N_i = mod_inv(M_i, congruence.m);
    solution = (solution + a_i * M_i % M * N_i) % M;
  }
  return solution;
}
