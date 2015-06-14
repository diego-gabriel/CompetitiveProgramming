#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
  
/**
 * Autor: Diego Gabriel Nuñez Duran
 * 
 * Esta es la solucion al problema A del segundo online Bolivia de la 
 * anterior semana, la idea es simple:
 * 
 * Ordenar los puntos, de modo que con ellos podamos formar una especie
 * de graditas asi:
 *  __________________
 * |      ·    ·     _|
 * |   ·     ·______|         
 * | ·   ·___|
 * |_____|
 * 
 * Las esquinitas ( _| ) son formadas por los puntos externos,
 * los otros puntos (·) son los puntos que no nos interesan pues 
 * su area esta dentro del area mas grande.
 * 
 * Bueno, ya que los tenemos ordenados, lo que nos queda es calcular
 * el area, y lo podemos hacer por barritas (notan que se puede dividir
 * en barritas verdad?) que pueden ser tanto horizontal como vertical, 
 * sumamos sus areas y listo! ahi esta nuestra solucion. No se olviden 
 * tomar siempre los casos extremos.. como que nos manden 0 puntos, 
 * entonces nuestra respuesta es 0.
 * 
 * La complejidad en cuanto a tiempo legaria a ser casi lineal... o...
 * no, de hecho aca lo mas costoso es el ordenamiento, asi que la 
 * complejidad es O(n*log n)
 * La memoria no es problema, pues solo se necesitan 2*n enteros para
 * guardar los n puntos :D
 * 
 * Espero les guste, lo hice con mucho cariño :')
 * 
 */


/**
 * Estas estructuras son similares a las clases de Java, la diferencia
 * es que no tenemos encapsulamiento, asi que todos sus atributos y 
 * metodos son "public".
 * Como ven tambien tiene un constructor :D
 */
struct Coord
{
	int x,y;
	Coord()
	{
		cin>>x>>y;
	}
};


/**
 * Este metodo de aca nos sirve para comparar 2 Coord y asi poder hacer
 * el ordenamiento. 
 * Es como sobreescribir el metodo compareTo cuando definimos clases
 * que implementan la interfaz Comparable, solo que en C++ no se 
 * sobreescribe eso, no existen las interfaces y los structs no son 
 * clases ni objetos, son como su nombre dice "estructuras".
 * Como los ordena? bueno, mas abajito hay una linea de sort()
 * donde le mando el nombre de esta funcion como parametro, entonces 
 * el programa utiliza esta funcion para ordenar.
 */
bool ordCoord(Coord a, Coord b)
{
	bool res;
	if (a.x == b.x)
	{
		res = a.y < b.y;
	} else res =  a.x < b.x;
	
	return res;
}

int main()
{
	int test;
	cin>>test;
	
	while (test--)
	{
		int n;
		cin>>n;
		
		//Aqui los vector son como los ArrayList de Java, solo que
		//tambien son structs, no Objetos (creo), asi que no se 
		//construyen con "new" 
		vector <Coord> points;
		
		for (int i = 0; i < n; i++){
			//Coord()... asi se construye una nueva estructura Coord :D
			points.push_back(Coord());
		}
		
		sort(points.begin(), points.end(), ordCoord); // <- AQUI el SORT
		
		int res = 0;
		if (!points.empty()) // aqui el cuidado de q nos manden 0
		{
			// y aqui la magia :D
			Coord last = points.at(n-1);
			Coord it;
			res += last.x * last.y;
			for (int i = n-2; i >= 0; i--)
			{
				it = points.at(i);
				if (it.y > last.y)
				{
					res += (it.y - last.y) * it.x;
					last = it;
				}
			}
		}
		cout<<res<<endl;
	}
	
	return 0;
}
