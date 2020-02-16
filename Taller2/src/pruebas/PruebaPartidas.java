package pruebas;


import logica.partida.Partida;
import logica.partida.Partidas;

import logica.valueObjects.VoPartida;

public class PruebaPartidas 
{

	public static void main(String[] args) 
	{
		Partidas listaPartidas = new Partidas();
		
		Partida p1 = new Partida(1, 500); 
		Partida p2 = new Partida(2, 250); 
		
		listaPartidas.insBack(p1);
		listaPartidas.insBack(p2);
		
		VoPartida[] arrayPartidas = listaPartidas.listarPartidas();  
		
		for(int i = 0; i < arrayPartidas.length;i++)
		{
			System.out.println("i: "+i);
			System.out.println(arrayPartidas[i].getNroPartida());
			System.out.println(arrayPartidas[i].getNroSecreto());
			System.out.println(arrayPartidas[i].getCantIntentosRealizados());
			System.out.println(arrayPartidas[i].getPuntajeObtenido());
		
		}		
		
		System.out.println("fin");

	}

}
