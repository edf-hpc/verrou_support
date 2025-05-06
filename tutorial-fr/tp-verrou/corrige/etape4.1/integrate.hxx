#include<cstdlib>
#include<algorithm>
#include<utility> 

typedef float RealType;

void FastTwoSum(const RealType&a, const RealType&b,
		RealType&c, RealType&d){
  RealType swapA(a), swapB(b);
  if(std::abs(swapB)> std::abs(swapA)){
    std::swap(swapA,swapB);
  }
  c=swapA+swapB;
  const RealType z=c-swapA;
  d=swapB-z;  
}


/** Calcule l'intégrale d'une fonction entre deux bornes avec la méthode des
    rectangles.

    @param f   la fonction à intégrer
    @param x0  borne gauche de l'intervalle d'intégration
    @param x1  borne droite
    @param n   nombre de rectangles
 */
template <typename T>
RealType integrate (const T& f, RealType a, RealType b, unsigned int n) {
  // Pas d'intégration
  const RealType dx = (b - a) / n;

  // Accumulateur
  RealType sum = 0.;
  RealType err_sum = 0.;

  // Boucle sur les rectangles d'intégration
  for (unsigned int i = 0 ; i<n ; ++i) {
    const RealType x = a + (i+(RealType)0.5) * dx;
    const RealType tmp = dx * f(x);
    RealType err;
    FastTwoSum(sum,tmp, sum, err);
    err_sum += err;
  }

  return sum+err_sum;
}
